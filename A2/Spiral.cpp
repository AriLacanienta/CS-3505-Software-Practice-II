/**
 * Spiral.cpp
 * A class to generate points in a spiral
 * 
 * A2: Classes, Facades, and Makefiles
 * Author: Ari Lacanienta
 * Date: 01/24/2023
*/
#include <stdlib.h>
#include <math.h>
#include "Spiral.h"


Spiral::Spiral(double centerX, double centerY, double startingAngle, double scalingFactor) 
    : centerX { centerX }, 
    centerY { centerY }, 
    currentAngle { std::abs(startingAngle) }, // Enforce minimum starting radius (angle?) to preserve the look of the text
    scalingFactor { scalingFactor } 
{

};


/**
 * Increase the internal angle by a given amount
*/
Spiral& Spiral::operator+=(double angle){
    this->currentAngle += angle;
    this->currentRadius += 1/angle;
    return *this;
};


/**
 * 
*/
double Spiral::getSpiralX() {
    return centerX + cos(currentAngle) * currentRadius;
};


/**
 * 
*/
double Spiral::getSpiralY() {
    return centerY + sin(currentAngle) * currentRadius;
};


/**
 * 
*/
double Spiral::getSpiralAngle() {
    return this->currentAngle;
};



