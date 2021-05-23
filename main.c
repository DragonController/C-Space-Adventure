/*
*FILENAME: main.c
*AUTHOR: Grace Fowler
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
  char* input = malloc(256);
  printf("Welcome to the Solar System!\n");
  printf("There are 9 planets to explore.\n");
  printf("What is your name?\n");
  fgets(input, 256, stdin);
  if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n')) {
    input[strlen(input) - 1] = '\0';
  }
  printf("Nice to meet you, %s. My name is Grace.\n", input);
  printf("Let's go on an adventure!\n");
  while (!(strcmp(input, "Y") == 0 || strcmp(input, "N") == 0)) {
    printf("Shall I randomly choose a planet for you to visit? (Y or N)\n");
    fgets(input, 256, stdin);
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n')) {
      input[strlen(input) - 1] = '\0';
    }
    if (strcmp(input, "N") == 0) {
      printf("Name the planet you would like to visit.\n");
	  scanf("%s", input);
	  strcpy(input, "N");
    } else if (strcmp(input, "Y") != 0) {
      printf("Sorry, I didn't get that.\n");
	}
  }
  printf("Mercury\n");
  printf("A very hot planet, closest to the sun.");
  free(input);
}