#include <iostream>
#include <string>
#include "Sparta/melee.h"
#include "guardConditions.h"
using namespace std;

// // Définition de la classe de la machine à états
// class StateMachine
// {
// public:
//     // Énumération des états possibles
//     enum class State
//     {
//         ATTENTE,
//         RECHERCHE_FUSEE,
//         EXPLORATION,
//         PVP,
//         RECHERCHE_CIBLE,
//         TIRER
//     };

//     // Constructeur
//     StateMachine() : currentState(State::ATTENTE) {}

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
        // on regarde si on peut tirer sinon on pvp si proche sinon retourne idle
        if (t_recherche_cible)
        {
            t_recherche_cible = false;
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
        currentState = State::ATTENTE;
        break;
    case State::RECHERCHE_CIBLE:
        // on regarde si on peut tirer sinon on pvp si proche sinon retourne idle
        if (t_tirer)
        {
            // attention a ne pas cycler
            currentState = State::TIRER;
        }
        else
        {
            currentState = State::EXPLORATION;
        }
        break;
    case State::TIRER:
        currentState = State::ATTENTE;
        break;
    }
}

//     // Méthode pour récupérer l'état actuel de la machine
//     State getCurrentState() const
//     {
//         return currentState;
//     }

// private:
//     // Variable d'état actuelle de la machine
//     State currentState;
// };

// int main()
// {
//     StateMachine machine;

// Boucle de démonstration de la machine à états
while (machine.getCurrentState() != StateMachine::State::ATTENTE)
{
    machine.transition();
}

//     return 0;
// }
