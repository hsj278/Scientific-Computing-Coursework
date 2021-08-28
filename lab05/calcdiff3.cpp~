#include <stdio.h>
#include <math.h>
#include "mymath.hpp"

const int NSTEPS = 100;
const double PI = 3.1415;

int main(){
  int n;
  double x;
  FILE *outp;

  outp = fopen("diff.dat","w");

  for(n=0;n<NSTEPS;n++){
    x = (3*PI)*((double)n/NSTEPS);
    printf("%lf\t %lf\t %lf\n",x,sinCosSquared(x),differentiate(sinCosSquared,x));
    fprintf(outp,"%lf\t %lf\t %lf\n",x,sinCosSquared(x),differentiate(sinCosSquared,x));
  } 

  fclose(outp);

  return (0);
}
