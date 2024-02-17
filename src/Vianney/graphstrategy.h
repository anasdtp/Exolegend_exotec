#pragma once
#include "getcaseneighboor.h"
#include <vector>
#define max_parth_finder_size 24
std::vector<int> BFSPruned();
int heuristic(const MazeSquare *sqr);
struct coordonnees
{
    int i;
    int j;
};

struct pathFinder
{
    int size;
    coordonnees path_coord[max_parth_finder_size];
};
