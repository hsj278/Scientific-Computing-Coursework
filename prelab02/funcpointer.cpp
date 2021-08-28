#include <stdio.h>
#include <math.h>

// trapezoidal rule integration - this C function will calculate the value
// of a definite integral for any other C function with the 
// prototype "double fcn(double)"
double trap_rule(double (*f)(double), double min, double max, int steps){
  int i;
  double sum=0;
  double dx=(max-min)/steps;
  for (i=1; i<steps ; i++) sum += f(min + i*dx);
  return dx * ( (f(min)+f(max))/2 + sum );
}

int main() {
  printf("Integral of sin(x) = %f\n", trap_rule(sin,0,M_PI/2,100));
  printf("Integral of exp(x) = %f\n", trap_rule(exp,0,10.,200));
}
