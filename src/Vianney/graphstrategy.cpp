#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <tuple>
#include "getcaseneighboor.h"
#include "graphstrategy.h"
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> BFSPruned()
{
    // Marquer tous les sommets comme non visités
    bool visited[144] = {false}; // les coordonnées des sommets sont codées en un int a, tq : a=i+j*12

    const MazeSquare *square = gladiator->maze->getNearestSquare(); // position du robot comme case de départ

    uint8_t i_index = square->i; // indice colonne selon la convention
    uint8_t j_index = square->j; // indice ligne selon la convention

    int start_coord = i_index + j_index * 12;
    int end_coord;

    queue<int> q; // Créer une file pour le BFS

    visited[start_coord] = true; // Marquer le sommet de départ comme visité et l'ajouter à la file
    q.push(start_coord);
    unordered_map<int, tuple<int, int>> path_dict; // key,pred,cost
    int depth_goal = 50;
    int depth = 1;

    while (depth < depth_goal)
    {
        // Extraire un sommet de la file
        int currentVertex = q.front();
        int i = currentVertex % 12;
        int j = currentVertex / 12;
        q.pop();
        int *result = getCaseNeighboor(i, j);

        for (int i = 0; i < 4; ++i) // Parcourir tous les sommets adjacents du sommet courant
        {

            int adjacentVertex = result[i];
            int i_a = adjacentVertex % 12;
            int j_a = adjacentVertex / 12;
            gladiator->log("case visitée :%d,%d", i_a, j_a);
            // Si un sommet adjacent n'a pas encore été visité, le marquer comme visité
            // et l'ajouter à la file
            if (adjacentVertex != 200)
            {
                if (!visited[adjacentVertex])
                {
                    visited[adjacentVertex] = true;
                    q.push(adjacentVertex);
                    tuple<int, int> t;
                    get<0>(t) = currentVertex;
                    const MazeSquare *sqr = gladiator->maze->getSquare(i_a, j_a);
                    get<1>(t) = heuristic(sqr);
                    path_dict[adjacentVertex] = t;
                }
            }
        }
        depth++;
    }
    // trouve la case de plus faible cout
    end_coord = 60;
    // trouve le chemin vers la case de plus faible cout
    vector<int> path;
    int current = end_coord;
    while (current != start_coord)
    {
        path.push_back(current);
        current = get<0>(path_dict.at(current));
    }
    path.push_back(start_coord);
    reverse(path.begin(), path.end()); // Inverser le chemin car on l'a construit de la fin au début
    return path;
}

int heuristic(const MazeSquare *sqr)
{

    return 0;
}