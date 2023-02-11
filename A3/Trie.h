#include <string>
#include <vector>
#include <iostream>
#include "Node.h"

using std::string;
using std::vector;
using std::ostream;

#ifndef TRIE_H
#define TRIE_H
class Trie
{
private:
    Node _head;
public:
    Trie();
    bool addAWord(string word);
    bool isAWord(string word);
    vector<string> allWordsBeginningWithPrefix(string prefix);
private:
    bool validateInput(string input);
};
#endif