/**
 * Trie Node implementation
 * Assignment 03: A Trie and Rule-of-Three
 * 
 * @file TrieNode.cpp
 * @author Ari Lacanienta
 * @date 2/11/2023
*/
#include <iostream>
#include "TrieNode.h"

using std::cout;
using std::endl;

/// @brief An individual node of a Trie. Nodes can be chained recursively, with
/// up to 26 subnodes each. Nodes are allocated on the heap.
TrieNode::TrieNode() 
: _isEndOfWord{false},
  _nodes{new TrieNode*[ALPHA_LEN]()}
{
    // Intentionally blank
}


/// @brief An individual node of a Trie. Nodes can be chained recursively, with
/// up to 26 subnodes each. Nodes are allocated on the heap.
/// This copy constructor performs a deep copy of `other`.
///@param other the TrieNode to be copied.
TrieNode::TrieNode(const TrieNode& other) 
: _isEndOfWord{other._isEndOfWord},
  _nodes{new TrieNode*[ALPHA_LEN]()} 
{
    for (int i = 0; i < ALPHA_LEN; i++)
    {
        if(other._nodes[i] != nullptr)
            this->_nodes[i] = new TrieNode(*other._nodes[i]);
    }
}


/// @brief Assign the value of other to this TrieNode
/// @param other Source TrieNode
TrieNode& TrieNode::operator=(TrieNode other) {
    std::swap(_isEndOfWord, other._isEndOfWord);
    std::swap(_nodes, other._nodes);
    return *this;
}


/// @brief Recursively deallocates memory for this TrieNode and all its subnodes.
TrieNode::~TrieNode() {
    for(int i = 0; i < ALPHA_LEN; i++){
        delete _nodes[i];
    }
    delete[] _nodes;
}


/// @brief Adds every character of word to the node using recursive subnodes.
/// @param word The word to be added.
/// @return True if the word was successfully added, False if the word already
/// existed in subnodes. 
bool TrieNode::addAWord(string word) {

    if(word.empty()) {
        if (_isEndOfWord)
            return false;
        else
            return _isEndOfWord = true;
    }

    int nextIndex = word.front()-'a';
    if (_nodes[nextIndex] == nullptr) {
        _nodes[nextIndex] = new TrieNode();
    }

    return _nodes[nextIndex]->addAWord(word.substr(1));
}


/// @brief Check whether a word exisits in this node's subnodes.
/// @param word The word to check.
/// @return True if the word can be found by traversing subnodes. False otherwise.
bool TrieNode::isAWord(string word) {

    if (word.empty())
        return _isEndOfWord;

    int nextIndex = word.front()-'a';
    if (_nodes[nextIndex] == nullptr){
        return false;
    }

    return _nodes[nextIndex]->isAWord(word.substr(1));
}


/// @brief Generates a list of words beginning with a given prefix.
/// @param prefix source
/// @return A vector containing every word found in this nodes subnodes that begins with the given prefix.
vector<string> TrieNode::allWordsBeginningWithPrefix(string prefix) {

    vector<string> foundWords;
    if(prefix.size() > 0) {

        int nextIndex = prefix.front()-'a';
        if (_nodes[nextIndex] == nullptr)
            return foundWords;

        for(string word : _nodes[prefix.front()-'a']->allWordsBeginningWithPrefix(prefix.substr(1)))
            foundWords.push_back(prefix.front()+word);

        return foundWords;
    } 
    
    if (_isEndOfWord) {
        foundWords.push_back("");
    }

    for (int i = 0; i < ALPHA_LEN; i++){
        if (_nodes[i] == nullptr)
            continue;
            
        for(string word : _nodes[i]->allWordsBeginningWithPrefix(""))
            foundWords.push_back((char)(i+'a') + word);
    }

    return foundWords;
}


/// @brief Recursively prints out this node and its subnodes, showing at each step what it's subnodes are
/// @param prefix 
void TrieNode::printTrie(){
    for (int i = 0; i < ALPHA_LEN; i++)
    if (_nodes[i] != nullptr) 
        cout << (char)(i+'a') << " " << i << " ";
    else 
        cout << "_ _ " ;
    cout << endl;

    for (int i = 0; i < ALPHA_LEN; i++)
        if (_nodes[i] != nullptr) 
            _nodes[i]->printTrie();
    return;
}


