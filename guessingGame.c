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

  // Clear the input buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}

  scanf(" %19s", person->name);
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
  // open text file and read contents
  char filename[] = "leaderboard.txt";
  FILE* fp = NULL;
  fp = fopen(filename, "r");

  if (fp == NULL) {
    fprintf(stderr, "Cannot open leaderboard.txt\n");
    exit(1);
  }

  Person leaders[5] = {0};
  int index = 0;

  while (fscanf(fp, "%19s made %d guesses\n", leaders[index].name, &leaders[index].guesses) == 2) {
    printf("%s made %d guesses\n", leaders[index].name, leaders[index].guesses);
    index++;
  }
  // printf("%s made %d guesses\n", leaders[0].name, leaders[0].guesses);

  char choice;
  
  printf("Welcome! Press 'q' to quit or any other key to continue: ");
  scanf(" %c", &choice);

  while(choice != 'q' && index < 5) {
    playGame(&leaders[index]);
    qsort(leaders, index+1, sizeof(Person), compare);
    printLeaders(leaders, index);

    printf("Press 'q' to quit or any other key to continue: ");
    scanf(" %c", &choice);
    index++;
  }

  if(index == 5)
  {
    printf("Maximum player count reached\n");
  }
  printf("Bye Bye!");
}

