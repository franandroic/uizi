#pragma once

#include <vector>

class Tile {

public:

    Tile();

    virtual ~Tile();

protected:

    std::vector<std::vector<char>> tile;

    int height;
    int width;

    char centralChar;

public:

    void markSelected(bool b);

    std::vector<std::vector<char>> getTile();

};