#pragma once

#include <iostream>

class Cursor {

public:

    Cursor(int mx, int my);

    //~Cursor();

private:

    int x;
    int y;

    int maxX;
    int maxY;

public:

    void move(bool direction, int distance);

    void moveTo(int nx, int ny);

    int getX();

    int getY();

    void setX(int nx);

    void setY(int ny);

};