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
 * Creates a new Spiral object. The Spiral tracks its position in degrees 
 * clockwise from up. (i.e. 0 degrees is 12:00, 90 degress is 3:00).
*/
Spiral::Spiral(double centerX, double centerY, double startingAngle, double scalingFactor) 
    : _centerX { centerX }, 
    _centerY { centerY }, 
    _currentAngle { abs(startingAngle) }, 
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
 * Gets the relative x coordinate of the spiral based on the current angle
*/
double Spiral::getSpiralX() {
    return _centerX + sin(_currentAngle * (M_PI/180)) * _currentRadius;
};


/**
 * Gets the relative y coordinate of the spiral based on the current angle
*/
double Spiral::getSpiralY() {
    return _centerY + cos(_currentAngle * (M_PI/180)) * _currentRadius;
};


/**
 * Gets the current angle of the Spiral.
*/
double Spiral::getSpiralAngle() {
    return this->_currentAngle;
};



