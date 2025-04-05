#include "map.h"

Map::Map(int x, int y) {

    this->x = x;
    this->y = y;
    generate();
}

void Map::generate() {

    map.resize(x);

    for (int row = 0; row < x; row++) {
        for (int col = 0; col < y; col++) {
            map[row].push_back('.');
        }
    }
}

void Map::print() {

    for (int row = 0; row < map.size(); row++) {
        for (int col = 0; col < map[row].size(); col++) {
            std::cout << map[row][col];
        }
        std::cout << std::endl;
    }
}