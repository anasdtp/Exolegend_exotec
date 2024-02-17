#include "stateMachine.h"
#include "GameData/GameData.h"
#include <vector>
StateMachine::StateMachine(GameState *game) : game(game), currentState(State::ATTENTE) {}

void StateMachine::transition()
{
    bool t_recherche_fusee = !game->gladiator->weapon->canLaunchRocket();
    bool t_ennemi_proche = ennemi_proche(game->gladiator);
    bool t_recherche_cible = true;
    bool t_tirer = true;
    game->gladiator->log("Possède une fusée : %d", t_recherche_fusee);

    switch (currentState)
    {
        case State::ATTENTE:
            if (t_ennemi_proche)
            {
                currentState = State::PVP;
            }
            if (t_recherche_fusee)
            {
                currentState = State::RECHERCHE_FUSEE;
            }
            else
            {
                currentState = State::EXPLORATION;
            }
            break;

        case State::RECHERCHE_FUSEE:
            currentState = State::ATTENTE;
            break;

        case State::EXPLORATION:
            {
                std::vector<int> path = BFSPruned(game);
                if (t_recherche_cible)
                {
                    currentState = State::RECHERCHE_CIBLE;
                }
                if (t_ennemi_proche)
                {
                    currentState = State::PVP;
                }
                else
                {
                    currentState = State::ATTENTE;
                }
            }
            break;

        case State::PVP:
            executePVP();
            currentState = State::ATTENTE;
            break;

        case State::RECHERCHE_CIBLE:
            t_recherche_cible = false;
            if (t_tirer)
            {
                currentState = State::TIRER;
            }
            else
            {
                currentState = State::EXPLORATION;
            }
            break;

        case State::TIRER:
            game->gladiator->weapon->launchRocket();
            currentState = State::ATTENTE;
            break;
        }
}
void StateMachine::executePVP()
{
    RobotData my_data = game->gladiator->robot->getData();
    RobotData ally_data;
    RobotList ids_list = game->gladiator->game->getPlayingRobotsId();
    for (int i = 0; i < 4; i++)
    {
        if ((ids_list.ids[i] == 121 || ids_list.ids[i] != 120) && ids_list.ids[i] != my_data.id)
        {
            ally_data = game->gladiator->game->getOtherRobotData(ids_list.ids[i]);
        }
    }
    SpartanMode(game);
}
