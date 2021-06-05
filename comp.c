/*
*FILENAME: comp.c
*AUTHOR: Grace Fowler
*/

#include "header.h"

char planets[18][100] = {"Mercury", "A very hot planet, closest to the sun.", "Venus", "It's very cloudy here!", "Earth", "There is something very familiar about this planet.", "Mars", "Known as the red planet.", "Jupiter", "A gas giant, with a noticeable red spot.", "Saturn", "This planet has beautiful rings around it.", "Uranus", "Strangely, this planet rotates around on its side.", "Neptune", "A very cold planet, furthest from the sun.", "Pluto", "I don't care what they say - it's a planet."};

void printWelcome()
{
  printf("Welcome to the Solar System!\n");
  printf("There are 9 planets to explore.\n");
}

char* responseFor(char* output)
{
  char* input = malloc(256);
  printf("%s\n", output);
  fgets(input, 256, stdin);
  if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n')) {
    input[strlen(input) - 1] = '\0';
  }
  return input;
}

void printGreeting(char* name)
{
  printf("Nice to meet you, %s. My name is Grace.\n", name);
  printf("Let's go on an adventure!\n");
}

int randomTravel()
{
  char* input = malloc(256);
  while (1) {
    printf("Shall I randomly choose a planet for you to visit? (Y or N)\n");
    fgets(input, 256, stdin);
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n')) {
      input[strlen(input) - 1] = '\0';
    }
    if (strcmp(input, "Y") == 0) {
      return 1;
    } else if (strcmp(input, "N") == 0) {
      return 0;
    } else {
      printf("Sorry, I didn't get that.\n");
    }
  }
}

void travelToRandomPlanet()
{
  int planet;
  srand(time(NULL));
  planet = rand() % 9;
  printf("Traveling to %s...\n", planets[planet * 2]);
  printf("Arrived at %s. %s\n", planets[planet * 2], planets[planet * 2 + 1]);
}

void travelTo(char* planet)
{
  int i;
  for (i = 0; i < 18; i += 2) {
    if (strcmp(planet, planets[i]) == 0) {
      printf("Traveling to %s...\n", planets[i]);
      printf("Arrived at %s. %s\n", planets[i], planets[i + 1]);
    }
  }
}
