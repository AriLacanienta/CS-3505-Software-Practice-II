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
    const static int ALPHA_LEN = 26;
    bool _isEndOfWord;
    Trie** _nodes; 
public:
    Trie();
    Trie(const Trie& other);
    Trie(string toAdd);
    ~Trie();
    bool addAWord(string toAdd);
    bool isAWord(string toCheck);
    vector<string> allWordsBeginningWithPrefix(string toCheck);
    Trie& operator=(Trie other);
    void printTrie(string ws);
private:
    Trie* traverseTo(string& word);
};

#endif