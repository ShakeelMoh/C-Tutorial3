#include <iostream>   //a system header file - needed to do simple I/O
#include <sstream>
#include <string>
#include <memory>
#include <queue>
#include <cstddef>
#include "Huffman.h"


using namespace std;

/*
struct Comp{
   bool operator()(const HuffmanNode &a, const HuffmanNode &b){
      if (a.getFrequency() < b.getFrequency()){
         return true;
      } else {
         return false;
      }
   }
};
*/

int main (int argc, char *argv[]) {

   string programName;
   string inputFile;
   string outputFile;
   
   inputFile = argv[1];
   outputFile = argv[2];
   
   unordered_map<char, int> letterFrequency { //unordered map of letter and its frequency
      {'a', 0},{'b', 0},{'c', 0},{'d', 0},{'e', 0},{'f', 0},{'g', 0},{'h', 0}, {'i', 0},
      {'j', 0},{'k', 0}, {'l', 0},{'m', 0},{'n', 0}, {'o', 0},{'p', 0},{'q', 0},{'r', 0},
      {'s', 0},{'t', 0},{'u', 0}, {'v', 0},{'w', 0},{'x', 0}, {'y', 0}, {'z', 0}, {' ', 0}
   
   };
   
   vector<shared_ptr<HuffmanNode>> nodes; //stores all 26 nodes
   priority_queue<HuffmanNode, vector<HuffmanNode>, MHMSHA056::Comp> pq;

   MHMSHA056::countLetters(letterFrequency, inputFile);
   //cout << "MAIN METHOD SAYS " << letterFrequency['a'];


   //Create nodes for each letter
   for (auto it = letterFrequency.begin(); it != letterFrequency.end(); ++it){
      
      char letter = it -> first;
      
      int frequency = it -> second;

      //Create node for each letter
      if (frequency > 0){
         shared_ptr<HuffmanNode> node(new HuffmanNode(frequency, letter, nullptr, nullptr));
         nodes.push_back(node); //add node to vector
         //cout << "Pushing node onto queue" << "\n";
         //node->HuffmanNode::getContents();
      
         //Add to priority queue
         pq.push(*node);
      }
      
      

   }
   
   //Print out priority queue
   
   /*
   while (!pq.empty()){
      cout << pq.top().HuffmanNode::getFrequency() << "\n";
      pq.pop();

   }
   */
   
   //Build the tree...
   
   HuffmanTree tree;
   
   HuffmanNode finalNode = tree.HuffmanTree::buildTree(pq);
   cout << "\nFinal Node Contents:" << "\n";
   finalNode.HuffmanNode::getContents();
   
   //finalNode.HuffmanNode::getLeftNode();
   //finalNode.HuffmanNode::getRightNode();

   tree.HuffmanTree::buildCodeTable(finalNode, pq);
   
   return 0;

}




