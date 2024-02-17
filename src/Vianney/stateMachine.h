#include <iostream>
#include <string>
#include "Sparta/melee.h"
#include "guardConditions.h"
#include "graphstrategy.h"

class StateMachine
{
public:
    GameState *game;
    enum class State
    {
        ATTENTE,
        RECHERCHE_FUSEE,
        EXPLORATION,
        PVP,
        RECHERCHE_CIBLE,
        TIRER
    };

    StateMachine(GameState *game);

    void transition();
    void executePVP();

private:
    State currentState;
};