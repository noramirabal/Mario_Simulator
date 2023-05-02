#include "World.h"
#include <iostream>
using namespace std;

World::World(){
    currentLevelIndex = 0;
    numLevels = 0;
    worldArr = new Level[numLevels];
}

//takes in all of the file processor information
//creates an array of levels
World::World(int l, int d, int c, int n, int g, int k, int m){
    currentLevelIndex = 0;
    numLevels = l;
    worldArr = new Level[numLevels];
    for (int i = 0; i < l; i++){
        worldArr[i] = Level(d, c, n, g, k, m);
    } for (int i = 0; i < l-1; i++){
        worldArr[i].warpPipe();
    }
}

World::~World(){
    if (worldArr != NULL){
        delete[] worldArr;
    }
}


int World::getNumLevels(){
    return numLevels;
}

//outputs a string of world
string World::displayW(){
    string worldArrString;
    for (int i = 0; i < numLevels; i++){
        worldArrString += worldArr[i].display();
    }
    return worldArrString;
}

//getters and setters
Level World::getLevel(int i){
    return worldArr[i];
}

int World::getCurrentLevelIndex(){
    return currentLevelIndex;
}

void World::setCurrentLevelIndex(int i){
    currentLevelIndex = i;
}


