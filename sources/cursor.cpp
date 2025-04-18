#include "cursor.h"

Cursor::Cursor(int mx, int my) {

    x = 0;
    y = 0;

    maxX = mx;
    maxY = my;
}

void Cursor::move(bool direction, int distance) {

    if (distance != 1 && distance != -1) return;

    if (direction) {

        if ((distance > 0 && x >= maxX - 1) ||
            (distance < 0 && x <= 0)) {
            return;
        }

        x += distance;
        std::cout << "X DISTANCE" << std::endl;

    } else {
        
        if ((distance > 0 && y >= maxY - 1) ||
            (distance < 0 && y <= 0)) {
            return;
        }

        y += distance;

        std::cout << "Y DISTANCE" << std::endl;
    }

}

int Cursor::getX() {
    return x;
}

int Cursor::getY() {
    return y;
}