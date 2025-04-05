#include "zone.h"

Zone::Zone(Map *m) {

    if (!m) throw std::runtime_error("Map non-existant!");

    map = m;
}

void Zone::print() {

    printLine = "";

    std::cout << "\033[2J\033[H";

    for (int row = 0; row < map->getX() * 4 + 1; row++) {
        
        printIdx = row % 4;

        for (int col = 0; col < map->getY(); col++) {

            if (printIdx == 0)
                printLine += "+-------";
            else
                printLine += "|       ";

        }

        if (printIdx == 0)
            printLine += "+";
        else
            printLine += "|";

        std::cout << printLine << std::endl;
        printLine = "";

    }
}