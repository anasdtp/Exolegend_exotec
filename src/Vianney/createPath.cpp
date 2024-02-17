#include "creategraph.h"
#include "createPath.h"
using namespace std;
pathFinder coord_list_simplified;

pathFinder createCommands(pathFinder coord_list) // crée une suite d'instructions pour le robot en fonction d'une suite de cases à visiter
{
    int c = 0;
    int p = 0;
    coord_list_simplified.path_coord[0] = coord_list.path_coord[0];

    while (c < coord_list.size)
    {
        int k = 0;
        if (coord_list.path_coord[c].i == coord_list.path_coord[c + 1].i)
        {
            while (coord_list.path_coord[c].i == coord_list.path_coord[c + k].i)
            {
                k++;
            }
        }
        else
        {
            while (coord_list.path_coord[c].i != coord_list.path_coord[c + k].i)
            {
                k++;
            }
        }
        p++;
        coord_list_simplified.path_coord[p] = coord_list.path_coord[c + k];
        c = c + k;
    }
    coord_list_simplified.size = p;
    return coord_list_simplified;
}
