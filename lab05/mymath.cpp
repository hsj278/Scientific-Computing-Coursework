#include <stdio.h>
#include <math.h>

double delta_x = pow(10,-4);

double differentiate(double(*f)(double),double x){
  return (f(x + delta_x) - f(x - delta_x))/(2*delta_x);
}

double sinCosSquared(double x){
  return sin(x)*pow(cos(x),2);
}
