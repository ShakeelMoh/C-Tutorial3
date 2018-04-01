#include <iostream>   //a system header file - needed to do simple I/O
#include <sstream>

using namespace std;

int main (int argc, char *argv[]) {

   String programName;
   String inputFile;
   String outputFile;
   
   inputFile = argv[1];
   outputFile = argv[2];
   
   cout << inputFile << outputFile;
   

   return 0;

}