#include "icon.h"

Icon::Icon() {

    icon = {{'/', '-', '-', '-', '\\'},
            {'|', '.', '.', '.', '|'},
            {'\\', '-', '-', '-', '/'}};

    height = icon.size();
    width = icon[0].size();
}

std::vector<std::vector<char>> Icon::getIcon() {

    return icon;
}

int Icon::getHeight() {

    return height;
}

int Icon::getWidth() {

    return width;
}