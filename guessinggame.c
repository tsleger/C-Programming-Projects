#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

int main()
{
	int maxValue;
        printf("Type in a maximum number: ");
	scanf("%d", &maxValue);	

	srand(time(NULL));
	int randomNumber = rand() % (maxValue + 1);

	printf("Guess a number 0 - %d: ", maxValue);

	while(1){
	  int input;
	  scanf("%d", &input);
	  if(input == randomNumber)
	  {
	     printf("You win!\n");
	     break;
	  } 
	  else
	  {
	     printf("You lose! Try again!\n");
	  }

        }

	printf("Thanks for playing!\n"); 
}
