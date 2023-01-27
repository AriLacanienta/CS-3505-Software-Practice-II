#ifndef SPIRLAL_H
#define SPIRAL_H

class Spiral {
    private:
        double centerX, centerY, currentAngle, scalingFactor;
        double currentRadius;

    public:
    
    Spiral(double centerX, double centerY, double startingAngle, double scalingFactor);

    Spiral& operator+=(double angle);
    double getSpiralX();
    double getSpiralY();
    double getSpiralAngle();

};

#endif