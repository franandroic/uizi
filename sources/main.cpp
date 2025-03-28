#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "map.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Bad no. of arguments.\n");
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    if (x == 0 || y == 0) {
        printf("Bad type of arguments.\n");
        return 1;
    }

    Map *map = new Map(x, y);

    printf("%d, %d\n", x, y);
    map->print();

    return 0;
}