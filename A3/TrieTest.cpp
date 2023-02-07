///

#include <fstream>
#include <iostream>
#include <string>
#include "Trie.cpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;


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

    

    return 0;
}
