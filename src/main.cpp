#include "gladiator.h"
#include "Vianney/creategraph.h"
#include <vector>
#include "Vianney/createPath.h"
int caseSize;
pathFinder coord_list;
pathFinder simplified_coord_list;
Gladiator *gladiator;
void reset();
void setup()
{
    // instanciation de l'objet gladiator
    gladiator = new Gladiator();
    // enregistrement de la fonction de reset qui s'éxecute à chaque fois avant qu'une partie commence

    gladiator->game->onReset(&reset); // GFA 4.4.1
}

void reset()
{
    // fonction de reset:
    caseSize = gladiator->maze->getSquareSize();
    std::vector<int> path = BFS();
    coord_list.size = path.size();
    simplified_coord_list = createCommands(coord_list);
    gladiator->log("_______PATH________");
    for (int i = 0; i < simplified_coord_list.size; i++)
    {
        simplified_coord_list.path_coord[i].i = path[i] % 12;
        simplified_coord_list.path_coord[i].j = path[i] / 12;
        gladiator->log(" i=%d; j=%d -------", simplified_coord_list.path_coord[i].i, simplified_coord_list.path_coord[i].j);
    }
    gladiator->log("_______PATH________");

    // initialisation de toutes vos variables avant le début d'un match
    gladiator->log("Call of reset function"); // GFA 4.5.1
}

void loop()
{
    if (gladiator->game->isStarted())
    { // tester si un match à déjà commencer
        // code de votre stratégie
        gladiator->log("Hello world - Game Started"); // GFA 4.5.1
    }
    else
    {
        gladiator->log("Hello world - Game not Startd yet"); // GFA 4.5.1
    }
    delay(300);
}