#include "movement.h"

float kw = 10.f;
float kv = 2.f;
float wlimit = 3.f;
float vlimit = 1.f;
float erreurPos = 0.07;

Position getSquareCoor(const MazeSquare *square, float squareSize)
{
    return getSquareCoor(square->i, square->j, squareSize);
}

Position getSquareCoor(uint8_t i, uint8_t j, float squareSize)
{
    Position coor;
    coor.x = (i + 0.5) * squareSize;
    coor.y = (j + 0.5) * squareSize;

    return coor;
}

float distance(const Position &p1, const Position &p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

double reductionAngle(double x)
{
    x = fmod(x + PI, 2 * PI);
    if (x < 0)
        x += 2 * PI;
    return x - PI;
}
void go_to(Position cons, Position pos, Gladiator *gladiator)
{
    double consvl, consvr;
    double dx = cons.x - pos.x;
    double dy = cons.y - pos.y;
    double d = sqrt(dx * dx + dy * dy);

    if (d > erreurPos)
    {
        double rho = atan2(dy, dx);
        double consw = kw * reductionAngle(rho - pos.a);

        double consv = kv * d * cos(reductionAngle(rho - pos.a));
        consw = abs(consw) > wlimit ? (consw > 0 ? 1 : -1) * wlimit : consw;
        consv = abs(consv) > vlimit ? (consv > 0 ? 1 : -1) * vlimit : consv;

        consvl = consv - gladiator->robot->getRobotRadius() * consw; // GFA 3.6.2
        consvr = consv + gladiator->robot->getRobotRadius() * consw; // GFA 3.6.2
    }
    else
    {
        consvr = 0;
        consvl = 0;
    }

    gladiator->control->setWheelSpeed(WheelAxis::RIGHT, consvr, false); // GFA 3.2.1
    gladiator->control->setWheelSpeed(WheelAxis::LEFT, consvl, false);  // GFA 3.2.1
}