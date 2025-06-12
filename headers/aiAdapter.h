#pragma once

#include <string>

#include "map.h"

class AiAdapter {
    
public:
    
    AiAdapter(Map *m);

private:

    Map *map;

    std::string gameState;

public:

    void constructGameStateString();

    std::string getGameState();
};