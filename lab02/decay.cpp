#include <stdio.h>
#include <math.h>

float A(float t);

int main() {
  int t;
  printf("#t/t_half Fraction remaining\n");
  for (t=0; t<11; t=t+1) {
    printf("%d %f\n",t,A(t));
  }  
  
  return 0;
}

float A(float t) {
  return (pow(0.5,t));
    }

