#ifndef GAME_H
#define GAME_H
#include "Game.h"
#include "Enemy.h"
#include "Goomba.h"
#include "Koopa.h"
#include "World.h"
#include "Boss.h"
#include "Log.h"
#include <string>
using namespace std;

class Game{
public:
    Game();
    Game(int L, int N, int V, int CP, int NP, int GP, int KP, int MP, string logName);
    ~Game();
    void startingLevel(World& w, int dimension, Mario& m, Log& log);
    int nextPosition(Log& log);
    void marioMove(Level& l, Mario& m, int random, Log& log);
    char action(char c, Mario& m, Level& currentLevel, World& w, Log& log);
private:
    Level currentLevel;
    char item;
    char replaceChar;
    int nextMove;
    int totalMoves;
    bool marioWon;
};

#endif