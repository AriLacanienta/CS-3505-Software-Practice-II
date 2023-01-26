#ifndef CAR_H
#define CAR_H
class Car {
  double speed;

 public:
  Car(double speed): speed(speed) {}

  void drive();
  void slow();
  void speedUp();

};
#endif