#include "getCaseNeighboor.h"
#include <vector>

using namespace std;

int *getCaseNeighboor(int i, int j)
{

    static int arr[4] = {200, 200, 200, 200}; // 200= il y a un mur

    const MazeSquare *square;

    square = gladiator->maze->getSquare(i, j); // GFA 4.7.1

    gladiator->log("----- WALL i=%d; j=%d -------", square->i, square->j); // GFA 4.5.1
    // vérifier s'il a un mur au dessus
    if (square->northSquare == nullptr)
    {
        gladiator->log("There a TOP wall"); // GFA 4.5.1
        arr[0] = 200;
    }
    else
    {
        arr[0] = i + (j + 1) * 12;
    }
    // vérifier s'il a un mur à droite
    if (square->eastSquare == nullptr)
    {
        gladiator->log("There a RIGHT wall"); // GFA 4.5.1
        arr[1] = 200;
    }
    else
    {
        arr[1] = i + 1 + j * 12;
    }
    // vérifier s'il a un mur en dessous
    if (square->southSquare == nullptr)
    {
        gladiator->log("There a BOTTOM wall"); // GFA 4.5.1
        arr[2] = 200;
    }
    else
    {
        arr[2] = i + (j - 1) * 12;
    }
    // vérifier s'il a un mur à gauche
    if (square->westSquare == nullptr)
    {
        gladiator->log("There a LEFT wall"); // GFA 4.5.1
        arr[3] = 200;
    }
    else
    {
        arr[3] = i - 1 + j * 12;
    }
    gladiator->log("----------------------------");

    return arr;
}
