#include <iostream>
#include "Car.h"

  void Car::drive() {
    std::cout << "Zooming " << Car::speed << " mph."<< std::endl;
  }

  void Car::slow() {
    speed = speed / 2;
  }

  void Car::speedUp() {
    speed = speed * 1.5;
  }


