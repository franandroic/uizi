#include "player.h"

Player::Player(std::string n, Cursor *c) {

    name = n;
    cursor = c;
    input = '0';
    signalToQuit = false;
}

bool Player::handleInput() {

    input = getchar();

    if (input == '\033') {

        getchar();
        switch (getchar()) {
            case 'A': {
                cursor->move(true, -1);
                break;
            }
            case 'B': {
                cursor->move(true, 1);
                break;
            }
            case 'C': {
                cursor->move(false, 1);
                break;
            }
            case 'D': {
                cursor->move(false, -1);
                break;
            }
            default:
                break;
        }
        
    } else {

        switch (input) {
            case '\n': {
                return true;
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