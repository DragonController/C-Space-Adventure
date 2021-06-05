/*
*FILENAME: main.c
*AUTHOR: Grace Fowler
*/

void readJSON();
void printWelcome();
char* responseFor(char* output);
void printGreeting(char* name);
int randomTravel();
void travelToRandomPlanet();
void travelTo(char* planet);

int main(int argc, char** argv)
{
  readJSON(argv[0]);

  printWelcome();
  printGreeting(responseFor("What is your name?"));
  if (randomTravel()) {
    travelToRandomPlanet();
  } else {
    travelTo(responseFor("Name the planet you would like to visit."));
  }
}
