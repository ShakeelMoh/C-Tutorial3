//.h file

#ifndef _HUFFMAN
#define _HUFFMAN

#include<vector>
#include <unordered_map>
#include <queue>

using namespace std;

class HuffmanNode{
   
   private:
      int frequency;
      char charLetter;
      
      HuffmanNode *left;
      HuffmanNode *right;
      

   public:
      HuffmanNode(int freq, char letter, HuffmanNode * l, HuffmanNode * r);
      void getContents();
      int getFrequency() const;
      char getLetter();
      void addToVector();
      
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
      void buildTree(priority_queue<HuffmanNode, vector<HuffmanNode>, MHMSHA056::Comp>& pq);
      

};








#endif