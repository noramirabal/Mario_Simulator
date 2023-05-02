#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include "Game.h"
#include <string>
#include <fstream>
using namespace std;

class FileProcessor {
public:
    FileProcessor();
    FileProcessor(string inputFileName, string outputFileName);
    ~FileProcessor();
    int getL();
    int getN();
    int getV();
    int getCP();
    int getNP();
    int getGP();
    int getKP();
    int getMP();
private:
    int L;
    int N;
    int V;
    int CP;
    int NP;
    int GP;
    int KP;
    int MP;
};

#endif