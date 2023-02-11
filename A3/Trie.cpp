#include <cassert>
#include "Trie.h"

using std::cerr;
using std::cout;
using std::endl;

Trie::Trie() : _isEndOfWord{false}, _nodes{new Trie*[ALPHA_LEN]()}
{
}

Trie::~Trie()
{
    delete[] _nodes;
}


bool Trie::addAWord(string toAdd) {

    if(toAdd.empty()){
        if (_isEndOfWord)
            return false;
        else
            return _isEndOfWord = true;
    }

    int nextIndex = toAdd.front()-'a';
    if (_nodes[nextIndex] == nullptr){
        _nodes[nextIndex] = new Trie();
    }

    return _nodes[nextIndex]->addAWord(toAdd.substr(1));
}

bool Trie::isAWord(string word) {

    if (word.empty())
        return _isEndOfWord;

    int nextIndex = word.front()-'a';
    if (_nodes[nextIndex] == nullptr){
        return false;
    }

    return _nodes[nextIndex]->isAWord(word.substr(1));
}

vector<string> Trie::allWordsBeginningWithPrefix(string prefix){
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


void Trie::printTrie(string prefix){
    for(int i = 0; i < 26; i++) {
        if (_nodes[i] != nullptr) {
            cout << prefix << (char)('a'+i) << " " << i << endl;
            _nodes[i]->printTrie(prefix + ".");
        }
    }
    return;
}

/// @brief Attempts to traverse the trie by following edges indexed by letters 
/// in word. If the Trie is partially traversed, the furthest child is returned
/// and word contains the remaining indexes (letters) that are not in the Trie
/// @param word 
/// @return 
Trie* Trie::traverseTo(string& word){

    // base case 1: end of word
    if (word.empty()){
        return this;
    }

    // base case 2: end of Trie
    int nextIndex = word.front()-'a';
    if (_nodes[nextIndex] == nullptr)
        return this;
    
    // recursive case
    word = word.substr(1);
    return _nodes[nextIndex]->traverseTo(word);
}


