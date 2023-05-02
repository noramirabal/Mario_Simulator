#ifndef KOOPA_H
#define KOOPA_H
#include "Enemy.h"

using namespace std;
//child class of Enemy
class Koopa: public Enemy{
public:
    Koopa(); 
    ~Koopa();
};

#endif