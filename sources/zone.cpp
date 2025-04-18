#include "zone.h"

Zone::Zone(Map *m) {

    if (!m) throw std::runtime_error("Map non-existant!");
    map = m;

    activePlayerIdx = -1;

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

    printLine[players[activePlayerIdx]->getCursor()->getX() * printLineLength * 4 + printLineLength * 2 + players[activePlayerIdx]->getCursor()->getY() * (1 + 7) + 4] = 'X';

    std::cout << printLine << std::endl;
}

void Zone::registerPlayer(Player *p) {

    if (std::find(players.begin(), players.end(), p) != players.end()) throw std::runtime_error("Player already added!");

    players.push_back(p);

    if (players.size() == 1) activePlayerIdx = 0;
}

void Zone::nextTurn() {

    if (players.size() == 0) throw std::runtime_error("No players!");

    activePlayerIdx = (activePlayerIdx + 1) % players.size();
}