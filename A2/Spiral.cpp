/**
 * Spiral.cpp
 * A class to generate points in a spiral
 * 
 * A2: Classes, Facades, and Makefiles
 * Author: Ari Lacanienta
 * Date: 01/24/2023
*/
#include <math.h>
#include "Spiral.h"


/**
 * Provide angle in degrees clockwise from up.
*/
Spiral::Spiral(double centerX, double centerY, double startingAngle, double scalingFactor) 
    : _centerX { centerX }, 
    _centerY { centerY }, 
    _currentAngle { abs(startingAngle) * (M_PI / 180) }, 
    _scalingFactor { scalingFactor } 
{
    _currentRadius = 10.0;
};


/**
 * Increase the internal angle by a given degree amount
*/
Spiral& Spiral::operator+=(double angle){
    this->_currentAngle += angle  * (M_PI / 180);
    this->_currentRadius += _scalingFactor;
    return *this;
};


/**
 * 
*/
double Spiral::getSpiralX() {
    return _centerX + -cos(_currentAngle +  M_PI_2) * _currentRadius;
};


/**
 * 
*/
double Spiral::getSpiralY() {
    return _centerY + sin(_currentAngle + M_PI_2) * _currentRadius;
};


/**
 * 
*/
double Spiral::getSpiralAngle() {
    return this->_currentAngle;
};



