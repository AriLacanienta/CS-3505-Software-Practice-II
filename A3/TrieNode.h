#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::ostream;

#ifndef NODE_H
#define NODE_H

class TrieNode
{
private:
    const static int ALPHA_LEN = 26;
    bool _isEndOfWord;
    TrieNode** _nodes; 
public:
    TrieNode();
    TrieNode(const TrieNode& other);
    TrieNode& operator=(TrieNode other);
    ~TrieNode();
    bool addAWord(string word);
    bool isAWord(string word);
    vector<string> allWordsBeginningWithPrefix(string prefix);
    void altAllWordsAlgo(string prefix, vector<string> &foundWords);
    void printTrie(string ws);
    TrieNode* traverseTo(string& word);
private:
};

#endif