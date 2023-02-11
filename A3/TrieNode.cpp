#include <cassert>
#include "TrieNode.h"

using std::cerr;
using std::cout;
using std::endl;

TrieNode::TrieNode() : _isEndOfWord{false}, _nodes{new TrieNode*[ALPHA_LEN]()}
{
}

TrieNode::TrieNode(const TrieNode& other){
    this->_isEndOfWord = other._isEndOfWord;
    this->_nodes = new TrieNode*[ALPHA_LEN]();

    for (int i = 0; i < ALPHA_LEN; i++)
    {
        if(other._nodes[i] != nullptr){
            this->_nodes[i] = new TrieNode(*other._nodes[i]);
            // cout << &this->_nodes[i] << " " << &other._nodes[i] << endl;
            
        }
    }
    
}

TrieNode& TrieNode::operator=(TrieNode other){
    std::swap(_isEndOfWord, other._isEndOfWord);
    std::swap(_nodes, other._nodes);
    return *this;
}

TrieNode::~TrieNode()
{
    for(int i = 0; i < ALPHA_LEN; i++){
        delete _nodes[i];
    }
    delete[] _nodes;
}


bool TrieNode::addAWord(string toAdd) {

    if(toAdd.empty()){
        if (_isEndOfWord)
            return false;
        else
            return _isEndOfWord = true;
    }

    int nextIndex = toAdd.front()-'a';
    if (_nodes[nextIndex] == nullptr){
        _nodes[nextIndex] = new TrieNode();
    }

    return _nodes[nextIndex]->addAWord(toAdd.substr(1));
}

bool TrieNode::isAWord(string word) {

    if (word.empty())
        return _isEndOfWord;

    int nextIndex = word.front()-'a';
    if (_nodes[nextIndex] == nullptr){
        return false;
    }

    return _nodes[nextIndex]->isAWord(word.substr(1));
}

vector<string> TrieNode::allWordsBeginningWithPrefix(string prefix){
    vector<string> foundWords;

    if(prefix.size() != 0){
        int nextIndex = prefix.front()-'a';
        if (_nodes[nextIndex] == nullptr)
            return foundWords;

        for(string word : _nodes[prefix.front()-'a']->allWordsBeginningWithPrefix(prefix.substr(1))){
            foundWords.push_back(prefix.front()+word);
        }
        return foundWords;
    } 
    
    if (_isEndOfWord)
        foundWords.push_back("");
 
    for (int i = 0; i < ALPHA_LEN; i++){
        if (_nodes[i] == nullptr)
            continue;
            
        for(string word : _nodes[i]->allWordsBeginningWithPrefix("")){
            foundWords.push_back((char)(i+'a') + word);
        }
    }
    return foundWords;
}

void TrieNode::altAllWordsAlgo(string prefix, vector<string>& foundWords) {
    if (_isEndOfWord)
        foundWords.push_back(prefix);

    for (int i = 0; i < ALPHA_LEN; i++){
        _nodes[i]->altAllWordsAlgo(prefix + (char)(i + 'a'), foundWords);
    }

}


void TrieNode::printTrie(string prefix){
    for (int i = 0; i < ALPHA_LEN; i++)
    if (_nodes[i] != nullptr) 
        cout << (char)(i+'a') << " " << i << " ";
    else 
        cout << "_ _ " ;
    cout << endl;

    for (int i = 0; i < ALPHA_LEN; i++)
        if (_nodes[i] != nullptr) 
            _nodes[i]->printTrie("");


    // for(int i = 0; i < 26; i++) {
    //     if (_nodes[i] != nullptr) {
    //         cout << prefix << (char)('a'+i) << " " << i << endl;
    //         _nodes[i]->printTrie(prefix + ".");
    //     }
    // }
    return;
}

/// @brief Attempts to traverse the trie by following edges indexed by letters 
/// in word. If the Node is partially traversed, the furthest child is returned
/// and word contains the remaining indexes (letters) that are not in the Node
/// @param word 
/// @return 
TrieNode* TrieNode::traverseTo(string& word){

    // base case 1: end of word
    if (word.empty()){
        return this;
    }

    // base case 2: end of Node
    int nextIndex = word.front()-'a';
    if (_nodes[nextIndex] == nullptr)
        return this;
    
    // recursive case
    word = word.substr(1);
    return _nodes[nextIndex]->traverseTo(word);
}


