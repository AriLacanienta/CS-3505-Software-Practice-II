/**
 * spiralPDF.cpp
 * Generates a .pdf with text in a spiral
 * 
 * A2: Classes, Facades, and Makefiles
 * Author: Ari Lacanienta
 * Date: 01/24/2023
 * 
 * INPUT: User-provided text (command line)
 * 
 * OUTPUT: spiralText.pdf
 * 
 * */
#include <string.h>
#include <math.h>
#include "HaruPDF.h"
#include "Spiral.h"

// DEBUG:
#include <iostream>

int main (int argc, char *argv[]) {    
    
    // name output pdf after program name
    char filename[256];
    strcpy(filename, argv[0]);
    strcat(filename, ".pdf");

    char inputText[256];
    strcpy(inputText, argv[1]);

    // DEBUG
    std::cout << inputText << std::endl;
    
    HaruPDF document(filename);;
    Spiral spiral(210, 300, 360, 0.225);

    // Place characters one at a time on the page.
    for (unsigned int i = 0; i < strlen (inputText); i++) {

        document.placeLetter(
            inputText[i],
            spiral.getSpiralX(), spiral.getSpiralY(), 
            (M_PI - spiral.getSpiralAngle() * (M_PI / 180)) - M_PI_2
            );


        double deltaAngle = 10;
        spiral += deltaAngle;
    }

    document.saveDocument();

    return 0;
}