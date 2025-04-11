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

    int getX();

    int getY();

};