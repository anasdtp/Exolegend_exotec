#include <iostream>
#include <string>
#include "Sparta/melee.h"
#include "guardConditions.h"
#include "graphstrategy.h"
using namespace std;

// Définition de la classe de la machine à états
class StateMachine
{
public:
    // Énumération des états possibles
    enum class State
    {
        ATTENTE,
        RECHERCHE_FUSEE,
        EXPLORATION,
        PVP,
        RECHERCHE_CIBLE,
        TIRER
    };

    // Constructeur
    StateMachine() : currentState(State::ATTENTE) {}

    // Méthode pour effectuer une transition d'état
    void transition()
    {
        bool t_recherche_fusee = !gladiator->weapon->canLaunchRocket();
        bool t_ennemi_proche = ennemi_proche();
        bool t_recherche_cible = true;
        bool t_tirer = true;
        gladiator->log("Possède une fusée : %d", t_recherche_fusee);
        switch (currentState)
        {
        case State::ATTENTE:
            // on regarde s'il y a un robot au corps à corps sinon on recherche une fusée sinon on explore
            if (t_ennemi_proche)
            {
                //______ recherche position robot allié____________
                currentState = State::PVP;
            }
            if (t_recherche_fusee)
            {
                currentState = State::RECHERCHE_FUSEE;
                // APPEL A FONCTION NEW MISSILE
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
            //____lance exploration___________
            vector<int> path = BFSPruned();
            // LANCER GOTO AVEC ROBOT
            // on regarde si on peut tirer sinon on pvp si proche sinon retourne idle
            if (t_recherche_cible)
            {

                // attention a ne pas cycler
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
            break;
        case State::PVP:
            //______ recherche position robot allié____________
            RobotData my_data = gladiator->robot->getData();
            RobotData ally_data;
            RobotList ids_list = gladiator->game->getPlayingRobotsId();
            for (int i = 0; i < 4; i++)
            {

                if ((ids_list.ids[i] == 121 || ids_list.ids[i] != 120) && ids_list.ids[i] != my_data.id)
                {
                    ally_data = gladiator->game->getOtherRobotData(ids_list.ids[i]);
                }
            }
            //_________________________________________________

            SpartanMode(gladiator, ally_data.position);
            currentState = State::ATTENTE;
            break;
        case State::RECHERCHE_CIBLE:
            t_recherche_cible = false;
            // on regarde si on peut tirer sinon on pvp si proche sinon retourne idle
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
            gladiator->weapon->launchRocket();
            currentState = State::ATTENTE;
            break;
        }
    }

private:
    // Variable d'état actuelle de la machine
    State currentState;
};
