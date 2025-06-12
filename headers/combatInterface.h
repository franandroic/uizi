#pragma once

#include <vector>

#include "combatObserver.h"
#include "player.h"
#include "unit.h"

class CombatInterface : public CombatObserver {

public:

    CombatInterface();

private:

    std::vector<Player *> players;

public:

    void registerPlayer(Player *p);

    bool updateCombatListener(Player *p, int x, int y) override;

};