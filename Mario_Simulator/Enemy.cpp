#include "Enemy.h"
#include <iostream>
#include <cstdlib>

//default constructor 
Enemy::Enemy(){
    probabilityLose = 0;
}

//overloaded constructor
Enemy::Enemy(int p){
    probabilityLose = p;
}

//default destructor
Enemy::~Enemy(){}

//getter
bool Enemy::getTakeLife(){
    return takeLife;
}

//simulates a fight between an enemy and mario
//returns true if mario wins the fight, false if mario loses the fight
bool Enemy::fight(Mario& m){
    int random = rand() % 100; 
    //enters if mario wins
    if (random < probabilityLose){
        //enters if mario wins while staying on the same life
        if (m.getSameLife()){
            //enters if mario already had a kill count of 6
            //resets kill count to 0 and adds a life to mario
            if (m.getKillCount() == 6){
                m.setKillCount(0);
                m.gainLife();
            //enters if mario had a kill count of less than 6   
            } else{
            m.addToKillCount(); 
            } 
        //enters if mario decreased in lives
        //adds 1 to his kill count
        } else{
            m.setSameLife(true);
            m.setKillCount(1);
        }
        return true; 
    //enters if the enemy won
    } else{ 
        //enters if the enemy took a life from mario
        if (m.loseToEnemy()){
            takeLife = true;
        }    
        return false;
    }
}
