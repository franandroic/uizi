#include "unit.h"

Unit::Unit(int startX, int startY) {

    x = startX;
    y = startY;
}

void Unit::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Unit::moveTo(int nx, int ny) {
    x = nx;
    y = ny;
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