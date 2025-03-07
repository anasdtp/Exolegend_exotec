#ifndef ASSERVISSEMENT_H
#define ASSERVISSEMENT_H
#include "gladiator.h"
#include <functional>

using FuncType = std::function<float(float)>;

#include <functional>

#define TE_MS 50
#define TE (TE_MS*0.001)

#define INITIALISATION 0
#define GO_TO_POS 1
#define ROTATION 4
#define ARRET 3


typedef struct
{
    float Kp; // = 0.04f; // Proportional gain
    float Ki; // = 0.f;    // Integral gain
    float Kd; // = 0.1f; // Derivative gain

    float integral, prev_error;
} PIDCoef;


Position getSquareCoor(const MazeSquare *square, float squareSize);
Position getSquareCoor(uint8_t i, uint8_t j, float squareSize);
float getDistance(const Position &p1, const Position &p2);
double reductionAngle(double x);
bool TempsEchantionnage(unsigned long TIME);

class Asservissement
{
private:
    Position currentPos;
    Position targetPos;

    float acc_max;// = 0.6f;
    float v_max;// = 0.8f;
    float ta;
    float d_max;

    FuncType traj;
    
    PIDCoef goTo;
    PIDCoef rotation;

    float robot_radius;

    float Threshold = 0.01f, toleranceAngle = 8.f * PI/180.f; // Adjust as needed
    float consvl = 0.f, consvr = 0.f;

    float kw = 3.f * 2.f;
    float kv = 0.75f * 2.f;
    float erreurPos = 0.07f;

    unsigned long start_time;
    float dt;

    int etat_automate_depl = INITIALISATION;

    bool flag_available;

    Gladiator* gladiator;

    FuncType fnVitesse2(Position init, Position fini);
    float trajectoire(float time, FuncType velocityProfile);

    float calculatePID(float error, float dt, PIDCoef &pid);

public:
    Asservissement(Gladiator* gladiator);
    ~Asservissement();

    void handlePIDCoef(PIDCoef &pidGoTo, PIDCoef &pidRotation);
    
    void positionControl(Position targetPos);

    void setTargetPos(Position targetPos);

    Position getTargetPos(){
        return targetPos;
    }

    bool available(){
        return flag_available;
    }
};


#endif // ASSERVISSEMENT_H