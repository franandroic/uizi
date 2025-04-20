#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Map {

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

    void print();

    char elementAt(int ix, int iy);

    int getX();

    int getY();

};