#include "map.h"

Map::Map(int x, int y) {

    this->x = x;
    this->y = y;
    generate();
}

void Map::generate() {

    std::vector<char> temp;

    for (int row = 0; row < x; row++) {
        for (int col = 0; col < y; col++) {
            temp.push_back('.');
        }
        map.push_back(temp);
        temp.clear();
    }
}

void Map::print() {

    for (int row = 0; row < map.size(); row++) {
        for (int col = 0; col < map[row].size(); col++) {
            printf("%c", map[row][col]);
        }
        printf("\n");
    }
}