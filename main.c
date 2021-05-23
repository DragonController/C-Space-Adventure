/*
*FILENAME: main.c
*AUTHOR: Grace Fowler
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printWelcome();
char* responseFor(char* output);
void printGreeting(char* name);
int randomTravel();
void travelToRandomPlanet();
void travelTo(char* planet);

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
  free(input);
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
  printf("Mercury\n");
  printf("A very hot planet, closest to the sun.");
}

void travelTo(char* planet)
{
  printf("Mercury\n");
  printf("A very hot planet, closest to the sun.");
}