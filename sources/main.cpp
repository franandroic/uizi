#include <iostream>
#include <stdlib.h>
#include <vector>
#include <csignal>
#include <termios.h>

#include "map.h"
#include "zone.h"
#include "player.h"

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

        if (argc != 3) throw std::runtime_error("Bad number of arguments!");

        int x = atoi(argv[1]);
        int y = atoi(argv[2]);

        if (x == 0 || y == 0) throw std::runtime_error("Map dimension can't be 0!");

        Map map(x, y);
        Cursor cursor1(x, y);
        Cursor cursor2(x, y);
        Player player1("Player 1", &cursor1);
        Player player2("Player 2", &cursor2);
        Zone zone(&map, &player1, &player2);

        //map.print();
        //zone.print();

        enableTerminalRawMode();

        while(running) {

            std::cout << "\033[2J\033[H";   //change 2 to 3 to disable scrollback
            
            do {
                std::cout << player1.getName() << std::endl;
                zone.print();
            } while (!player1.handleInput());

            if (player1.getSignalToQuit()) {
                running = false;
                break;
            }
            
            do {
                std::cout << player2.getName() << std::endl;
                zone.print();
            } while (!player2.handleInput());

            if (player2.getSignalToQuit()) {
                running = false;
                break;
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