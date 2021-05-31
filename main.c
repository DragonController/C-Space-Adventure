/*
*FILENAME: main.c
*AUTHOR: Grace Fowler
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printWelcome();
char* responseFor(char* output);
void printGreeting(char* name);
int randomTravel();
void travelToRandomPlanet();
void travelTo(char* planet);

char planets[18][100] = {"Mercury", "A very hot planet, closest to the sun.", "Venus", "It's very cloudy here!", "Earth", "There is something very familiar about this planet.", "Mars", "Known as the red planet.", "Jupiter", "A gas giant, with a noticeable red spot.", "Saturn", "This planet has beautiful rings around it.", "Uranus", "Strangely, this planet rotates around on its side.", "Neptune", "A very cold planet, furthest from the sun.", "Pluto", "I don't care what they say - it's a planet."};

int main(int argc, char** argv)
{
  printWelcome();
  printGreeting(responseFor("What is your name?"));
  if (randomTravel()) {
    travelToRandomPlanet();
  } else {
    travelTo(responseFor("Name the planet you would like to visit."));
  }
}