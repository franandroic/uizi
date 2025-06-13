#include "aiAdapter.h"
#include <iostream>
#include <cmath>

// Ažuriran konstruktor
AiAdapter::AiAdapter(Map *m, std::vector<Player> *players, CombatInterface *ci) {
    map = m;
    gameState = "";
    allPlayers = players;
    combatInterface = ci;
}

void AiAdapter::constructGameStateString() {
    gameState = "";

    if (!map) {
        std::cerr << "Error: Map pointer is null in AiAdapter::constructGameStateString(). Cannot construct game state." << std::endl;
        return;
    }

    map->dynamicMap = map->map;

    if (allPlayers) {
        for (Player &player : *allPlayers) {
            for (int u = 0; u < player.getNumberOfUnits(); u++) {
                Unit *currentUnit = player.getUnit(u);
                if (currentUnit &&
                    currentUnit->getHealth() > 0 &&
                    currentUnit->getX() >= 0 && currentUnit->getX() < map->getX() &&
                    currentUnit->getY() >= 0 && currentUnit->getY() < map->getY()) {

                currentUnit->getIcon()->embedId(currentUnit->getId(), player.getId());

                map->dynamicMap[currentUnit->getX()][currentUnit->getY()] = '0' + player.getId();
                }
            }
        }
    }

    for (int row = 0; row < map->dynamicMap.size(); row++) {
        for (int col = 0; col < map->dynamicMap[row].size(); col++) {
            gameState += map->dynamicMap[row][col];
        }
    }
}

std::string AiAdapter::getGameState() {
    return gameState;
}

Unit* AiAdapter::findClosestEnemyUnit(Player *aiPlayer, Unit *aiUnit, int &targetX, int &targetY) {
    Unit *closestEnemy = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (Player &otherPlayer : *allPlayers) {
        if (otherPlayer.getId() != aiPlayer->getId()) {
            for (int i = 0; i < otherPlayer.getNumberOfUnits(); ++i) {
                Unit *enemyUnit = otherPlayer.getUnit(i);
                if (enemyUnit->getHealth() > 0) {
                    double distance = std::sqrt(std::pow(aiUnit->getX() - enemyUnit->getX(), 2) +
                                                std::pow(aiUnit->getY() - enemyUnit->getY(), 2));
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestEnemy = enemyUnit;
                        targetX = enemyUnit->getX();
                        targetY = enemyUnit->getY();
                    }
                }
            }
        }
    }
    return closestEnemy;
}

bool AiAdapter::isUnitAdjacent(Unit *unit1, Unit *unit2) {
    return (std::abs(unit1->getX() - unit2->getX()) + std::abs(unit1->getY() - unit2->getY()) <= 1);
}

void AiAdapter::makeMove(Player *aiPlayer) {
    if (!aiPlayer) return;

    for (int i = 0; i < aiPlayer->getNumberOfUnits(); ++i) {
        Unit *currentAiUnit = aiPlayer->getUnit(i);
        if (!currentAiUnit || currentAiUnit->getHealth() <= 0) continue;

        int targetX = -1, targetY = -1;
        Unit *closestEnemy = findClosestEnemyUnit(aiPlayer, currentAiUnit, targetX, targetY);

        if (closestEnemy) {

            int currentX = currentAiUnit->getX();
            int currentY = currentAiUnit->getY();

            int bestNx = -1, bestNy = -1;
            double minDistanceToEnemy = std::numeric_limits<double>::max();
            //bool foundValidMoveTarget = false;
            bool moved = false;

            for (int dy = -2; dy <= 2; ++dy) {
                for (int dx = -2; dx <= 2; ++dx) {

                    if (std::abs(dx) + std::abs(dy) > 2) continue;

                    int potentialNx = currentX + dx;
                    int potentialNy = currentY + dy;

                    if (potentialNx >= 0 && potentialNx < map->getX() &&
                        potentialNy >= 0 && potentialNy < map->getY()) {

                        double distToEnemy = std::sqrt(std::pow(potentialNx - targetX, 2) +
                                                        std::pow(potentialNy - targetY, 2));

                        if (distToEnemy <= minDistanceToEnemy) {
                            bestNx = potentialNx;
                            bestNy = potentialNy;
                            //foundValidMoveTarget = true;
                            moved = currentAiUnit->moveTo(bestNx, bestNy);
                            if (moved) minDistanceToEnemy = distToEnemy;
                        }
                    }

                    if (moved) break;
                }
                if (moved) break;
            }

            if (moved) {
                std::cout << "AI Player " << aiPlayer->getId() << ", Unit " << currentAiUnit->getId()
                            << " moved from (" << currentX << "," << currentY << ") to (" << bestNx
                            << "," << bestNy << ") towards enemy at (" << targetX << "," << targetY << ")" << std::endl;

                if (isUnitAdjacent(currentAiUnit, closestEnemy)) {
                    std::cout << "AI Player " << aiPlayer->getId() << ", Unit " << currentAiUnit->getId()
                            << " attacks enemy unit " << closestEnemy->getId() << " at (" << closestEnemy->getX()
                            << "," << closestEnemy->getY() << ")!" << std::endl;

                    if (combatInterface) {
                        combatInterface->updateCombatListener(aiPlayer, closestEnemy->getX(), closestEnemy->getY());
                    } else {
                        std::cerr << "Error: CombatInterface pointer is null in AiAdapter::makeMove(). Cannot perform attack." << std::endl;
                    }
                }

            } else {
                std::cout << "AI Player " << aiPlayer->getId() << ", Unit " << currentAiUnit->getId()
                            << " could not find a valid move target towards enemy within 2 squares." << std::endl;
            }
        }
    }
}