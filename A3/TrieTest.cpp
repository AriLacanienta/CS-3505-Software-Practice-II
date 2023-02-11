///

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
        cout << line << dictionary.addAWord(line) << endl;
    }

    source.close();

    string str = " ";
    dictionary.printTrie("");

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


    // testRuleOfThree();

    return 0;
}

void testRuleOfThree() {

    Trie firstTrie;
    firstTrie.addAWord("distance");
    firstTrie.addAWord("distant");
    firstTrie.allWordsBeginningWithPrefix("dist");

    // Test copy constructor
    Trie secondTrie(firstTrie);
    secondTrie.allWordsBeginningWithPrefix("dist");

    // Test assignment operator
    Trie thirdTrie;
    thirdTrie.addAWord("distain");
    thirdTrie.allWordsBeginningWithPrefix("dist");
    
    thirdTrie = firstTrie;
    thirdTrie.allWordsBeginningWithPrefix("dist");

    // Prove deep copy
    firstTrie.addAWord("distorted");
    secondTrie.addAWord("distinguished");
    thirdTrie.addAWord("distributed");

    firstTrie.isAWord("distorted");
    secondTrie.isAWord("distorted");
    thirdTrie.isAWord("distorted");
}
