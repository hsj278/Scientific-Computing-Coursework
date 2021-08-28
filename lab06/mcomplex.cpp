#include <stdio.h>
#include <math.h>
#include "mcomplex.hpp"

double magnitude(Complex z){
  return sqrt(z.re*z.re + z.im*z.im);
}

void complex_conjugate(Complex *z){
  z->im = -z->im;
}

int print(Complex z){
  return printf("(%lf,%lfi)\n",z.re,z.im);
}
