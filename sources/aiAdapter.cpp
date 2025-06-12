#include "aiAdapter.h"

AiAdapter::AiAdapter(Map *m) {

    map = m;
    gameState = "";
}

void AiAdapter::constructGameStateString() {

    gameState = "";

    for (int row = 0; row < map->dynamicMap.size(); row++) {
        for (int col = 0; col < map->dynamicMap[row].size(); col++) {
            gameState += map->dynamicMap[row][col];
        }
    }

}

std::string AiAdapter::getGameState() {
    return gameState;
}