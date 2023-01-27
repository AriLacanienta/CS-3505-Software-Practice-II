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

    std::cout << inputText << std::endl;

    float angle2;
    float rad1;
    float rad2;
    unsigned int i;

    const char* SAMP_TXT = "The quick brown fox jumps over the lazy dog. We need more text to test a spiral. Maybe the radians needs to increase with smaller radius. ";
    
    HaruPDF document(filename);;
    Spiral spiral(210, 300, 90, 2.0);

    /* text along a circle */
    angle2 = 180;

    int deltaAngle = 25;


    // Place characters one at a time on the page.
    for (i = 0; i < strlen (inputText); i++) {

        double ang = spiral.getSpiralAngle() * (180 / M_PI);

        document.placeLetter(inputText[i], spiral.getSpiralX(), spiral.getSpiralY(), -spiral.getSpiralAngle() + M_PI_2);

        angle2 -= 10.0; // change the angle around the circle
        spiral += deltaAngle;
        // deltaAngle -= 1;

    }

        document.saveDocument();

    return 0;
}