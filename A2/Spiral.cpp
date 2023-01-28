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
    _currentAngle { abs(startingAngle) + 90 }, 
    _scalingFactor { scalingFactor } 
{
    _currentRadius = (_currentAngle * _scalingFactor);
};


/**
 * Increase the internal angle by a given degree amount
*/
Spiral& Spiral::operator+=(double angle){
    this->_currentAngle += angle;
    this->_currentRadius = _currentAngle * _scalingFactor;
    return *this;
};


/**
 * 
*/
double Spiral::getSpiralX() {
    return _centerX + -cos(_currentAngle * (M_PI/180)) * _currentRadius;
};


/**
 * 
*/
double Spiral::getSpiralY() {
    return _centerY + sin(_currentAngle * (M_PI/180)) * _currentRadius;
};


/**
 * 
*/
double Spiral::getSpiralAngle() {
    return this->_currentAngle;
};



