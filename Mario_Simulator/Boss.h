#ifndef BOSS_H
#define BOSS_H
#include "Mario.h"

class Boss {
public:
    Boss();
    ~Boss();
    bool fight(Mario& m);
};

#endif