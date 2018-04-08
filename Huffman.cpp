// Implements Huffman.h

#include <iostream>
#include "Huffman.h"
#include <fstream> //For reading/writing textfile
#include <vector>
#include <queue>
#include <memory>
#include <unordered_map>
#include <algorithm>

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
shared_ptr<HuffmanNode> HuffmanNode::getL(){
   return left;
}
shared_ptr<HuffmanNode> HuffmanNode::getR(){
   return right;
}
//Returns right node
shared_ptr<HuffmanNode> HuffmanNode::getRightNode(){
   cout << "Right node contents is " << "\n";
   right->HuffmanNode::getContents();
   return right;
}
//Builds code table
void HuffmanTree::buildCodeTable(HuffmanNode root){
   cout << "Building code table" << "\n" << "\n";
   
   //left.HuffmanNode::getLeftNode();
   cout << "PRINTING ALL LEAF NODES" << "\n";
   HuffmanTree::printLeafNodes(root);
   

}

//Level is how deep recursion process is
void HuffmanTree::printLeafNodes(HuffmanNode root){
   level++;
   //if node is leaf node, print its data
   if (!root.HuffmanNode::getL() && !root.HuffmanNode::getR()){
      cout << "\nLeaf node data" << "\n";
      root.HuffmanNode::getContents();
      cout << code << "\n";
      letters.push_back(root.HuffmanNode::getLetter());
      codes.push_back(code);
      code = code.substr(0, code.size()-1);
      level--;
      return;
   }
   //if left child exists check recursively
   if (root.HuffmanNode::getL()){
      code = code + "0";
      HuffmanTree::printLeafNodes(*root.HuffmanNode::getL());
      
   }
   //if right child exists check recursively
   if (root.HuffmanNode::getR()){
      code = code + "1";
      HuffmanTree::printLeafNodes(*root.HuffmanNode::getR());
   }
   code = code.substr(0, code.size()-1);
}

void HuffmanTree::printCodeTable(string outputFile){
   cout << "\n\nPRINTING CODE TABLE TO TEXT FILE\n";
   ofstream output;
   output.open(outputFile + ".hdr");
   output << "Count " << letters.size() << "\n";
   for (int i = 0; i < letters.size(); i++){
      
      output << letters[i] << " = ";
      output << codes[i] << "\n";
      //cout << "Letter: " << letters[i] << "\n";
      //cout << "Code: " << codes[i] << "\n";
   }
   
}

void HuffmanTree::outputCompressedFile(string outputFile, string inputFile){
   cout << "\nCOMPRESSING TEXT FILE TO " << outputFile << "\n"; 
   
   ifstream inFile; //get txt file
   inFile.open(inputFile);
   
   if (!inFile){ //while next line
      cerr << "Unable to open file";       
   }
   
   ofstream output;
   output.open(outputFile);
   
   string line;

   while(getline(inFile, line)){
   //cout << "Current line is " << line;
      char currentLetter; //current letter
      
      for(int i = 0; i < line.length(); ++i)
      {
         currentLetter = line[i]; // select one letter/number at a time from string line.
         int pos = distance(letters.begin(), std::find(letters.begin(), letters.end(), currentLetter));
         output << codes[pos];
      }
   }
   
   
}

HuffmanNode HuffmanTree::buildTree(priority_queue<HuffmanNode, vector<HuffmanNode>, MHMSHA056::Comp>& pq){
   cout << "Building tree" << "\n";

   while (pq.size() > 1){
   
      HuffmanNode node1 = pq.top();
      shared_ptr<HuffmanNode> node1Ptr;
      if (node1.getL() || node1.getR()){
         cout << "Created node with children!" << "\n";
         node1.HuffmanNode::getContents();
         shared_ptr<HuffmanNode> node1Ptr1 (new HuffmanNode(node1.HuffmanNode::getFrequency(), node1.HuffmanNode::getLetter(), node1.getLeftNode(), node1.getRightNode()));
          node1Ptr = node1Ptr1;
         cout << "\n";
      } else {
         cout << "Creating brand new node..." << "\n";
         shared_ptr<HuffmanNode> node1Ptr1 (new HuffmanNode(node1.HuffmanNode::getFrequency(), node1.HuffmanNode::getLetter(), nullptr, nullptr));
         node1Ptr = node1Ptr1;
      }
   
      //shared_ptr<HuffmanNode> node1Ptr(new HuffmanNode(node1.HuffmanNode::getFrequency(), node1.HuffmanNode::getLetter(), nullptr, nullptr));
      //node1Ptr->HuffmanNode::getContents();
      //HuffmanNode * node1Ptr = node1;
      pq.pop();
      HuffmanNode node2 = pq.top();
      
      shared_ptr<HuffmanNode> node2Ptr;
      if (node2.getL() || node2.getR()){
         cout << "Created node with children!" << "\n";
         node2.HuffmanNode::getContents();
         shared_ptr<HuffmanNode> node2Ptr2 (new HuffmanNode(node2.HuffmanNode::getFrequency(), node2.HuffmanNode::getLetter(), node2.getLeftNode(), node2.getRightNode()));
          node2Ptr = node2Ptr2;
         cout << "\n";
      } else {
         cout << "Creating brand new node..." << "\n";
         shared_ptr<HuffmanNode> node2Ptr2 (new HuffmanNode(node2.HuffmanNode::getFrequency(), node2.HuffmanNode::getLetter(), nullptr, nullptr));
         node2Ptr = node2Ptr2;
      }
      /*
      if (node2.getL() == nullptr){
         cout << "We have a null ptr here 2!" << "\n";
         node2.HuffmanNode::getContents();
      } else {
         cout << "Created node with children!";
         node1.HuffmanNode::getContents();
         cout << "\n";
      }
      */
      //shared_ptr<HuffmanNode> node2Ptr(new HuffmanNode(node2.HuffmanNode::getFrequency(), node2.HuffmanNode::getLetter(), nullptr, nullptr));
      
      //node2Ptr->HuffmanNode::getContents();
      //HuffmanNode * node2Ptr = node2
      pq.pop();
      int freq1 = node1.HuffmanNode::getFrequency();
      int freq2 = node2.HuffmanNode::getFrequency();
      int sum = freq1 + freq2;      //cout << sum << " is the sum";
      
      //Create parent node and give it its children. Smaller node on left
      if (freq1 <= freq2){
         shared_ptr<HuffmanNode> newNode(new HuffmanNode(sum, ' ', node1Ptr, node2Ptr));
         /*
         if (newNode->HuffmanNode::getLeftNode()){
            cout << "Combined node left contents" << "\n";
            newNode->HuffmanNode::getLeftNode();
         }
         */
         //cout << "Created node with sum and children " << "\n";
         //cout << "Sum: " << newNode->getFrequency() << "\n";
         //node1Ptr->getContents();
         //node2Ptr->getContents();
         pq.push(*newNode);
      } else {
         shared_ptr<HuffmanNode> newNode(new HuffmanNode(sum, ' ', node2Ptr, node1Ptr));
         /*
         if (newNode->HuffmanNode::getLeftNode()){
            cout << "Combined node left contents" << "\n";
            newNode->HuffmanNode::getLeftNode();
         }
         */
         //cout << "Created node with children " << "\n";
         //cout << newNode->getFrequency();
         //node1Ptr->getContents();
         //node2Ptr->getContents();
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
   
   //cout << "CHECKING ROOT LEFT NODES\n";
   //shared_ptr<HuffmanNode> leftN = finalNode.HuffmanNode::getLeftNode();
   //leftN->getLeftNode();
   
   //Tree recusion must be done here else all pointers go out of scope
  
   
   return finalNode;
}