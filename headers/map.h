#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "unitObserver.h"

class Map : public UnitObserver {

public:

    Map(int x, int y);

    Map(int x, int y, int d);

    //~Map();

private:

    int x;
    int y;

    int seed;
    int density;

    void generate();

    void addObstacles();

public:

    std::vector<std::vector<char>> map;

    std::vector<std::vector<char>> dynamicMap;

    void print();

    void printDynamic();

    char elementAt(int ix, int iy);

    int getX();

    int getY();

    bool updateUnitListener(int ownerId, int oldX, int oldY, int newX, int newY) override;

};