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
    : _centerX { centerX }, 
    _centerY { centerY }, 
    _currentAngle { std::abs(startingAngle) }, // Enforce minimum starting radius (angle?) to preserve the look of the text
    _scalingFactor { scalingFactor } 
{

};


/**
 * Increase the internal angle by a given amount
*/
Spiral& Spiral::operator+=(double angle){
    this->_currentAngle += angle;
    this->_currentRadius += 1/angle;
    return *this;
};


/**
 * 
*/
double Spiral::getSpiralX() {
    return _centerX + cos(_currentAngle) * _currentRadius;
};


/**
 * 
*/
double Spiral::getSpiralY() {
    return _centerY + sin(_currentAngle) * _currentRadius;
};


/**
 * 
*/
double Spiral::getSpiralAngle() {
    return this->_currentAngle;
};



