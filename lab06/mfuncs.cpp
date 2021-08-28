#include <stdio.h>
#include "mfuncs.hpp"

double ipower(double x, int n){
  if (n==0) return 1;
  if (n==1) return x;
  if (n<0)  return 1.0 / ipower(x,-n);
  return x*ipower(x, n-1);
}

long factorial(int n){
  long answer;
  if (n < 2 ) answer = 1;
  else {
    printf("calling factorial(n-1)\n");
    answer = (long)n * factorial(n-1);
  }
  return answer;
} 
