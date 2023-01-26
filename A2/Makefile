
default: spiralPDF

spiralPDF: spiralPDF.o Spiral.o HaruPDF.o
	g++ -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -L../libharu/src/ -lhpdfs -lz

spiralPDF.o: spiralPDF.cpp
	g++ -c spiralPDF.cpp

Spiral.o: Spiral.cpp
	g++ -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp
	g++ -c HaruPDF.cpp -I../libharu/include/

test: spiralPDF

clean:
	rm spiralPDF *.o