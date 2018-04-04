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
HuffmanNode::HuffmanNode(int freq, char letter, shared_ptr<HuffmanNode> l, shared_ptr<HuffmanNode> r){

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

   cout << "Contents of node is " << charLetter << ": " << frequency << "\n";

}

int HuffmanNode::getFrequency() const{
   return frequency;
}

char HuffmanNode::getLetter(){
   return charLetter;
}

//Returns left node
shared_ptr<HuffmanNode> HuffmanNode::getLeftNode(){
   cout << "Left node contents is " << "\n";
   left->HuffmanNode::getContents();
   return left;
}
//Returns right node
shared_ptr<HuffmanNode> HuffmanNode::getRightNode(){
   cout << "Right node contents is " << "\n";
   right->HuffmanNode::getContents();
   return right;
}
//Builds code table
void HuffmanTree::buildCodeTable(HuffmanNode root){
   cout << "Building code table";

}


HuffmanNode HuffmanTree::buildTree(priority_queue<HuffmanNode, vector<HuffmanNode>, MHMSHA056::Comp>& pq){
   cout << "Building tree" << "\n";

   while (pq.size() > 1){
   
      HuffmanNode node1 = pq.top();
      shared_ptr<HuffmanNode> node1Ptr(new HuffmanNode(node1.HuffmanNode::getFrequency(), node1.HuffmanNode::getLetter(), nullptr, nullptr));
      //HuffmanNode * node1Ptr = node1;
      pq.pop();
      HuffmanNode node2 = pq.top();
      shared_ptr<HuffmanNode> node2Ptr(new HuffmanNode(node2.HuffmanNode::getFrequency(), node2.HuffmanNode::getLetter(), nullptr, nullptr));
      //HuffmanNode * node2Ptr = node2
      pq.pop();
      int freq1 = node1.HuffmanNode::getFrequency();
      int freq2 = node2.HuffmanNode::getFrequency();
      int sum = freq1 + freq2;      //cout << sum << " is the sum";
      
      //Create parent node and give it its children. Smaller node on left
      if (freq1 <= freq2){
         shared_ptr<HuffmanNode> newNode(new HuffmanNode(sum, ' ', node1Ptr, node2Ptr));
         cout << "Created node with sum and children " << "\n";
         cout << "Sum: " << newNode->getFrequency() << "\n";
         node1Ptr->getContents();
         node2Ptr->getContents();
         pq.push(*newNode);
      } else {
         shared_ptr<HuffmanNode> newNode(new HuffmanNode(sum, ' ', node2Ptr, node1Ptr));
         cout << "Created node with children " << "\n";
         cout << newNode->getFrequency();
         node1Ptr->getContents();
         node2Ptr->getContents();
         pq.push(*newNode);
      }
      
      //cout << "sum of contents is \n";
      //newNode->HuffmanNode::getContents();
      
      /*
      cout << "Node 1:";
      node1.HuffmanNode::getContents();
      cout << "\nNode 2";
      node2.HuffmanNode::getContents();
      cout << "\n";
      */
      
      
   }
   HuffmanNode finalNode = pq.top();
   //finalNode.HuffmanNode::getContents();
   return finalNode;
}