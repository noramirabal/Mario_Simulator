#ifndef WORLD_H
#define WORLD_H
#include "Level.h"

using namespace std;
#include <string>

class World {
public:
    World();
    World(int l, int d, int c, int n, int g, int k, int m);
    ~World();
    string displayW();
    int getNumLevels();
    Level getLevel(int i);
    int getCurrentLevelIndex();
    void setCurrentLevelIndex(int i);
private:
    //the current level that mario is on
    int currentLevelIndex;
    int numLevels;
    Level *worldArr;
};


#endif