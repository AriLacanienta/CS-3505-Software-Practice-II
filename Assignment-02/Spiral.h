/**
 * Spiral.cpp
 * A class to generate points in a spiral
 * 
 * A2: Classes, Facades, and Makefiles
 * Author: Ari Lacanienta
 * Date: 01/24/2023
*/
#ifndef SPIRLAL_H
#define SPIRAL_H

class Spiral {
    private:
    
        double _centerX, _centerY, _currentAngle, _scalingFactor, _currentRadius;

    public:

   /**
     * Creates a new Spiral object. The Spiral tracks its position in degrees 
     * clockwise from up. (i.e. 0 degrees is 12:00, 90 degress is 3:00).
    */ 
    Spiral(double centerX, double centerY, double startingAngle, double scalingFactor);


    /**
     * Increase the internal angle by a given degree amount
    */
    Spiral& operator+=(double angle);

    /**
     * Gets the relative x coordinate of the spiral based on the current angle
    */
    double getSpiralX();

    /**
     * Gets the relative y coordinate of the spiral based on the current angle
    */
    double getSpiralY();

    /**
     * Gets the current angle of the Spiral.
    */
    double getSpiralAngle();

};

#endif