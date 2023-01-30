CARDIR = /workspaces/CS-3505/Lab3/Carlib

car2: main.o Car.o
	g++ -I $(CARDIR)/include/ -o Main main.o Car.o -L $(CARDIR)/lib/ -lCar

default: main.cpp Car.cpp 
	g++ -o Main main.cpp Car.cpp Car.h


Main: main.o Car.o
	g++ -o Main main.o Car.o

main.o: main.cpp
	g++ -I $(CARDIR)/include/ -c main.cpp

Car.o: Car.cpp
	g++ -I $(CARDIR)/include/ -c Car.cpp