#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100
int secret_number;
void read_guesses(void);

int main(void)
{
  char command;
  printf("Guess the secret number between 1 and %d\n\n", MAX_NUMBER);

  srand((unsigned) time(NULL));
  for(;;)
  {
    secret_number = 1 + (rand() % MAX_NUMBER);
    printf("A new number has been chosen\n");
    read_guesses();
    printf("Play again? (Y/N) ");
    scanf(" %c", &command);
    if(command == 'n' || command == 'N') return 0;
    if(command == 'y' || command == 'Y') continue;
    else return 0;
  }
}

void read_guesses(void)
{
  int guess, number_of_guesses = 0;

  for(;;)
  {
    printf("Enter guess: ");
    scanf("%d", &guess);

    if(guess < secret_number) {
       printf("\nToo low, try again.\n");
       number_of_guesses++;
    } 
    if(guess > secret_number) {
       printf("\nToo high, try again.\n");
       number_of_guesses++;
    } 
    if(guess == secret_number) {
      number_of_guesses++;
      printf("\nYou won in %d guesses!\n\n", number_of_guesses); 
      return;
    }  
  }
}
