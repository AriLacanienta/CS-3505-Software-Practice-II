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

// DEBUG
#include <iostream>

class Spiral
{
private:
    double centerX, centerY, currentAngle, scalingFactor;
    double currentRadius;
public:
    Spiral(double centerX, double centerY, double startingAngle, double scalingFactor) 
    : centerX { centerX }, 
    centerY { centerY }, 
    currentAngle { std::abs(startingAngle) }, // Enforce minimum starting radius (angle?) to preserve the look of the text
    scalingFactor { scalingFactor } 
    {

    };


    /**
     * Increase the internal angle by a given amount
    */
    Spiral& operator+=(double angle){
        this->currentAngle += angle;
        this->currentRadius += 1/angle;
        return *this;
    };


    /**
     * 
    */
    double getSpiralX() {
        return centerX + cos(currentAngle) * currentRadius;
    };


    /**
     * 
    */
    double getSpiralY() {
        return centerY + sin(currentAngle) * currentRadius;
    };


    /**
     * 
    */
    double getSpiralAngle() {
        return this->currentAngle;
    };



};


//DEBUG
int main() {
    Spiral s1(0,0,0,0);
    for (int i = 0; i < 100; i++)
    {
        s1 += 5;

        std::cout << "(" << s1.getSpiralX() << "," << s1.getSpiralY() << ")" << std::endl;
    }
    
}


