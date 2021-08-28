#include <stdio.h>
#include <math.h>

double ipow(double x, int n);

int main() {
  int x;
  int n;
  printf("Give an integer and power: ");
  scanf("%i %i",&x,&n);
  printf("%lf\n",ipow(x,n));
  return 0;
}

double ipow(double x, int n) {
  if (n == 0)
    return (long)1;
  else
    return (long)x*pow(x,n-1);
}
