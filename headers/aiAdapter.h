#pragma once

#include <string>
#include <vector>
#include <limits>

#include "map.h"
#include "player.h"
#include "unit.h"
#include "combatInterface.h"

class AiAdapter {
    
public:
    AiAdapter(Map *m, std::vector<Player> *players, CombatInterface *ci);

private:
    Map *map;
    std::string gameState;
    std::vector<Player> *allPlayers;
    CombatInterface *combatInterface;

public:
    void constructGameStateString();
    std::string getGameState();
    void makeMove(Player *aiPlayer);

private:
    Unit* findClosestEnemyUnit(Player *aiPlayer, Unit *aiUnit, int &targetX, int &targetY);
    bool isUnitAdjacent(Unit *unit1, Unit *unit2);
};