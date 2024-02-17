#include "gladiator.h"
#include "Vianney/creategraph.h"
#include <vector>
#include "Vianney/createPath.h"

#include "mouvement\movement.h"

float caseSize;
pathFinder coord_list;
pathFinder simplified_coord_list;
Gladiator *gladiator;

Position goal;

coordonnees go[] ={
    coordonnees{0, 4},
    coordonnees{1, 4},
    coordonnees{2, 6},
    coordonnees{6, 6},
    coordonnees{4, 3},
    coordonnees{3, 8},
    coordonnees{5, 8},
    coordonnees{7, 4},
    coordonnees{7, 6},
    coordonnees{6, 6},
    coordonnees{5, 6},
    coordonnees{6, 5},

};

void new_missile(){
    std::vector<int> path = BFS();
    coord_list.size = path.size();
    for (int i = 0; i < coord_list.size; i++)  {
        coord_list.path_coord[i].i = path[i] % 12;
        coord_list.path_coord[i].j = path[i] / 12;
    }
    simplified_coord_list = createCommands(coord_list);
}

void new_target(int i, int j){
    std::vector<int> path = BFS(false, i, j);
    coord_list.size = path.size();
    for (int i = 0; i < coord_list.size; i++)  {
        coord_list.path_coord[i].i = path[i] % 12;
        coord_list.path_coord[i].j = path[i] / 12;
    }
    simplified_coord_list = createCommands(coord_list);
}

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
    new_missile();
    // initialisation de toutes vos variables avant le début d'un match
    goal = gladiator->robot->getData().position;
}
Position current;
uint8_t count = 0;
bool shit = true;
int f = 0;
void loop()
{
    if (gladiator->game->isStarted())
    { // tester si un match à déjà commencer
        // code de votre stratégie
        current = gladiator->robot->getData().position;
        go_to(goal, current, gladiator);

        if (count == simplified_coord_list.size && f < 12){
            new_target(go[f].i, go[f].j);
            gladiator->log("new target");
            count = 0;
            f++;
        }

        if (distance(current, goal) <= THRESHOLD && count < simplified_coord_list.size)
        {
            goal = getSquareCoor(simplified_coord_list.path_coord[count].i, simplified_coord_list.path_coord[count].j, caseSize);
            gladiator->log("i: %d | j: %d", simplified_coord_list.path_coord[count].i, simplified_coord_list.path_coord[count].j);
            ++count;
        }
    }
}