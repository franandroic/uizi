#include "tile.h"

Tile::Tile() {

    tile = {{'+', '-', '-', '-', '-', '-', '-', '-', '+'},
            {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
            {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
            {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
            {'+', '-', '-', '-', '-', '-', '-', '-', '+'}};

    height = tile.size();
    width = tile[0].size();

    centralChar = tile[height / 2][width / 2];
}

Tile::~Tile() {

}

void Tile::markSelected(bool b) {

    if (b) tile[height / 2][width / 2] = 'I';
    else tile[height / 2][width / 2] = centralChar;
}

std::vector<std::vector<char>> Tile::getTile() {

    return tile;
}