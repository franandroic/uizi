#include "player.h"

#define MAX_ACTIONS 2

Player::Player(std::string n, Cursor *c) {

    name = n;
    cursor = c;
    x = c -> getX();
    y = c -> getY();
    input = '0';
    signalToQuit = false;
    actionsTaken = 0;
}

bool Player::handleInput() {

    input = getchar();  

    if (input == '\033' && actionsTaken < MAX_ACTIONS) {

        getchar();
        switch (getchar()) {
            case 'A': {
                cursor->move(true, -1);
                actionsTaken++;
                break;
            }
            case 'B': {
                cursor->move(true, 1);
                actionsTaken++;
                break;
            }
            case 'C': {
                cursor->move(false, 1);
                actionsTaken++;
                break;
            }
            case 'D': {
                cursor->move(false, -1);
                actionsTaken++;
                break;
            }
            default:
                break;
        }
        
    } else {

        switch (input) {
            case '\n': {
                x = getCursor() -> getX();
                y = getCursor() -> getY();
                actionsTaken = 0;
                return true;
            }
            case ' ': {
                getCursor() -> setX(x);
                getCursor() -> setY(y);
                actionsTaken = 0;
                return false;
            }
            case 'q': {
                signalToQuit = true;
                return true;   
            }
            default:
                break;
        }

    }

    return false;
}

std::string Player::getName() {
    return name;
}

Cursor *Player::getCursor() {
    return cursor;
}

bool Player::getSignalToQuit() {
    return signalToQuit;
}