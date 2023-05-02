/*  Nora Mirabal
    Student ID: 2370638
    Student Email: mirabal@chapman.edu
    CPSC 350-02
    Assignment 2: Not So Super Mario Bros.

    - Ben Fellows
    - Student ID: 002369768
    - Student Email: bfellows@chapman.edu
    - CPSC 350-02
    - Assignment 2: Not So Super Mario Bros.
*/

#include "Boss.h"
#include "Mario.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Boss::Boss(){}

Boss::~Boss(){}

//simulates a fight between a boss and mario
//returns true if mario wins the fight, false if mario loses the fight
bool Boss::fight(Mario& m){
    bool marioWin = false; 
    int random = rand() % 2;
    //enters if mario wins 
    if (random == 0) 
        marioWin = true; 
    //enters if mario loses and decreases his power level by 2
    //or decreases a life
    else{ 
        m.loseToBoss(); 
    } 
    return marioWin; 
}