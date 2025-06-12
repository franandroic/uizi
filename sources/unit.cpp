#include "unit.h"

Unit::Unit(int startUnitId, int startOwnerId, int startX, int startY) {

    unitId = startUnitId;
    ownerId = startOwnerId;
    x = startX;
    y = startY;

    health = 3;     //hardcoded health

    icon.embedId(unitId, ownerId);
}

Unit::~Unit() {
    notifyListeners(-1, -1);
}

void Unit::move(int dx, int dy) {
    x += dx;
    y += dy;
}

bool Unit::moveTo(int nx, int ny) {
    if (notifyListeners(nx, ny)) {
        x = nx;
        y = ny;
        return true;
    }
    return false;
}

int Unit::getId() {
    return unitId;
}

Icon *Unit::getIcon() {
    return &icon;
}

int Unit::getX() {
    return x;
}

int Unit::getY() {
    return y;
}

void Unit::subscribeUnitListener(UnitObserver *uo) {
    listeners.push_back(uo);
}

bool Unit::takeDamage(int damage) {
    health--;
    if (health == 0) return true;
    return false;
}

bool Unit::notifyListeners(int newX, int newY) {

    bool canMove = false;

    for (int i = 0; i < listeners.size(); i++) {
        canMove = canMove || listeners[i]->updateUnitListener(ownerId, x, y, newX, newY);
    }

    return canMove;
}