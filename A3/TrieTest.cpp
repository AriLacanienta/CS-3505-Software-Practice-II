///

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include "Trie.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;


void testRuleOfThree();

/// @brief 
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char const *argv[])
{
    // Command line I/O
    if (argc != 3){
        cerr << "Incorrect number of arguments passed" << endl;
        return 1;
    }

    ifstream source(argv[1]);
    if (!source.is_open()) {
        cerr << "Unable to open file: " << argv[1] << endl;
        return 2;
    }


    // Read dict into trie

    Trie dictionary;
    string line;
    while (getline(source, line)) {
        dictionary.addAWord(line);
    }

    source.close();

    // dictionary.printTrie("");

    // Query trie
    
    ifstream queries(argv[2]);
    if(!queries.is_open()){
        cerr << "Unable to open file: " << argv[2] << endl;
        return 2;
    }

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

    testRuleOfThree();

    return 0;
}

void testRuleOfThree() {
    const string TEST_PREFIX = "dist";
    const string TEST_WORD_1 = "distance";
    const string TEST_WORD_2 = "distant";

    Trie firstTrie;
    firstTrie.addAWord(TEST_WORD_1);
    firstTrie.addAWord(TEST_WORD_2);
    // cout << endl;
    // firstTrie.printTrie("");
    // cout << endl;

    // Test copy constructor
    Trie secondTrie(firstTrie);
    assert(secondTrie.isAWord(TEST_WORD_1));
    assert(secondTrie.isAWord(TEST_WORD_2));

    // secondTrie.printTrie("");
    // cout << endl;

    // return;

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
