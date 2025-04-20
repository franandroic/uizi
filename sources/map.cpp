#include "map.h"

Map::Map(int x, int y) {

    this->x = x;
    this->y = y;

    seed = time(NULL);
    density = 0;

    generate();
}

Map::Map(int x, int y, int d) {
    
    this->x = x;
    this->y = y;

    seed = time(NULL);
    density = d;

    generate();
}

void Map::generate() {

    map.resize(x);
    for (int row = 0; row < x; row++) {
        for (int col = 0; col < y; col++) {
            map[row].push_back('.');
        }
    }
    
    addObstacles();
}

void Map::addObstacles() {

    srand(seed);

    for (int i = 0; i < density; i++) {
        map[rand() % x][rand() % y] = 'X';
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

char Map::elementAt(int ix, int iy) {

    if (ix >= x || iy >= y) throw std::runtime_error("Map index out of range!");

    return map[ix][iy];
}

int Map::getX() {

    return x;
}

int Map::getY() {

    return y;
}