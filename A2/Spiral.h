#ifndef SPIRLAL_H
#define SPIRAL_H

class Spiral {
    private:
        double _centerX, _centerY, _currentAngle, _scalingFactor;
        double _currentRadius;

    public:
    
    Spiral(double centerX, double centerY, double startingAngle, double scalingFactor);

    Spiral& operator+=(double angle);
    double getSpiralX();
    double getSpiralY();
    double getSpiralAngle();

};

#endif