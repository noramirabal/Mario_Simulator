#include "FileProcessor.h"

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(int argc, char** argv){
    srand(time(NULL));
    FileProcessor inputFile(argv[1], argv[2]);
    return 0;
}