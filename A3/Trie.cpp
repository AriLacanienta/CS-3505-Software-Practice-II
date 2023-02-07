#include <string>
#include <vector>
#include <iostream>

using std::cerr;
using std::endl;
using std::string;
using std::vector;

class Trie
{
private:
    /* data */
public:
    Trie();
    ~Trie();
    bool addAWord(std::string toAdd);
    bool isAWord(std::string toCheck);
    std::vector<std::string> allWordsBeginningWithPrefix(std::string);
};

Trie::Trie()
{
}

Trie::~Trie()
{
}

bool addAWord(string toAdd) {
    cerr << "Not implemented" << endl;
    return false;
}

bool isAWord(std::string toCheck) {
    cerr << "Not implemented" << endl;
    return false;
}

vector<string> Trie::allWordsBeginningWithPrefix(string){
    cerr << "Not implemented" << endl;
    vector<string> results;
    return results;
}

