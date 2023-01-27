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

test: spiralPDF
	./spiralPDF "Testing from Makefile"

clean: 
	rm *.o spiralPDF

rebuild: clean all

example: pdfExample.cpp
	$(CC) -I $(LIBHARU)/include/ -o pdfExample pdfExample.cpp -L $(LIBHARU)/src/ -lhpdfs -lz