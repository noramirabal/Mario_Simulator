#include "Mario.h"
#include <iostream>

//default constructor 
Mario::Mario(){
  numLives = 0;
  numCoins = 0;
  powerLevel = 0;
  iPosition = 0;
  jPosition = 0;
  killCount = 0;
  alive = true;
  sameLife = true;
}

//overloaded constructor
Mario::Mario(int l){
  numLives = l;
  numCoins = 0;
  powerLevel = 0;
  iPosition = 0;
  jPosition = 0;
  killCount = 0;
  alive = true;
  sameLife = true;
}

//default destructor
Mario::~Mario(){
}

//setters and getters
void Mario::setLives(int l){
  numLives = l;
}

int Mario::getLives(){
  return numLives;
}

void Mario::setCoins(int c){
  numCoins = c;
}

int Mario::getCoins(){
  return numCoins;
}

void Mario::setPowerLevel(int pl){
  powerLevel = pl;
}

int Mario::getPowerLevel(){
  return powerLevel;
}

void Mario::setiPosition(int i){
  iPosition = i;
}

int Mario::getiPosition(){
  return iPosition;
}

void Mario::setjPosition(int j){
  jPosition = j;
}

int Mario::getjPosition(){
  return jPosition;
}

bool Mario::getAlive(){
  return alive;
}

bool Mario::getSameLife(){
  return sameLife;
}

void Mario::setSameLife(bool torf){
  sameLife = torf;
}

void Mario::setKillCount(int kc){
  killCount = kc;
}

int Mario::getKillCount(){
  return killCount;
}

//adds a coin to Mario; if he already has 19 coins it 
//resets his coins to 0 and adds a life
void Mario::collectCoin(){
    if (numCoins < 19)
        ++numCoins; 
    else{
        gainLife(); 
        numCoins = 0;
    }
}

//adds a life to mario
void Mario::gainLife(){
    ++numLives;
}

//decreases a life from mario; if mario reaches 0 lives
//it changes mario's status to dead
void Mario::loseLife(){
  if (alive){
    --numLives;
    powerLevel = 0;
  }
  if (numLives == 0){
    alive = false;
  }
}

//adds a power level to mario unless he is already at
//the max power level
void Mario::gainPowerLevel(){
    if (powerLevel < 2)
      ++powerLevel;
}

//decreases a power level from mario unless his power level
//is at 0; if it is it decreases a life from mario
bool Mario::loseToEnemy(){
    if (powerLevel > 0){
      --powerLevel;
      return false;
    }
    else{
      loseLife();
      return true;
    }
}

//decreases marios power level by 2 only if he already has
//2 power levels; if he doesn't he loses a life
void Mario::loseToBoss(){
  if (powerLevel == 2)
    powerLevel = 0;
  else
    loseLife();
}

//adds 1 to mario's kill count
void Mario::addToKillCount(){
  ++killCount;
}






