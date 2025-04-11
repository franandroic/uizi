#pragma once

#include <iostream>
#include <vector>

class Map {

public:

    Map(int x, int y);

    //~Map();

private:

    int x;
    int y;

    void generate();

public:

    std::vector<std::vector<char>> map;

    void print();

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

};