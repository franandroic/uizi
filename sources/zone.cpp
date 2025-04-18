#include "zone.h"

Zone::Zone(Map *m, Player *p1, Player *p2) {

    if (!m) throw std::runtime_error("Map non-existant!");
    map = m;

    if (!p1 || !p2) throw std::runtime_error("There aren't two players!");
    player1 = p1;
    player2 = p2;

    printLine = "";
    printIdx = 0;
    printLineLength = map->getY() * (1 + 7) + 1 + 1;
}

void Zone::print() {

    printLine = "";

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

        printLine +="\n";
    }

    printLine[player1->getCursor()->getX() * printLineLength * 4 + printLineLength * 2 + player1->getCursor()->getY() * (1 + 7) + 4] = 'X';

    std::cout << printLine << std::endl;
}