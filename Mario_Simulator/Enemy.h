#ifndef ENEMY_H
#define ENEMY_H
#include "Mario.h"

using namespace std;

class Enemy {
public:
    Enemy();
    Enemy(int p);
    ~Enemy();
    bool fight(Mario& m);
    bool getTakeLife();
protected:
    //probability that the enemy will lose
    int probabilityLose;
    //true = goomba decreased a life from mario
    //false = goomb did not affect mario' lives
    bool takeLife;
};

#endif