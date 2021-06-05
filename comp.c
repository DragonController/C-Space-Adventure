/*
*FILENAME: comp.c
*AUTHOR: Grace Fowler
*/

#include "header.h"

void readJSON(char* arg)
{
  FILE* file = fopen("planetarySystem.json", "r");
  char string[2048];
  char* output = malloc(1024);
  cJSON* json;
  cJSON* planet = NULL;
  cJSON* planetz = NULL;
  int i = 0;
  int newline = 0;
  while (!feof(file))
  {
    string[i++] = fgetc(file);
    if (string[i - 1] == '\n')
    {
      newline = 1;
      i--;
    } else if (string[i - 1] == ' ' && newline == 1) {
      i--;
    } else {
      newline = 0;
    }
  }
  string[i] = '\0';
  json = cJSON_Parse(string);
  planetz = cJSON_GetObjectItem(json, "planets");
  i = 0;
  cJSON_ArrayForEach(planet, planetz)
  {
    cJSON* name = cJSON_GetObjectItem(planet, "name");
    cJSON* description = cJSON_GetObjectItem(planet, "description");
    strcpy(planets[i++], name->valuestring);
    strcpy(planets[i++], description->valuestring);
    //printf("%s\n", name->valuestring);
  }
  //output = planetz->valuestring;
  //printf("%s\n", output);
  fclose(file);
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
  return input;
}

void printGreeting(char* name)
{
  printf("Nice to meet you, %s. My name is Grace.\n", name);
  printf("Let's go on an adventure!\n");
}

int randomTravel()
{
  char input[256];
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
