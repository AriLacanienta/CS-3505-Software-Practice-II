/**
 * Cat.cpp
 * Lab02
 * Author: Ari Lacanienta
 * 01/18/2023
 * 
*/
#include <iostream>

/**
 * Meow
*/
class Cat
{
private:
    int lives;
public:
    Cat() : lives{20} { }

    void reportLives()
    {
        std::cout << "This cat has " << lives << " lives." << std::endl;
    };

    void loseLife()
    {
        lives--;
    };

    Cat& operator+=(int toAdd)
    {
        lives += toAdd;
        return *this;
    };
};

int main() 
{
    Cat mycat;
    mycat.reportLives();
    mycat.loseLife();
    mycat.reportLives();
    mycat += 1;
    mycat.reportLives();
    (mycat += 1) += 3;
    mycat.reportLives();
}
