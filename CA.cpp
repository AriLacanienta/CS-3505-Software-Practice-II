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

const int GENERATION_SIZE = 64;
const int NUM_GENERATIONS = 50;

/**
 * Controls program flow
*/
int main() 
{
    void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int ruleSetArray[8]);
    void displayGeneration(int generationToDisplay[], int length);
    void computeNextGeneration(int currentGeneration[], int nextGeneration[], int generationSize, int ruleSet[]);

    // Get input
    int ruleSetNumber;
    std::cout << "Enter a ruleset id [0-255]: ";
    std::cin >> ruleSetNumber; 
    
    if (ruleSetNumber < 0 || ruleSetNumber > 255)
    {
        std::cout << ruleSetNumber << " Is out of bounds [0-255]";
        return 0;
    }
    
    // Convert ruleset
    int ruleSetArray[8];
    convertRuleSetNumberToRuleSetArray(ruleSetNumber, ruleSetArray);
    
    // Initial generation
    int currentGeneration[GENERATION_SIZE];
    int midpoint = GENERATION_SIZE / 2;
    for (int i = 0; i < GENERATION_SIZE; i++)
    {
        if (i == midpoint)
            currentGeneration[i] = 1;
        else
            currentGeneration[i] = 0;
    }

    // Acitve loop - generates each generation
    for (int i = 0; i < NUM_GENERATIONS; i++)
    {
        displayGeneration(currentGeneration, GENERATION_SIZE);

        int nextGeneration[GENERATION_SIZE];
        computeNextGeneration(currentGeneration, nextGeneration, GENERATION_SIZE, ruleSetArray);
        
        for (int i = 0; i < GENERATION_SIZE; i++)
        {
            currentGeneration[i] = nextGeneration[i];
        }
    }

    return 0;
};


/**
 * Converts a decimal number to it's 8-bit binary representation, and stores the
 * digits in ruleSetArray.
 * 
 * INPUT: ruleSetNumber
 * 
 * OUTPUT: ruleSetArray
*/
void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int ruleSetArray[8]) 
{
    // Evaluates one binary place-value at a time by repeatedly halving
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
 * Pretty-prints one generation of the CA
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
 * Computes the nex CA generation based on provided ruleSet.
 * 
 * INPUT: currentGeneration[], generationSize, ruleSet[]
 * 
 * OUTPUT: nextGeneration[]
*/
void computeNextGeneration(int currentGeneration[], int nextGeneration[], int generationSize, int ruleSet[]) {

    int convertNeighborhoodToindex(int left, int center, int right);

    // Copy edges down
    nextGeneration[0] = currentGeneration[0];
    nextGeneration[generationSize-1] = currentGeneration[generationSize-1];

    for (int i = 1; i < generationSize - 1; i++)
    {
        // Consult the ruleset
        int ruleIndex = convertNeighborhoodToindex(currentGeneration[i-1], currentGeneration[i], currentGeneration[i+1]);
        nextGeneration[i] = ruleSet[ruleIndex];
    }
};


/**
 * Given 3 nieghboring elements from the generation, returns the index of the
 * ruleSet that should be used to calcualte the next generation.
 * 
 * INPUT: left, center, right are expected to be int[0,1]
 * 
 * OUTPUT: int[0,7]
*/
int convertNeighborhoodToindex(int left, int center, int right) {
    return left * 4 + center * 2 + right * 1;
};



