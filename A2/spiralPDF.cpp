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

int main (int argc, char *argv[]) {    
    
    // name output pdf after program name
    char filename[256];
    strcpy(filename, argv[0]);
    strcat(filename, ".pdf");

    char inputText[2048];
    strcpy(inputText, argv[1]);
    
    HaruPDF document(filename);;
    const double CENTER_X = 210;
    const double CENTER_Y = 300;
    Spiral spiral(CENTER_X, CENTER_Y, 360, 0.225);

    double deltaAngle;
    // Place characters one at a time on the page.
    for (unsigned int i = 0; i < strlen (inputText); i++) {

        /* Calculate the rotation of each letter by getting the complement of
            the angle, then convert it to Radians */
        document.placeLetter(
            inputText[i],
            spiral.getSpiralX(), spiral.getSpiralY(),
            (360 - spiral.getSpiralAngle() ) * (M_PI / 180)
            );

        // Limit deltaAngle based on how far we are from the center.
        double radius = sqrt(
            pow(spiral.getSpiralX() - CENTER_X, 2) + 
            pow(spiral.getSpiralY() - CENTER_Y, 2));
        
        if (radius <= 1e-4)
            radius = 1;
            
        deltaAngle = 1000/radius;
        spiral += deltaAngle;
    }

    document.saveDocument();

    return 0;
}