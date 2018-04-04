//.h file

#ifndef _HUFFMAN
#define _HUFFMAN

#include<vector>
#include <unordered_map>
#include <queue>
#include <memory>

using namespace std;

class HuffmanNode{
   
   private:
      int frequency;
      char charLetter;
      
      shared_ptr<HuffmanNode> left;
      shared_ptr<HuffmanNode> right;
      

   public:
      HuffmanNode(int freq, char letter, shared_ptr<HuffmanNode> l, shared_ptr<HuffmanNode> r);
      void getContents();
      int getFrequency() const;
      char getLetter();
      void addToVector();
      shared_ptr<HuffmanNode> getLeftNode();
      shared_ptr<HuffmanNode> getRightNode();
      
      
      
};

namespace MHMSHA056{

   void countLetters(unordered_map<char, int> &letterFreq, string inputFile);

   struct Comp{
      bool operator() (const HuffmanNode &a, const HuffmanNode &b);
   };
   
};

class HuffmanTree{

   private:
   
   public:
      HuffmanNode buildTree(priority_queue<HuffmanNode, vector<HuffmanNode>, MHMSHA056::Comp>& pq);
      void buildCodeTable(HuffmanNode root);

};








#endif