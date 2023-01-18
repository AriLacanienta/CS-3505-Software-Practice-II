/**
 * CA.cpp
 * A1: 1D Cellular Automata
 * Author: Ari Lacanienta
 * 01/18/2023
 * 
 * INPUT: int 0-255 corresponding to the particular cellular automata ruleset
 * 
 * OUTPUT: writes 50 generations of that ruleset to the console window.
*/
#include <iostream>

const int GENERATION_SIZE = 10;
const int NUM_GENERATIONS = 50;

/**
 * Controls program flow
*/
int main() 
{
    void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int (&ruleSetArray)[8]);
    void displayGeneration(int generationToDisplay[], int length);
    void computeNextGeneration(int currentGeneration[], int nextGeneration[], int generationSize, int ruleSet[]);

    // Get input
    int ruleSetNumber;
    do
    {
        std::cout << "Enter a ruleset id [0-255]: ";
        std::cin >> ruleSetNumber; 
    } while (ruleSetNumber < 0 || ruleSetNumber > 255);
    
    // Convert ruleset
    int ruleSetArray[8];
    convertRuleSetNumberToRuleSetArray(ruleSetNumber, ruleSetArray);
    
    // Init gen-0
    int currentGeneration[GENERATION_SIZE];
    int midpoint = GENERATION_SIZE / 2;
    for (int i = 0; i < GENERATION_SIZE; i++)
    {
        if (i == midpoint)
            currentGeneration[i] = 1;
        else
            currentGeneration[i] = 0;
    }
    
    int* gen;
    gen = currentGeneration;
    for (int i = 0; i < NUM_GENERATIONS; i++)
    {
        std::cout << i << ":";
        displayGeneration(gen, GENERATION_SIZE);

        int nextGeneration[GENERATION_SIZE];
        computeNextGeneration(currentGeneration, nextGeneration, GENERATION_SIZE, ruleSetArray);
        gen = nextGeneration;
    }

    return 0;
};

/*
int* initializeFirstGeneration(){
    
};

int getRuleSetNumber() {
    
};
*/


void displayGeneration(int generationToDisplay[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if(generationToDisplay[i] == 1)
            std::cout << "#";
        else
            std::cout << " ";
    }
    
    std::cout << "\n";
}

/**
 * 
*/
void computeNextGeneration(int currentGeneration[], int nextGeneration[], int generationSize, int ruleSet[]) {

    int convertNeighborhoodToindex(int left, int center, int right);

    nextGeneration[0] = currentGeneration[0];
    nextGeneration[generationSize] = currentGeneration[generationSize];

    for (int i = 1; i < generationSize - 1; i++)
    {
        int ruleIndex = convertNeighborhoodToindex(currentGeneration[i-1], currentGeneration[i], currentGeneration[i+1]);
        nextGeneration[i] = ruleSet[ruleIndex];
    }
};


/**
 * 
*/
void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int (&ruleSetArray)[8]) 
{
    for (int i = 0; i < 8; i++)
    {
        if (ruleSetNumber % 2 == 0)
            ruleSetArray[i] = 0;
        else {
            ruleSetArray[i] = 1;
            ruleSetNumber--;
        }

        ruleSetNumber /= 2;
    }
};


/**
 * Given 3 nieghboring elements from the generation, returns the index of the
 * ruleSet that should be used to calcualte the next generation.
 * 
 * PARAM: left, center, right are expected to be int[0,1]
*/
int convertNeighborhoodToindex(int left, int center, int right) {
    return left * 4 + center * 2 + right * 1;
};



