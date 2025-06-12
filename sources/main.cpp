#include <iostream>
#include <stdlib.h>
#include <vector>
#include <csignal>
#include <termios.h>
#include <thread>
#include <chrono>

#include "map.h"
#include "zone.h"
#include "player.h"
#include "combatInterface.h"
#include "aiAdapter.h"

#define NUM_OF_PLAYERS 2
#define SIZE_OF_MAP 8
#define OBSTACLE_DENSITY 10

bool running = true;

void enableTerminalRawMode() {

    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void disableTerminalRawMode() {

    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void handleInterruption(int signal) {

    std::cout << "Ending the game..." << std::endl;
    disableTerminalRawMode();
    running = false;
}

int main(int argc, char *argv[]) {

    try {

        signal(SIGINT, handleInterruption);

        /*
        if (argc != 3) throw std::runtime_error("Bad number of arguments!");

        int x = atoi(argv[1]);
        int y = atoi(argv[2]);

        if (x == 0 || y == 0) throw std::runtime_error("Map dimension can't be 0!");
        */

        Map map(SIZE_OF_MAP, SIZE_OF_MAP, OBSTACLE_DENSITY);
        Zone zone(&map);
        CombatInterface combatInterface;

        //map.print();

        std::vector<std::string> playerNames = {"Player 1", "Player 2"};
        std::vector<Cursor> cursors;
        std::vector<Player> players;

        cursors.reserve(NUM_OF_PLAYERS);
        players.reserve(NUM_OF_PLAYERS);

        for (int i = 0; i < NUM_OF_PLAYERS; i++) {
            cursors.emplace_back(SIZE_OF_MAP, SIZE_OF_MAP);
            players.emplace_back(i + 1, playerNames[i], &cursors[i]);
            zone.registerPlayer(&players[i]);
            players[i].subscribePlayerListener(&zone);
            for (int j = 0; j < players[i].getNumberOfUnits(); j++) {
                players[i].getUnit(j)->subscribeUnitListener(&map);
                players[i].getUnit(j)->moveTo(players[i].getUnit(j)->getX(), players[i].getUnit(j)->getY());
            }
            combatInterface.registerPlayer(&players[i]);
            players[i].subscribeCombatListener(&combatInterface);
        }

        //std::cout << players[0].getName() << " " << players[0].getCursor()->getX() << " " << players[0].getCursor()->getY() << std::endl;

        AiAdapter adapter(&map, &players, &combatInterface);
        
        enableTerminalRawMode();

        while(running) {

            std::cout << "\033[2J\033[H";   //change 2 to 3 to disable scrollback
            
            for (Player &player : players) {
                if (!running) break;
                adapter.constructGameStateString();
                std::cout << adapter.getGameState() << std::endl;

                if (player.getId() == 2) {
                    std::cout << "--- AI Player's Turn ---" << std::endl;
                    adapter.makeMove(&player);
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                } else {
                     running = player.handleInput();
                }

                if (!running) break;
                if (running) zone.nextTurn();

            }
        }

    } catch (const std::exception &e) {

        std::cout << "Caught exception: " << e.what() << std::endl;

    } catch (...) {

        std::cout << "Caught exception!" << std::endl;
    }

    disableTerminalRawMode();

    return 0;
}