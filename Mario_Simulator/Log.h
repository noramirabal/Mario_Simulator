#ifndef LOG_H
#define LOG_H

#include <string>
using namespace std;

class Log{
public:
    Log();
    Log(string FileName);
    ~Log();
    //adds all of the entries to the output file 
    void addingText();
    void setLevelNum(string s);
    void setPositionLocationRow(string s);
    void setPositionLocationCol(string s);
    void setPowerLevelBeforeInteraction(string s);
    void setAction(string s);
    void setNumLivesAfterAction(string s);
    int getNumLivesAfterAction();
    void setNumCoinsAfterAction(string s);
    void setNextDirection(string s);
    void setNumTotalMoves(string s);
    void setGameEnd(string s);
    void setDisplayWorld(string s);
    void setDisplayLevel(string s);
    void individualLog();
    //formats each turn information
    void finalLog();
    void firstLog();
private:
    string fileName;
    string log;
    string levelNum;
    string powerLevelBeforeInteraction;
    string positionLocationRow;
    string positionLocationCol;
    string action;
    string numLivesAfterAction;
    string numCoinsAfterAction;
    string nextDirection;
    string displayLevel;
    string numTotalMoves;
    string gameEnd;   
    string displayWorld;
};

#endif