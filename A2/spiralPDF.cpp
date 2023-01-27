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
    Spiral spiral(0, 0, 0, 5.0);

    /* text along a circle */
    angle2 = 180;

    // Place characters one at a time on the page.
    for (i = 0; i < strlen (SAMP_TXT); i++) {
        float x;
        float y;
        // rad1 determines the angle of the letter on the page. rad2 is how far
        // around the circle you are. Notice that they are perpendicular and
        // thus not independent.
        //
        // Pay careful attention to what wants radians and what is degrees
        // between haru and spiral and math functions.
        rad1 = (angle2 - 90) / 180 * 3.141592;
        rad2 = angle2 / 180 * 3.141592;

        // The position of the character depends on the center point
        // plus the angle and the radius.
        x = 210 + cos(rad2) * (-10)*rad2;
        y = 300 + sin(rad2) * (-10)*rad2;

        document.placeLetter(SAMP_TXT[i], spiral.getSpiralX(), spiral.getSpiralY(), rad1);

        angle2 -= 10.0; // change the angle around the circle
        spiral += 1.0;

    }
        document.saveDocument();

    return 0;
}