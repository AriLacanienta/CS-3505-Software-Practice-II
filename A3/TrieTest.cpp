/**
 * Testing file for Trie.cpp
 * Assignment 03: A Trie and Rule-of-Three
 * 
 * @file TrieTest.cpp
 * @author Ari Lacanienta
 * @date 2/11/2023
*/
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include "Trie.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

int buildTrie(string sourceFilename, Trie& dictionary);
int queryTrie(string queryFilename, Trie& dictionary);
void testRuleOfThree();

/// @brief Runs various tests against the Trie class.
int main(int argc, char const *argv[])
{
    // Command line I/O
    if (argc != 3){
        cerr << "Incorrect number of arguments passed" << endl;
        return 1;
    }

    // Read source words into trie
    Trie dictionary;
    int returnCode = buildTrie(argv[1], dictionary);
    if (returnCode != 0)
        return returnCode;

    // Query trie  
    returnCode = queryTrie(argv[2], dictionary);
    if (returnCode != 0)
        return returnCode;

    testRuleOfThree();

}

/// @brief Attempts to open sourceFilename, and then adds every word in the file to the Trie.
/// @param sourceFilename source file
/// @param trie destination Trie
/// @return 0 if successful, 2 if file can't be opened.
int buildTrie(string sourceFilename, Trie& trie) {
    ifstream source(sourceFilename);
    if (!source.is_open()) {
        cerr << "Unable to open file: " << sourceFilename << endl;
        return 2;
    }

    string line;
    while (getline(source, line)) {
        trie.addAWord(line);
    }
    source.close();
    return 0;
}


/// @brief Attempts to open queryFilename, and then queries the trie for every word in the file.
/// @param queryFilename query source file
/// @param trie Trie to query
/// @return 0 if successful, 2 if file can't be opened.
int queryTrie(string queryFilename, Trie& dictionary) {
    ifstream queries(queryFilename);
    if(!queries.is_open()){
        cerr << "Unable to open file: " << queryFilename << endl;
        return 2;
    }

    string line;
    while (getline(queries, line)) {
        cout << "Testing " << line << ":" << endl;
        
        if (dictionary.isAWord(line))
            cout << "Found" << endl;
        else
            cout << "Not found" << endl;

        for (auto result : dictionary.allWordsBeginningWithPrefix(line))
            cout << result << " ";
        cout << endl;
    }
    queries.close();
    return 0;
}


/// @brief Tests a Trie's rule of three implementation by copying and modifying a few small tries.
void testRuleOfThree() {
    const string TEST_PREFIX = "dist";
    const string TEST_WORD_1 = "distance";
    const string TEST_WORD_2 = "distant";

    Trie firstTrie;
    firstTrie.addAWord(TEST_WORD_1);
    firstTrie.addAWord(TEST_WORD_2);

    // Test copy constructor
    Trie secondTrie(firstTrie);
    assert(secondTrie.isAWord(TEST_WORD_1));
    assert(secondTrie.isAWord(TEST_WORD_2));


    // Test assignment operator
    Trie thirdTrie;
    thirdTrie.addAWord("distain");
    assert(!thirdTrie.isAWord(TEST_WORD_1));
    assert(!thirdTrie.isAWord(TEST_WORD_2));
    assert(thirdTrie.isAWord("distain"));
    
    
    thirdTrie = firstTrie;
    assert(thirdTrie.isAWord(TEST_WORD_1));
    assert(thirdTrie.isAWord(TEST_WORD_2));
    assert(!thirdTrie.isAWord("distain"));

    // Prove deep copy
    const string T1_UNIQ = "distorted";
    const string T2_UNIQ = "distinguished";
    const string T3_UNIQ = "distributed";
    firstTrie.addAWord(T1_UNIQ);
    secondTrie.addAWord(T2_UNIQ);
    thirdTrie.addAWord(T3_UNIQ);

    assert(firstTrie.isAWord(T1_UNIQ));
    assert(!firstTrie.isAWord(T2_UNIQ));
    assert(!firstTrie.isAWord(T3_UNIQ));

    assert(!secondTrie.isAWord(T1_UNIQ));
    assert(secondTrie.isAWord(T2_UNIQ));
    assert(!secondTrie.isAWord(T3_UNIQ));

    assert(!thirdTrie.isAWord(T1_UNIQ));
    assert(!thirdTrie.isAWord(T2_UNIQ));
    assert(thirdTrie.isAWord(T3_UNIQ));
}
