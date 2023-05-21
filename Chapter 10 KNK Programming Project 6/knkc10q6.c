#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100
/* external variables  */

int contents[STACK_SIZE];
int top = 0;

/* function declarations */
void make_empty();
bool is_empty();
bool is_full();
void push(int i);
int pop();
void stack_overflow();
void stack_underflow();


int main()
{
  char ch, op1, op2;
  
 begin:
 while(1) {
    printf("Enter an RPN expression: ");
    scanf(" %c", &ch);
  while(ch != '\n') {
    if(ch >= '0' && ch <= '9') {
       ch -= '0';
       push(ch);
    }
    else
      switch(ch) {
        case '+': push(pop() + pop()); break;
        case '-': op2 = pop();
                  op1 = pop();
                  push(op1 - op2); 
                  break;
        case '*': push(pop() * pop()); break;
        case '/': op2 = pop(); 
                  op1 = pop();
                  push(op1 / op2);
                  break;
        case ' ': break;
        case '=': printf("Value of expression is: %d\n", pop()); goto begin; break;
        default: printf("Wrong character \n"); exit(EXIT_FAILURE);
        }
    scanf(" %c", &ch);
  }
 }

  return 0;
}

void stack_underflow()
{
  printf("\nNot enough operands in expression\n"); 
}

void stack_overflow()
{
  printf("\nExpression is too complex\n"); 
}


void make_empty()
{
  top = 0;
}

bool is_empty()
{
  return top == 0;
}

bool is_full()
{
  return top == STACK_SIZE;
}

void push(int i)
{
  if(is_full())
    stack_overflow();
  else
    contents[top++] = i;
}

int pop()
{
  if(is_empty()) {
    stack_underflow();
    return '\0';
  }
  else
    return contents[--top];
}
