#pragma once
#include "gladiator.h"
#include "Vianney/creategraph.h"

class GameState{
    public:
    Gladiator *gladiator;
    RobotData myData;
    RobotData allyData;
    RobotData er1Data;
    RobotData er2Data;

    Position goal;

    float squareSize;

    pathFinder coord_list;
    pathFinder simplified_coord_list;

    GameState(Gladiator *gladiator);

    void Update();
    void reset();
};