#include <iostream>
#include <stdlib.h>
#include <vector>

#include "map.h"
#include "zone.h"

int main(int argc, char *argv[]) {

    if (argc != 3) throw std::runtime_error("Bad number of arguments!");

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    if (x == 0 || y == 0) throw std::runtime_error("Map dimension can't be 0!");

    Map *map = new Map(x, y);
    Zone *zone = new Zone(map);
    
    map->print();
    zone->print();

    free(map);
    free(zone);

    return 0;
}