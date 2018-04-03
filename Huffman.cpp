// Implements Huffman.h

#include <iostream>
#include "Huffman.h"
#include <fstream> //For reading/writing textfile
#include <vector>
#include <queue>
#include <memory>
#include <unordered_map>

using namespace std;

//Count occurences of letter
void MHMSHA056::countLetters(unordered_map<char, int> &letterFreq, string inputFile){

   //cout << "Count letters method executing for file " << inputFile << "\n";

   string alphabet = "abcdefghijklmnopqrstuvwxyz";

   ifstream inFile; //get txt file
   inFile.open(inputFile);
   
   if (!inFile){ //while next line
         cerr << "Unable to open file";       
      }
   
   
   
   string line;

   while(getline(inFile, line)){
   //cout << "Current line is " << line;
      char currentLetter; //current letter
      
      for(int i = 0; i < line.length(); ++i)
      {
         currentLetter = line[i]; // select one letter/number at a time from string line.
         //cout << "Current letter is " << currentLetter << "\n";
         ++letterFreq[currentLetter];
         //cout << "current letter is " << currentLetter;
      }
   }
   //letterFreq['a'] = 5;
   //cout << letterFreq['a'] << " is a's...";

}


//Constructor
HuffmanNode::HuffmanNode(int freq, char letter, HuffmanNode * l, HuffmanNode * r){

   frequency = freq;
   charLetter = letter;
   left = l;
   right = r;

}

bool MHMSHA056::Comp::operator()(const HuffmanNode &a, const HuffmanNode &b){
   if (a.getFrequency() > b.getFrequency()){
      return true;
   } else {
      return false;
      }
}



//toString for node
void HuffmanNode::getContents(){

   cout << "Contents of node is " << charLetter << " : " << frequency << "\n";

}

int HuffmanNode::getFrequency() const{
   return frequency;
}

char HuffmanNode::getLetter(){
   return charLetter;
}

void HuffmanTree::buildTree(priority_queue<HuffmanNode, vector<HuffmanNode>, MHMSHA056::Comp>& pq){
   cout << "Building tree";

   while (pq.size() > 1){
   
      HuffmanNode node1 = pq.top();
      pq.pop();
      HuffmanNode node2 = pq.top();
      pq.pop();
      //shared_ptr<HuffmanNode> newNode(new HuffmanNode(node1.HuffmanNode::getFrequency() + node2.HuffmanNode::getFrequency(),node1, node2);
      /*
      cout << "Node 1:";
      node1.HuffmanNode::getContents();
      cout << "\nNode 2";
      node2.HuffmanNode::getContents();
      cout << "\n";
      */
}
}