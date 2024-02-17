#pragma once

#include <vector>

std::vector<int> BFS(bool rocket_man = true, int i_goal = 0, int j_goal = 0);
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
