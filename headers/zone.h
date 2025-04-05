#pragma once

#include <iostream>
#include <string>

#include "map.h"

class Zone {

public:

    Zone(Map *m);

private:

    Map *map;

    std::string printLine;
    int printIdx;

public:

    void print();

};