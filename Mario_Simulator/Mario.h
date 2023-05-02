#ifndef MARIO_H
#define MARIO_H
#include "Mario.h"

class Mario {
public:
    Mario();
    Mario(int l);
    ~Mario();
    void setLives(int l);
    int getLives();
    void setCoins(int c);
    int getCoins();
    void setPowerLevel(int pl);
    int getPowerLevel();
    void setiPosition(int i);
    int getiPosition();
    void setjPosition(int j);
    int getjPosition();
    bool getAlive();
    bool getSameLife();
    void setSameLife(bool torf);
    void setKillCount(int kc);
    int getKillCount();
    void collectCoin();
    void gainLife();
    void loseLife();
    void gainPowerLevel();
    bool loseToEnemy();
    void loseToBoss();
    void addToKillCount();
private:
    int numLives;
    int numCoins;
    int powerLevel;
    int iPosition;
    int jPosition;
    //number of regular enemies killed
    int killCount;
    //true = alive, false = dead
    bool alive;
    //true = on the same life, false = decreased a life
    bool sameLife;
};

#endif