/**
 * Trie wrapper class
 * Assignment 03: A Trie and Rule-of-Three
 * 
 * @file Trie.cpp
 * @author Ari Lacanienta
 * @date 2/11/2023
*/
#include "Trie.h"

/// @brief This Trie can store words consisting only of lowercase letters a-z.
/// This is accomplished by indexing subnodes in alphabetical order, recursively.
Trie::Trie() 
:_head{TrieNode()} 
{
    // Intentionally blank
}


/// @brief Adds a word to the Trie.
/// word should consist of lowercase letters a-z.
/// @param word The word to be added.
/// @return True if the word was successfully added to the Trie, False otherwise.
bool Trie::addAWord(string word) {
    return _head.addAWord(word);
}


/// @brief Checks whether the given word exists in the Trie. 
/// Word should only consist of lowercase letters a-z.
/// @param word The word to check.
/// @return True iff the word exists in the Trie.
bool Trie::isAWord(string word) {
    if (!validateInput(word))
        return false;

    return _head.isAWord(word);
}


/// @brief Generates a list of words in the Trie that begin with a given prefix.
/// Prefix should only consist of lowercase letters a-z.
/// @param prefix The prefix of words to be found.
/// @return All words stored in the Trie that begin with the given prefix.
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
