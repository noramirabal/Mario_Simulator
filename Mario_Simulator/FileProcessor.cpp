#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//default constructor
FileProcessor::FileProcessor(){
    L = 0;
    N = 0;
    V = 0;
    CP = 0;
    NP = 0;
    GP = 0;
    KP = 0;
    MP = 0;
}

FileProcessor::FileProcessor(string inputFileName, string outputFileName){
    //creates temporary strings to hold the file values
    string sL;
    string sN;
    string sV;
    string sCP;
    string sNP;
    string sGP;
    string sKP;
    string sMP;
    //opens the file and stores the information in the temporary strings
    fstream inputFile;
    inputFile.open(inputFileName, ios::in);
    if (inputFile.is_open()){
        getline(inputFile, sL, '\n'); //reading in the line and storing it as a string
        getline(inputFile, sN, '\n');
        getline(inputFile, sV, '\n');
        getline(inputFile, sCP, '\n');
        getline(inputFile, sNP, '\n');
        getline(inputFile, sGP, '\n');
        getline(inputFile, sKP, '\n');
        getline(inputFile, sMP, '\n');
    }
    inputFile.close();
    //turns all of the temp strings into integers
    L = stoi(sL); 
    N = stoi(sN);
    V = stoi(sV);
    CP = stoi(sCP);
    NP = stoi(sNP);
    GP = stoi(sGP);
    KP = stoi(sKP);
    MP = stoi(sMP);

    //initializes a game (passes through the log file name)
    Game game(L, N, V, CP, NP, GP, KP, MP, outputFileName);
}


FileProcessor::~FileProcessor(){}

//getters
int FileProcessor::getL(){
    return L;
}

int FileProcessor::getN(){
    return N;
}

int FileProcessor::getV(){
    return V;
}

int FileProcessor::getCP(){
    return CP;
}

int FileProcessor::getNP(){
    return NP;
}

int FileProcessor::getGP(){
    return GP;
}

int FileProcessor::getKP(){
    return KP;
}

int FileProcessor::getMP(){
    return MP;
}
