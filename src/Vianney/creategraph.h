#pragma once

#include <vector>

std::vector<int> BFS(int i_goal = 44, int j_goal = 44);
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
