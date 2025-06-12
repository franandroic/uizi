#pragma once

class Player;

class CombatObserver {

public:

    virtual bool updateCombatListener(Player *p, int x, int y) = 0;

    virtual ~CombatObserver() = default;

};