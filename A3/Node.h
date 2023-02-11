#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::ostream;

#ifndef NODE_H
#define NODE_H

class Node
{
private:
    const static int ALPHA_LEN = 26;
    bool _isEndOfWord;
    Node** _nodes; 
public:
    Node();
    Node(const Node& other);
    Node& operator=(Node other);
    ~Node();
    bool addAWord(string word);
    bool isAWord(string word);
    vector<string> allWordsBeginningWithPrefix(string prefix);
    void printTrie(string ws);
private:
    vector<string> recurseAllWordsBeginningWithPrefix(string prefix);
    Node* traverseTo(string& word);
};

#endif