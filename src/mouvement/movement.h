#pragma once
#include "gladiator.h"

#define THRESHOLD 0.1

extern float kw, kv, wlimit, vlimit, erreurPos, squareSize;

Position getSquareCoor(const MazeSquare *square);
Position getSquareCoor(uint8_t i, uint8_t j);
float distance(const Position &p1, const Position &p2);

double reductionAngle(double x);
void go_to(Position cons, Position pos, Gladiator *gladiator);