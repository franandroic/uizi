#include "player.h"

Player::Player(int i, std::string n, Cursor *c) {

    id = i;
    name = n;
    cursor = c;

    input = '0';
    signalToQuit = false;

    //TODO hard-coded starting units, change it
    if (i % 2 == 0) {
        units.push_back(Unit(1, id, 0, 0));
        units.push_back(Unit(2, id, 0, 1));
        units.push_back(Unit(3, id, 0, 2));
    } else {
        units.push_back(Unit(1, id, 7, 5));
        units.push_back(Unit(2, id, 7, 6));
        units.push_back(Unit(3, id, 7, 7));
    }
    
    activeUnitIdx = 0;
}

bool Player::handleInput() {

    for (int uIdx = 0; uIdx < units.size(); uIdx++) {

        activeUnitIdx = uIdx;
        cursor->moveTo(units[activeUnitIdx].getX(), units[activeUnitIdx].getY());

        for (int a = 0; a < 2; a++) {
            do {
                std::cout << name << std::endl;
                std::cout << "Unit " << units[activeUnitIdx].getId() << std::endl;
                if (a == 0) std::cout << "Move" << std::endl;
                else std::cout << "Attack" << std::endl;
                notifyListeners();
            } while (!handleUnitAction(a));

            if (signalToQuit) return false;
        }
    }

    return true;
}

bool Player::handleUnitAction(int action) {

    input = getchar();  

    if (input == '\033') {

        getchar();
        switch (getchar()) {
            case 'A': {
                cursor->move(true, -1);
                break;
            }
            case 'B': {
                cursor->move(true, 1);
                break;
            }
            case 'C': {
                cursor->move(false, 1);
                break;
            }
            case 'D': {
                cursor->move(false, -1);
                break;
            }
            default:
                break;
        }
        
    } else {

        switch (input) {
            case '\n': {
                if (action == 0) {
                    if (manhattanDistance() > 2) return false;
                    if (!units[activeUnitIdx].moveTo(cursor->getX(), cursor->getY())) return false;
                } else {
                    if (manhattanDistance() > 1) return false;
                    if (!notifyCombatListener()) return false;
                }
                return true;
            }
            case ' ': {
                if (action == 0) {
                    cursor->moveTo(units[activeUnitIdx].getX(), units[activeUnitIdx].getY());
                } else {
                    return true;
                }              
                return false;
            }
            case 'q': {
                signalToQuit = true;
                return true;   
            }
            default:
                break;
        }

    }

    return false;
}

std::string Player::getName() {
    return name;
}

Cursor *Player::getCursor() {
    return cursor;
}

std::vector<Unit> *Player::getUnits() {
    return &units;
}

Unit *Player::getUnit(int idx) {
    if (idx >= units.size()) return nullptr;
    return &units[idx];
}

int Player::getActiveUnitIdx() {
    return activeUnitIdx;
}

int Player::getNumberOfUnits() {
    return units.size();
}

bool Player::getSignalToQuit() {
    return signalToQuit;
}

int Player::getId() {
    return id;
}

void Player::subscribePlayerListener(PlayerObserver *po) {
    listeners.push_back(po);
}

void Player::subscribeCombatListener(CombatObserver *co) {
    combatListener = co;
}

void Player::notifyListeners() {
    for (int i = 0; i < listeners.size(); i++) {
        listeners[i]->updatePlayerListener();
    }
}

bool Player::notifyCombatListener() {
    return combatListener->updateCombatListener(this, cursor->getX(), cursor->getY());
}

void Player::damageUnit(int unitIdx, int damage) {
    if (units[unitIdx].takeDamage(damage)) units.erase(units.begin() + unitIdx);
}

int Player::manhattanDistance() {
    return std::abs(cursor->getX() - units[activeUnitIdx].getX()) + std::abs(cursor->getY() - units[activeUnitIdx].getY());
}