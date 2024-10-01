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

  printf("Bye Bye !");