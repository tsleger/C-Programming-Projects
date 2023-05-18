#include <stdio.h>

int main()
{
  float eps, i_factorial = 1.0, j_factorial = 1.0;

  printf("Choose an epsilon to approximate e: ");
  scanf("%f", &eps);

  int i;
  for(i = 2; ;i++){ //finding smallest i s.t. 1/i! < eps
    if(i_factorial < 1.0/eps)
    i_factorial *= i;
    else break;
  }
  printf("So we calculate to the %dth Maclaurin expansion term ", i+1);
  printf("(i.e. up to 1/%d!)\n", i); 

  float e_minus_one;
  printf("So e equals 1 + ");

  for(int j = 1;j < i + 1;j++) {
    j_factorial *= j;
    e_minus_one += 1.0/j_factorial;
    if(j < i)
      printf("1/(%d!) + ", j);
    else  
      printf("1/(%d!)\n", j);
 }
  printf("So e (roughly) = %f\n", e_minus_one + 1);
}
