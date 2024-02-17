#pragma once
#include "getcaseneighboor.h"
#include <vector>

std::vector<int> BFSPruned();
int heuristic(MazeSquare);
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
