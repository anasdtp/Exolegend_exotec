#pragma once
#include "gladiator.h"

#define THRESHOLD 0.07

extern float kw, kv, wlimit, vlimit, erreurPos;

Position getSquareCoor(const MazeSquare *square, float squareSize);
Position getSquareCoor(uint8_t i, uint8_t j, float squareSize);
float distance(const Position &p1, const Position &p2);

double reductionAngle(double x);
void go_to(Position cons, Position pos, Gladiator *gladiator);