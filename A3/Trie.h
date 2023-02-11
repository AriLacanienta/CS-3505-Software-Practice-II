/**
 * Trie wrapper class
 * Assignment 03: A Trie and Rule-of-Three
 * 
 * @file Trie.h
 * @author Ari Lacanienta
 * @date 2/11/2023
*/
#include <string>
#include <vector>
#include "TrieNode.h"

using std::string;
using std::vector;

#ifndef TRIE_H
#define TRIE_H
class Trie
{
private:

    /// @brief Wherenode to start indexing from.
    /// The head node does not have an associated letter.
    TrieNode _head;

public:

    /// @brief This Trie can store words consisting only of lowercase letters a-z.
    /// This is accomplished by indexing subnodes in alphabetical order, recursively.
    Trie();

    
    /// @brief Adds a word to the Trie.
    /// word should consist of lowercase letters a-z.
    /// @param word The word to be added.
    /// @return True if the word was successfully added to the Trie, False otherwise.
    bool addAWord(string word);


    /// @brief Checks whether the given word exists in the Trie. 
    /// Word should only consist of lowercase letters a-z.
    /// @param word The word to check.
    /// @return True iff the word exists in the Trie.
    bool isAWord(string word);


    /// @brief Generates a list of words in the Trie that begin with a given prefix.
    /// Prefix should only consist of lowercase letters a-z.
    /// @param prefix The prefix of words to be found.
    /// @return All words stored in the Trie that begin with the given prefix.
    vector<string> allWordsBeginningWithPrefix(string prefix);

private:

    /// @brief Validates whether input text consists of lowercase letters a-z
    /// @param input the text to validate
    /// @return True iff every character in input is a lowercase letter a-z
    bool validateInput(string input);
};
#endif