#pragma once

#include <vector>

class Icon {

public:

    Icon();

private:

    std::vector<std::vector<char>> icon;

    int height;
    int width;

public:

    std::vector<std::vector<char>> getIcon();

    int getHeight();

    int getWidth();

};