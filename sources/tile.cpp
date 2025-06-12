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

void Tile::overlayIcon(bool draw, std::vector<std::vector<char>> icon) {

    if (draw) {
        
        //hardcoded values for now
        for (int rowT = 1, rowI = 0; rowT < 4, rowI < 3; rowT++, rowI++) {
            for (int colT = 2, colI = 0; colT < 7, colI < 5; colT++, colI++) {
                if (icon[rowI][colI] != '.') tile[rowT][colT] = icon[rowI][colI];
            }
        }

    } else {

        for (int rowT = 1; rowT < 4; rowT++) {
            for (int colT = 2; colT < 7; colT++) {
                tile[rowT][colT] = centralChar;
            }
        }
    }
}

std::vector<std::vector<char>> Tile::getTile() {

    return tile;
}