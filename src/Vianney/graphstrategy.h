#pragma once
#include "getcaseneighboor.h"
#include <vector>
#include "GameData/GameData.h"
#define max_parth_finder_size 24
std::vector<int> BFSPruned(GameState *game);
int heuristic(const MazeSquare *sqr, GameState *game);
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
