#include "Level.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



Level::Level(){
    dimension = 0;
    totalArrayPositions = dimension*dimension;
    coinProb = 0;
    nothingProb = 0;
    goombaProb = 0;
    koopaProb = 0;
    mushroomProb = 0;
    } 

Level::Level(int d, int c, int n, int g, int k, int m){
    dimension = d;
    totalArrayPositions = dimension*dimension;
    coinProb = c;
    nothingProb = n;
    goombaProb = g;
    koopaProb = k;
    mushroomProb = m;
    //initializes a char array with coins, nothing,
    //goombas, koopas, or mushrooms
    levelArr = new char[totalArrayPositions];
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            levelArr[i * dimension + j] = randomChar();
        }
    }
    //overrides a level position and makes it a boss
    int random = rand() % dimension;
    int random2 = rand() % dimension;
    levelArr[random * dimension + random2] = 'b';
}


Level::~Level(){
}


int Level::getDimension(){
  return dimension;
}

//outputs either a coin, nothing, goomba, koopa, or mushroom character
//based on probability passed in through the defaul constructor
char Level::randomChar(){
    int nothingPositions = nothingProb + coinProb;
    int goombaPositions = goombaProb + nothingPositions;
    int koopaPositions = koopaProb + goombaPositions;
    int mushroomPositions = mushroomProb + koopaPositions;

    int random = rand() % 100; //range 0-total positions in the array
    if (random < coinProb){
        return 'c';
    } else if (random < nothingPositions){
        return 'x';
    } else if (random < goombaPositions){
        return 'g';
    } else if (random < koopaPositions){
        return 'k';
    } else if (random < mushroomPositions){
        return 'm';
    }
}

//creates a string of the level 
string Level::display(){
    string levelArrString;
    for(int i =0; i < dimension; i++){
        for (int j = 0 ; j < dimension; j++){
            levelArrString += levelArr[i * dimension + j];
        }
    levelArrString += "\n"; 
    }
    levelArrString += "\n";
    return levelArrString;
}

char Level::checkItem(int i, int j){
    return levelArr[i * dimension + j];
}

void Level::makeH(int i, int j){
    levelArr[i * dimension + j] = 'H';
}

void Level::makeChar(int i, int j, char c){
    levelArr[i * dimension + j] = c;
}

//populates each level except for the last with a warp pipe
//maks sure not to override the boss in each level
void Level::warpPipe(){
    int random = rand() % dimension;
    int random2 = rand() % dimension;
    if (levelArr[random * dimension + random2] != 'b'){
        levelArr[random * dimension + random2] = 'W';
    } else{
        warpPipe();
    }
}

