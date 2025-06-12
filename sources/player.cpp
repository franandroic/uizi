#include "player.h"

Player::Player(std::string n, Cursor *c) {

    name = n;
    cursor = c;
    input = '0';
    signalToQuit = false;

    //TODO hard-coded starting units, change it
    units.push_back(Unit(0, 0));
    units.push_back(Unit(0, 1));
    units.push_back(Unit(0, 2));
    activeUnitIdx = 0;
}

bool Player::handleInput() {

    for (int uIdx = 0; uIdx < units.size(); uIdx++) {

        activeUnitIdx = uIdx;
        cursor->moveTo(units[activeUnitIdx].getX(), units[activeUnitIdx].getY());

        do {
            std::cout << name << std::endl;
            notifyListeners();
        } while (!handleUnitMovement());

        if (signalToQuit) return false;
    }

    return true;
}

bool Player::handleUnitMovement() {

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
                units[activeUnitIdx].moveTo(cursor->getX(), cursor->getY());
                return true;
            }
            case ' ': {
                cursor->moveTo(units[activeUnitIdx].getX(), units[activeUnitIdx].getY());
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

void Player::subscribePlayerListener(PlayerObserver *po) {
    listeners.push_back(po);
}

void Player::notifyListeners() {
    for (int i = 0; i < listeners.size(); i++) {
        listeners[i]->updatePlayerListener();
    }
}