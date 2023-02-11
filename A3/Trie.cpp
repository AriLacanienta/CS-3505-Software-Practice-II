#include "Trie.h"


Trie::Trie() :_head{TrieNode()} {

}

bool Trie::addAWord(string word){
    return _head.addAWord(word);
}

bool Trie::isAWord(string word) {
    if (!validateInput(word))
        return false;

    return _head.isAWord(word);
}

vector<string> Trie::allWordsBeginningWithPrefix(string prefix) {
    vector<string> foundWords;
    if(!validateInput(prefix))
        return foundWords;
    return _head.allWordsBeginningWithPrefix(prefix);
}

/// @brief Validates whether input text consists of lowercase letters a-z
/// @param input the text to validate
/// @return True iff every character in input is a lowercase letter a-z
bool Trie::validateInput(string input){
    for (auto character : input) {
        if (character - 'a' < 0
        || character - 'z' > 0)
            return false;
    }
    return true;
}
