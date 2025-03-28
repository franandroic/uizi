#include <stdio.h>
#include <vector>

class Map {

public:

    Map(int x, int y);

private:

    int x;
    int y;

    void generate();

public:

    std::vector<std::vector<char>> map;

    void print();

};