#include "zone.h"

Zone::Zone(Map *m) {

    if (!m) throw std::runtime_error("Map non-existant!");
    map = m;

    activePlayerIdx = -1;
    
    tiles.resize(map->getX(), std::vector<Tile *>(map->getY()));
    for (int row = 0; row < map->getX(); row++) {
        for (int col = 0; col < map->getY(); col++) {
            if (map->elementAt(row, col) == '.') tiles[row][col] = new Tile();
            if (map->elementAt(row, col) == 'X') tiles[row][col] = new TileX();
        }
    }
}

Zone::~Zone() {

    for (int row = 0; row < map->getX(); row++) {
        for (int col = 0; col < map->getY(); col++) {
            delete tiles[row][col];
        }
    }

    tiles.clear();
}

void Zone::print() {

    printString = "";
    Player *activePlayer = players[activePlayerIdx];

    tiles[activePlayer->getCursor()->getX()][activePlayer->getCursor()->getY()]->markSelected(true);
    
    for (int uIdx = 0; uIdx < activePlayer->getNumberOfUnits(); uIdx++) {
        tiles[activePlayer->getUnit(uIdx)->getX()][activePlayer->getUnit(uIdx)->getY()]->overlayIcon(true, activePlayer->getUnit(uIdx)->getIcon()->getIcon());
    }

    //Hardcoded tile dimensions to 5x9
    for (int mapRow = 0; mapRow < map->getX(); mapRow++) {
        for (int tileRow = 0; tileRow < (5 - 1); tileRow++) {
            for (int mapCol = 0; mapCol < map->getY(); mapCol++) {
                for (int tileCol = 0; tileCol < (9 - 1); tileCol++) {
                    printString += tiles[mapRow][mapCol]->getTile()[tileRow][tileCol];
                }
            }
            printString += tiles[mapRow][map->getY() - 1]->getTile()[tileRow][9 - 1];
            printString += '\n';
        }
    }

    for (int mapCol = 0; mapCol < map->getY(); mapCol++) {
        for (int tileCol = 0; tileCol < (9 - 1); tileCol++) {
            printString += tiles[map->getX() - 1][mapCol]->getTile()[5 - 1][tileCol];
        }
    }

    tiles[activePlayer->getCursor()->getX()][activePlayer->getCursor()->getY()]->markSelected(false);
    
    for (int uIdx = 0; uIdx < activePlayer->getNumberOfUnits(); uIdx++) {
        tiles[activePlayer->getUnit(uIdx)->getX()][activePlayer->getUnit(uIdx)->getY()]->overlayIcon(false, activePlayer->getUnit(uIdx)->getIcon()->getIcon());
    }

    std::cout << printString << std::endl;
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

void Zone::updatePlayerListener() {
    map->print();
    print();
}