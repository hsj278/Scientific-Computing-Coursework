#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mymath.hpp"



int main(int argc, char *argv[]){
  int n;
  int i;
  double x;
  double x_min;
  double x_max;
  FILE *outp;

  outp = fopen("diff.dat","w");
  i = atoi(argv[1]);
  x_min = atoi(argv[2]);
  x_max = atoi(argv[3]);
  for(n=0;n<i;n++){
    x = (x_max - x_min)*((double)n/i) + x_min;
    printf("%lf\t %lf\t %lf\n",x,sinCosSquared(x),differentiate(sinCosSquared,x));
    fprintf(outp,"%lf\t %lf\t %lf\n",x,sinCosSquared(x),differentiate(sinCosSquared,x));
  } 

  fclose(outp);

  return (0);
}
