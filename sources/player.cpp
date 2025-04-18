#include "player.h"

// TODO define max of 2 actions and add attack option

Player::Player(std::string n, Cursor *c) {

    name = n;
    cursor = c;
    x = c -> getX();
    y = c -> getY();
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
                x = getCursor() -> getX();
                y = getCursor() -> getY();
                return true;
            }
            case ' ': {
                getCursor() -> setX(x);
                getCursor() -> setY(y);
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