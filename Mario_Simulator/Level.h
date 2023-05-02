#ifndef LEVEL_H
#define LEVEL_H
#include <string>
using namespace std;

class Level {
public:
    Level(int d, int c, int n, int g, int k, int m);
    Level();
    ~Level();
    int getDimension();
    char randomChar();
    string display();
    //returns the item in the array
    char checkItem(int i, int j);
    //changes the array position to H
    void makeH(int i, int j);
    //changes the array position to the char passed in
    void makeChar(int i, int j, char c);
    //populates warp pipes
    void warpPipe();
private:
    int dimension;
    int totalArrayPositions;
    int coinProb;
    int nothingProb;
    int goombaProb;
    int koopaProb;
    int mushroomProb;
    char *levelArr;
};

#endif
