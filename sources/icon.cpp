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

void Icon::embedId(int id1, int id2) {
    icon[0][width - 1] = '0' + id1;
    icon[height - 1][width - 1] = '0' + id2;
}