#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  char name[20];
  int guesses;
}Person;

void playGame(Person *person) {
  // declare struct variables with person's info
  printf("Please enter your name to start: ");

  scanf(" %s", person->name);
  printf("Your name is %s \n", person->name);
  person->guesses = 0;

  // prompt user for starting guess game
  int randomNum = rand() % (100 - 10 + 1) + 10;
  double sqrtVal = sqrt(randomNum);
  int guess;

  printf("%d IS THE NUMBER\n", randomNum);
  printf("%f is the square root of what number? ", sqrtVal);
  scanf(" %d", &guess);

  // logic for guess
  while(guess != randomNum) {
    if(guess > randomNum) {
      person->guesses++;
      printf("Too high, guess again: Guess a value between 10 and 100: ");
      scanf(" %d", &guess);
    }
    else {
      person->guesses++;
      printf("Too low, guess again: Guess a value between 10 and 100: ");
      scanf(" %d", &guess);
    }
  }

  person->guesses++;
  printf("You got it, baby! \n You made %d guesses\n", person->guesses);
}


void printLeaders(Person leaders[5], int size) {  
  printf("\n");
  printf("There are %d players\n", size);

  printf("Here are the current leaders: \n");

  for(int i = 0; i <= size; i++) {
    printf("%s made %d guesses\n", leaders[i].name, leaders[i].guesses);
  }
}

int compare(const void* a, const void* b) {
  Person* personA = (Person*)a;
  Person* personB = (Person*)b;
  return personA->guesses - personB->guesses;
}

int main() {
  char choice;
  Person leaders[5] = {0};
  
  printf("Welcome! Press 'q' to quit or any other key to continue: ");
  scanf(" %c", &choice);

  int currentIndex = 0;
  while(choice != 'q' && currentIndex < 5) {
    playGame(&leaders[currentIndex]);
    qsort(leaders, currentIndex+1, sizeof(Person), compare);
    printLeaders(leaders, currentIndex);

    printf("Press 'q' to quit or any other key to continue: ");
    scanf(" %c", &choice);
    currentIndex++;
  }

  prtinf("Bye Bye !");
}

