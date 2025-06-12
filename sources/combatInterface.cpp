#include "combatInterface.h"

CombatInterface::CombatInterface() {

}

void CombatInterface::registerPlayer(Player *p) {
    players.push_back(p);
}

bool CombatInterface::updateCombatListener(Player *p, int x, int y) {

    for (Player *other : players) {
        if (other != p) {
            for (int u = 0; u < other->getNumberOfUnits(); u++) {
                if (x == other->getUnit(u)->getX() && y == other->getUnit(u)->getY()) {
                    other->damageUnit(u, 1);    //hardcoded damage to 1
                    return true;
                }
            }
        }
    }

    return false;

}