#include "gladiator.h"
#include "Vianney/creategraph.h"
#include <vector>
#include "Vianney/createPath.h"
#include "Vianney/stateMachine.h"
#include "Asservissement/Asservissement.h"
#include "GameData/GameData.h"

GameState *game;
Gladiator *gladiator;
StateMachine *robot_state_machine;

Asservissement *motors;

void reset();
void setup()
{
    // instanciation de l'objet gladiator
    gladiator = new Gladiator();
    motors = new Asservissement(gladiator);
    game = new GameState(gladiator, motors);
    // enregistrement de la fonction de reset qui s'éxecute à chaque fois avant qu'une partie commence
    robot_state_machine = new StateMachine(game);
    gladiator->game->onReset(&reset); // GFA 4.4.1

}

void reset()
{
    // fonction de reset:
    game->reset();

    // initialisation de toutes vos variables avant le début d'un match
    game->goal = gladiator->robot->getData().position;

    Serial.println("Game Start ! ");
    motors->setTargetPos(game->goal);
}

void loop()
{
    if (gladiator->game->isStarted())
    { // tester si un match à déjà commencer
        // code de votre stratégie
        game->Update();

        if (TempsEchantionnage(TE_10MS))
        {
            motors->positionControl(motors->getTargetPos());
        }
        robot_state_machine->machine();
    }
}