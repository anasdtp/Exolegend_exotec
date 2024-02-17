#pragma once

#include <vector>

std::vector<int> BFS();
struct coordonnees
{
    int i;
    int j;
};

struct pathFinder
{
    int size;
    coordonnees path_coord[12];
};
