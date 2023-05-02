#include "Log.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

Log::Log(){
    fileName = "";
    levelNum = "0";
    numLivesAfterAction = "0";
    positionLocationRow = "0";
    numCoinsAfterAction = "0";
    nextDirection = "";
    log = "";
}

Log::Log(string FileName){
    fileName = FileName;
    levelNum = "0";
    numLivesAfterAction = "0";
    positionLocationRow = "0";
    numCoinsAfterAction = "0";
    nextDirection = "";
    log = "THE GAME HAS COMMENCED! HAVE FUN! \n";
} 

Log::~Log(){}

//adds all of the log entries to the output files
void Log::addingText(){
    ofstream outputFile;
    outputFile.open(fileName);
    outputFile << log;
}

//setters and getters
void Log::setLevelNum(string s){
    levelNum = s;
}

void Log::setPositionLocationRow(string s){
    positionLocationRow = s;
}

void Log::setPositionLocationCol(string s){
    positionLocationCol = s;
}

void Log::setPowerLevelBeforeInteraction(string s){
    powerLevelBeforeInteraction = s;
}

void Log::setAction(string s){
    action = s;
}

void Log::setNumLivesAfterAction(string s){
    numLivesAfterAction = s;
}

int Log::getNumLivesAfterAction(){
    return stoi(numLivesAfterAction);
}

void Log::setNumCoinsAfterAction(string s){
    numCoinsAfterAction = s;
}

void Log::setNextDirection(string s){
    nextDirection = s;
}

void Log::setNumTotalMoves(string s){
    numTotalMoves = s;
}

void Log::setGameEnd(string s){
    gameEnd = s;
}

void Log::setDisplayWorld(string s){
    displayWorld = s;
}

void Log::setDisplayLevel(string s){
    displayLevel = s;
}


//formates and adds each turn's information to the log string
void Log::individualLog(){
    log += "Level number: " + levelNum + "\n" +
    "Mario's position location: " + positionLocationRow + "," + positionLocationCol + "\n" +
    "Mario's power level before interaction: PL" + powerLevelBeforeInteraction + "\n" + 
    "Action that took place: " + action + "\n" +
    "Mario's lives after action"  + ": " + numLivesAfterAction + "\n" +
    "Mario's coins after action" + ": " + numCoinsAfterAction + "\n" +
    "Mario's next move: " + nextDirection + "\n" + 
    "Current Level:" + "\n" + displayLevel + "\n";
}

void Log::finalLog(){
    log += "Total number of moves: " + numTotalMoves + "\n" + gameEnd;
}

void Log::firstLog(){
    log += displayWorld;
}

