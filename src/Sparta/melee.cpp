#include "melee.h"

void SpartanMode(Gladiator *gladiator, Position ally_position){
    uint8_t team = gladiator->robot->getData().teamId;
    Position current = gladiator->robot->getData().position;
    float dx = current.x - ally_position.x;
    float dy = current.y - ally_position.y;

    float distance = sqrt(dx*dx + dy*dy);

    if(distance < ATTACK_DISTANCE){

    }
    else{
        gladiator->control->setWheelSpeed(WheelAxis::LEFT, 1);
        gladiator->control->setWheelSpeed(WheelAxis::RIGHT, -1);
    }
}