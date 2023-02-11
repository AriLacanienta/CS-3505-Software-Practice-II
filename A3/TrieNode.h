/**
 * Trie Node implementation
 * Assignment 03: A Trie and Rule-of-Three
 * 
 * @file TrieNode.h
 * @author Ari Lacanienta
 * @date 2/11/2023
*/
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef NODE_H
#define NODE_H

class TrieNode
{
private:
    /// @brief Number of direct subnodes
    const static int ALPHA_LEN = 26;

    /// @brief Array of direct subnodes
    TrieNode** _nodes;

    /// @brief Designates this node as the end of the word.
    bool _isEndOfWord;
public:

    /// @brief An individual node of a Trie. Nodes can be chained recursively, with
    /// up to 26 subnodes each. Nodes are allocated on the heap.
    TrieNode();

    /// @brief An individual node of a Trie. Nodes can be chained recursively, with
    /// up to 26 subnodes each. Nodes are allocated on the heap.
    /// 
    ///This copy constructor performs a deep copy of other.
    ///@param other the TrieNode to be copied.
    TrieNode(const TrieNode& other);


    /// @brief Assign the value of other to this TrieNode
    /// @param other Source TrieNode
    TrieNode& operator=(TrieNode other);


    /// @brief Recursively deallocates memory for this TrieNode and all its subnodes.
    ~TrieNode();


    /// @brief Adds every character of word to the node using recursive subnodes.
    /// @param word The word to be added.
    /// @return True if the word was successfully added, False if the word already
    /// existed in subnodes. 
    bool addAWord(string word);

    
    /// @brief Check whether a word exisits in this node's subnodes.
    /// @param word The word to check.
    /// @return True if the word can be found by traversing subnodes. False otherwise.
    bool isAWord(string word);

    
    /// @brief Generates a list of words beginning with a given prefix.
    /// @param prefix source
    /// @return A vector containing every word found in this nodes subnodes that begins with the given prefix.
    vector<string> allWordsBeginningWithPrefix(string prefix);


    /// @brief Recursively prints out this node and its subnodes, showing at each step what it's subnodes are
    /// @param prefix 
    void printTrie();

};

#endif