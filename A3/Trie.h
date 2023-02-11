#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::ostream;

#ifndef TRIE_H
#define TRIE_H

class Trie
{
private:
    /* data */
    const static int ALPHA_LEN = 26;
    bool _isEndOfWord;
    Trie** _nodes; 
public:
    Trie();
    Trie(string toAdd);
    ~Trie();
    bool addAWord(string toAdd);
    bool isAWord(string toCheck);
    vector<string> allWordsBeginningWithPrefix(string toCheck);
    void printTrie(string ws);
private:
    Trie* traverseTo(string& word);
};

#endif