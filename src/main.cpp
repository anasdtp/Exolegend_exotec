#include "gladiator.h"
#include "Vianney/creategraph.h"
#include <vector>
#include "Vianney/createPath.h"

#include "mouvement\movement.h"
#include "GameData\GameData.h"

GameState *game;
Gladiator *gladiator;

coordonnees go[] = {
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

void new_missile()
{
    std::vector<int> path = BFS(game);
    game->coord_list.size = path.size();
    for (int i = 0; i < game->coord_list.size; i++)
    {
        game->coord_list.path_coord[i].i = path[i] % 12;
        game->coord_list.path_coord[i].j = path[i] / 12;
    }
    game->simplified_coord_list = createCommands(game->coord_list);
}

void new_target(int i, int j)
{
    std::vector<int> path = BFS(game, false, i, j);
    game->coord_list.size = path.size();
    for (int i = 0; i < game->coord_list.size; i++)
    {
        game->coord_list.path_coord[i].i = path[i] % 12;
        game->coord_list.path_coord[i].j = path[i] / 12;
    }
    game->simplified_coord_list = createCommands(game->coord_list);
}

void reset();
void setup()
{
    // instanciation de l'objet gladiator
    gladiator = new Gladiator();
    game = new GameState(gladiator);
    // enregistrement de la fonction de reset qui s'éxecute à chaque fois avant qu'une partie commence

    gladiator->game->onReset(&reset); // GFA 4.4.1
}

void reset()
{
    // fonction de reset:
    game->reset();
    new_missile();
    // initialisation de toutes vos variables avant le début d'un match
    game->goal = gladiator->robot->getData().position;
    liste.type = TYPE_MOUVEMENT_SUIVANT;
    liste.fin = game->goal;
}
Position current;
uint8_t count = 0;
bool shit = true;
int f = 0;
void loop()
{
    if (gladiator->game->isStarted())
    { // tester si un match à déjà commencer
        game->Update();
        
        if (TempsEchantionnage(TE_10MS))
        {
            calcul();
        }


        static int etat = 0;
        switch (etat)
        {
        case 0:
        {
            // code de votre stratégie
            current = gladiator->robot->getData().position;

            if (count == game->simplified_coord_list.size && f < 12)
            {
                new_target(go[f].i, go[f].j);
                gladiator->log("new target");
                count = 0;
                f++;
            }

            if (getDistance(current, game->goal) <= THRESHOLD && count < game->simplified_coord_list.size)
            {
                game->goal = getSquareCoor(game->simplified_coord_list.path_coord[count].i, game->simplified_coord_list.path_coord[count].j, game->squareSize);
                gladiator->log("i: %d | j: %d", game->simplified_coord_list.path_coord[count].i, game->simplified_coord_list.path_coord[count].j);
                ++count;

                // go_to(game->goal, current, gladiator);
                liste.type = TYPE_DEPLACEMENT_LIGNE_DROITE;
                liste.fin = game->goal;
                gladiator->log("Position liste.fin.x = %f, liste.fin.y = %f, liste.fin.a = %f", liste.fin.x, liste.fin.y, liste.fin.a);
                etat = 1;
            }

            if(gladiator->weapon->canLaunchRocket()){
                gladiator->weapon->launchRocket();
            }

        }
        break;
        case 1:
        {
            if (next_action)
            {
                next_action = false;
                etat = 0;
            }
        }
        break;
        default:
            break;
        }
            
    }
}