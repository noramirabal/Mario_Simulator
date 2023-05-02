#include "Game.h"
#include <iostream>

using namespace std;


Game::Game(){
    char item = ' ';
    char replaceChar = ' ';
    int nextMove = 0;
    int totalMoves = 0;
    bool marioWon = false;
}

//runs through the game until mario loses or wins
Game::Game(int L, int N, int V, int CP, int NP, int GP, int KP, int MP, string logName){
    marioWon = false;
    Log log(logName);
    totalMoves = 0;
    World world(L, N, CP, NP, GP, KP, MP);
    log.setDisplayWorld(world.displayW());
    log.firstLog();
    world.displayW();
    Mario mario(V);
    //sets mario's lives to the user's file input value
    log.setNumLivesAfterAction(to_string(V));
    //starts the game
    startingLevel(world, N, mario, log);
    //loops while mario is alive and mario has not won
    while ((mario.getAlive()) && (!marioWon)){
        //enters if the array spot mario is on is neither a boss, koopa, or goomba
        if (replaceChar != 'b' && replaceChar != 'K' && replaceChar != 'G' ){
            //replaces the character on the array position Mario left with the relpacement character
            currentLevel.makeChar(mario.getiPosition(), mario.getjPosition(), replaceChar); 
            //moves mario to the next direction
            marioMove(currentLevel, mario, nextMove, log);
            //stores the item type of the position mario is going to move into to
            item = currentLevel.checkItem(mario.getiPosition(), mario.getjPosition()); 
            //changes that array positio to H to indicate mario 
            currentLevel.makeChar(mario.getiPosition(), mario.getjPosition(), 'H');
        }
        //interacting with the item originally in the spot mario is occuping
        //and stores the variable to replace the array with when mario moves
        replaceChar = action(item, mario, currentLevel, world, log); 
        //enters if the number of mario's lives changed during his interaction with the item
        //changes mario's same life value to false
        if (mario.getLives() != log.getNumLivesAfterAction()){
            mario.setSameLife(false);
        }
        log.setNumLivesAfterAction(to_string(mario.getLives()));
        log.setNumCoinsAfterAction(to_string(mario.getCoins()));
        //enters if the character to replace marios position is not indicated
        //sets mario's next position as stay put
        if (replaceChar == 'b' || replaceChar == 'G' || replaceChar == 'K'){
            log.setNextDirection("Stay put");
        //enters if the character to replace marios position is not a warp pipe or boss\
        //sets mario's next position as random
        } if (replaceChar == 'W' || replaceChar == 'B'){
            log.setNextDirection("Random");
        //sets mario's next position as either 0,1,2,3
        } else{
            nextMove = nextPosition(log); //storing marios next move
        }
        ++totalMoves;
        log.setDisplayLevel(currentLevel.display());
        log.individualLog();
        if (replaceChar == 'W' || replaceChar == 'B'){
            if (world.getCurrentLevelIndex() == world.getNumLevels()){
                marioWon = true;
                log.setGameEnd("MARIO WON THE GAME!!!");
            //enters if mario isn't on the same level
            } else{
                currentLevel = world.getLevel(world.getCurrentLevelIndex());
                log.setLevelNum(to_string(world.getCurrentLevelIndex()+1));
                startingLevel(world, N, mario, log);
            }
        }
    }
    log.setNumTotalMoves(to_string(totalMoves));
    //declares wether at the end of the game if mario lost or won
    if (!marioWon){
        log.setGameEnd("Mario lost :(");
    }
    log.finalLog();
    log.addingText();
}

//default destructor
Game::~Game(){
}

//method for mario's first turn in a level
void Game::startingLevel(World& w, int dimension, Mario& m, Log& log){
    //gives mario a random position on the array
    int randomRow = rand() % dimension; 
    int randomCol = rand() % dimension; 
    log.setPositionLocationRow(to_string(randomRow));
    log.setPositionLocationCol(to_string(randomCol));
    //sets the current level for mario on the level he is in
    currentLevel = w.getLevel(w.getCurrentLevelIndex());
    log.setLevelNum(to_string(w.getCurrentLevelIndex()+1));
    //holds the item on the array that mario is going to be on
    item = currentLevel.checkItem(randomRow, randomCol);
    m.setiPosition(randomRow);
    m.setjPosition(randomCol);
    //makes the array position H for mario
    currentLevel.makeH(randomRow, randomCol);
    //does the action of the original item where mario is now on
    replaceChar = action(item, m, currentLevel, w, log);
    //enters if the number of mario's lives changed during his interaction with the item
    //changes mario's same life value to false
    if (m.getLives() != log.getNumLivesAfterAction()){
        m.setSameLife(false);
    }
    log.setNumLivesAfterAction(to_string(m.getLives()));
    log.setNumCoinsAfterAction(to_string(m.getCoins()));
    if (replaceChar == 'b' || replaceChar == 'G' || replaceChar == 'K'){
        log.setNextDirection("Stay put");
        log.setDisplayLevel(currentLevel.display());
        log.individualLog();
    //adds an index level if mario landed on a warp pipe or a boss and won
    } if (replaceChar == 'W' || replaceChar == 'B'){
            log.setNextDirection("Random");
            log.setDisplayLevel(currentLevel.display());
            log.individualLog();
            currentLevel = w.getLevel(w.getCurrentLevelIndex());
            log.setLevelNum(to_string(w.getCurrentLevelIndex()+1));
            startingLevel(w, dimension, m, log);
    } else{
        nextMove = nextPosition(log); //storing marios next move
        log.setDisplayLevel(currentLevel.display());
        log.individualLog();
    }
    ++totalMoves;
}

//returns a random int between 0-3
//to indicate his next movement
int Game::nextPosition(Log& log){
    int random = rand() % 4;
    if (random == 0){
        log.setNextDirection("Up");
    } if (random == 1 ){
        log.setNextDirection("Down");
    } if (random == 2){
        log.setNextDirection("Left");
    } if (random == 3 ){
        log.setNextDirection("Right");
    }
    return random;
}

//moves mario in his new direction
//wraps around the array vertically and horizontally
void Game::marioMove(Level& l, Mario& m, int random, Log& log){
    int i = m.getiPosition();
    int j = m.getjPosition();
    if (random == 0){ //go up
        if (i == 0){
            m.setiPosition(l.getDimension()-1);
        } else{
            m.setiPosition(i-1);
        }
        log.setPositionLocationRow(to_string(m.getiPosition()));
    } 
    if (random == 1){ //go down
        if (i == l.getDimension()-1){
            m.setiPosition(0);
        } else{
            m.setiPosition(i+1);
        }
        log.setPositionLocationRow(to_string(m.getiPosition()));
    } 
    if (random == 2 ){ //go left
        if (j == 0){
            m.setjPosition(l.getDimension()-1);
        } else{
            m.setjPosition(j-1);
        }
        log.setPositionLocationCol(to_string(m.getjPosition()));
    } 
    if (random == 3){ //go right
        if (j == l.getDimension()-1){
            m.setjPosition(0);
        } else{
            m.setjPosition(j+1);
        }
        log.setPositionLocationCol(to_string(m.getjPosition()));
    }
}

//does the action between mario and the char in the array position he is on
//returns the char that will replace mario when he moves out of his  position
char Game::action(char c, Mario& m, Level& currentLevel, World& w, Log& log){ 
    log.setPowerLevelBeforeInteraction(to_string(m.getPowerLevel()));
    if (c == 'c'){
        m.collectCoin();
        log.setAction("Mario collected a coin");
        return 'x';
    } if (c == 'x'){
        log.setAction("Mario landed on an empty space");
        return 'x';
    } if (c == 'm'){
        m.gainPowerLevel();
        log.setAction("Mario found a mushroom and gained a power level");
        return 'x';
    } if (c == 'g' || c == 'G'){
        Goomba g;
        //enters if mario wins the fight against the goomba
        if (g.fight(m)){
            log.setAction("Mario faught a goomba and won");
            return 'x';
        //enters if mario loses the fight against the goomba
        } else{
            //enters if mario loses a life during the fight
            if (g.getTakeLife()){
                log.setAction("Mario faught a goomba and lost a life");
                return 'G';
            //enters if mario doesn't lose a life
            } else{
                log.setAction("Mario faught a goomba and lost");
                return 'g';
            }
        }
    } if (c == 'k' || c == 'K'){
        Koopa k;
        //enters if mario wins the fight against the koopa
        if (k.fight(m)){
            log.setAction("Mario faught a koopa and won");
            return 'x';
        //enters if mario loses the fight against the koopa
        } else{
            //enters if mario loses a life during the fight
            if (k.getTakeLife()){
                log.setAction("Mario faught a koopa and lost a life");
                return 'K';
            //enters if mario doesn't lose a life
            } else{
                log.setAction("Mario faught a koopa and lost");
                return 'g';
            }
        }
    } if (c == 'b'|| c == 'B'){
        Boss b;
        //enters if wins against the boss
        if (b.fight(m)){
            //increases marios level index 1
            w.setCurrentLevelIndex(w.getCurrentLevelIndex() +1);
            log.setAction("Mario faught a boss and won");
            return 'B';
        //enters if mario loses against the boss
        } else{
            log.setAction("Mario faught a boss and lost");
            return 'b';
        }
    } if (c == 'W'){
        //increases marios level index by 1
        w.setCurrentLevelIndex(w.getCurrentLevelIndex() +1);
        log.setAction("Mario found a warp pipe");
        return 'W';
    }
}

