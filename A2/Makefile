# Compiler settings
CC = g++ -g -Wall

# Library paths
LIBHARU = ../libharu

all: spiralPDF.o Spiral.o HaruPDF.o
	$(CC) -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -L $(LIBHARU)/src/ -lhpdfs -lz

spiralPDF.o: spiralPDF.cpp
	$(CC) -c spiralPDF.cpp -I $(LIBHARU)/include

Spiral.o: Spiral.cpp
	$(CC) -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp
	$(CC) -c HaruPDF.cpp -I $(LIBHARU)/include/

test: all
	./spiralPDF "You are a worm through time. The thunder song distorts you. White pearls, but yellow and red in the eye"

test2: all
	./spiralPDF ".........................................................................................................................................................."

test3: all
	./spiralPDF "Alllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll"

test4: all
	./spiralPDF "Allllllllllllll"

clean: 
	rm *.o spiralPDF spiralPDF.pdf

rebuild: clean all

example: pdfExample.cpp
	$(CC) -I $(LIBHARU)/include/ -o pdfExample pdfExample.cpp -L $(LIBHARU)/src/ -lhpdfs -lz