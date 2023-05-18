#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int roll_dice(void);
bool play_game(void);

int main(void)
{
  int wins = 0, losses = 0;

  srand((unsigned) time(NULL));
  for(;;) {
  if(play_game())
  {
    printf("You win!\n");
    wins++;
  } 
  else
  {  
    printf("You lose!\n");
    losses++;
  }
  char x;
  printf("\nPlay again? ");
  scanf("%c", &x);
  getchar();

  if(x == 'y' || x == 'Y')
    continue;  
  if(x == 'n' || x == 'N') 
  { 
     printf("Wins: %d Losses: %d\n", wins, losses);
     break;
  }
 }

return 0;
}


int roll_dice(void)
{
  int die1, die2;

  die1 = 1 + rand() % 6;
  die2 = 1 + rand() % 6;

  return die1 + die2;
}


bool play_game(void)
{
  int score1 = roll_dice();

  if(score1 == 7 || score1 == 11)
  {
    printf("You rolled: %d\n", score1);
    return true;
  }
  if(score1 == 2 || score1 == 3 || score1 == 12)
   {
     printf("You rolled: %d\n", score1);
     return false;
   }  

  else
  {
    printf("You rolled %d\nYour point is %d\n", score1, score1);
  }
  
  for(;;){
  int score2 = roll_dice();
  if(score2 == 7) {
    printf("You rolled: %d\n", score2);
    return false; }
  if(score2 == score1) {
    printf("You rolled: %d\n", score2);
    return true; }
  else printf("You rolled: %d\n", score2);
  }
}

