# spiralPDF compilation makefile
# A2: Classes, Facades, and Makefiles
# Author: Ari Lacanienta
# Date: 01/24/2023
#
# spiralPDF - compiles and links all files
# clean - removes compiled files
# rebuild - removes compiled files then compiles and links all files
# test, test[2-4] - compiles all files then runs the project using sample text 

# Compiler settings
CC = g++ -g -Wall

# Library paths
LIBHARU = ../libharu

spiralPDF: spiralPDF.o Spiral.o HaruPDF.o
	$(CC) -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -L $(LIBHARU)/src/ -lhpdfs -lz

spiralPDF.o: spiralPDF.cpp Spiral.h 
	$(CC) -c spiralPDF.cpp -I $(LIBHARU)/include/

Spiral.o: Spiral.cpp Spiral.h
	$(CC) -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) -c HaruPDF.cpp -I $(LIBHARU)/include/

clean: 
	rm *.o spiralPDF spiralPDF.pdf

rebuild: clean spiralPDF

test: spiralPDF
	./spiralPDF "You are a worm through time. The thunder song distorts you. Happiness comes. White pearls, but yellow and red in the eye."

test2_spiral: spiralPDF
	./spiralPDF ".........................................................................................................................................................."

test3_orientation: spiralPDF
	./spiralPDF "Alllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll"

test4_stress: spiralPDF
	./spiralPDF "You are a worm through time. The thunder song distorts you. Happiness comes. White pearls, but yellow and red in the eye. Through a mirror, inverted is made right. Leave your insides by the door. Push the fingers through the surface into the wet. Youve always been the new you. You want this to be true. We stand around you while you dream. You can almost hear our words but you forget. This happens more and more now. You gave us the permission in your regulations. We wait in the stains. The word that describes this is redacted. Repeat the word. The name of the sound. It resonates in your house. After the song, time for applause. We build you till nothing remains. The egg cracks and the truth will emerge out of you. You are home. You remind us of home. You've taken your boss with your boss with you. All hair must be eaten. Under the conceptual reality behind this reality you must want these waves to drag you away. After the song, time for applause. This cliché is death out of time, breaking the first the second the third the fourth wall, the fifth wall, floor; no floor: you fall. How do you say “insane”. Hurts to be happy. An earworm is a tune you can't stop humming in a dream: “baby baby baby yeah”. Just plastic. So, safe and nothing to worry about. Ha ha, funny. The last egg breaks now. The hole in your room is a hole in you. You came and we let you in through the hole in you. You have always been here, the only child. A copy of a copy of a copy. Orange peel. The picture is you holding the picture. When you hear this you will know you're in new you. You want to listen. You want to dream. You want to smile. You want to hurt. You don't want to be."