#include <stdio.h>
#include <math.h>

typedef struct {
  char name[20];
  int guesses;
}Person;

void playGame(Person person) {
  // prompt user for name and 
  printf("Please enter your name to start: ");
  scanf(" %s", person.name);
  printf("Your name is %s \n", person.name);

  // guess
  double randomNum = rand() % (100 - 10 + 1) + 10;
  double sqrtVal = sqrt(randomNum)
}


void updateLeaders(Person leaders[5]) {
  
}

int main() {
  char choice;
  Person leaders[5];
  
  printf("Welcome! Press 'q' to quit or any other key to continue: ");
  scanf(" %c", &choice);

  int currentIndex = 0;
  while(choice != 'q') {
    playGame(leaders[currentIndex]);

    printf("Press 'q' to quit or any other key to continue: ");
    scanf(" %c", &choice);
    currentIndex++;
  }
}

