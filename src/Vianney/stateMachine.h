#include <iostream>
#include <string>
#include "Sparta/melee.h"
#include "guardConditions.h"
#include "graphstrategy.h"
#include "GameData/GameData.h"

class StateMachine
{
public:
    enum class State
    {
        ATTENTE,
        RECHERCHE_FUSEE,
        EXPLORATION,
        PVP,
        RECHERCHE_CIBLE,
        TIRER
    };

    GameState *game;
    State currentState;

    int etat_exploration;
    StateMachine(GameState *game);

    void machine();
    void executePVP();
};