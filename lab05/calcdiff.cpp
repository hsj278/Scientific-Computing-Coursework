#include <stdio.h>
#include <math.h>

double differentiate(double (*f)(double), double x);
double sinCosSquared(double x);
double expx(double x);

const int NSTEPS = 100;
const double PI = 3.1415;
double delta_x = pow(10,-4);

int main(){
  int n;
  double x;
  FILE *outp;

  outp = fopen("diff.dat","w");

  for(n=0;n<NSTEPS;n++){
    x = (3*PI)*((double)n/NSTEPS);
    //printf("%lf\t %lf\t %lf\n",x,sinCosSquared(x),differentiate(sinCosSquared,x));
    //fprintf(outp,"%lf\t %lf\t %lf\n",x,sinCosSquared(x),differentiate(sinCosSquared,x));
    printf("%lf\t %lf\t %lf\n",x,expx(x),differentiate(expx,x));
    fprintf(outp,"%lf\t %lf\t %lf\n",x,expx(x),differentiate(expx,x));
  } 

  fclose(outp);

  return (0);
}

double differentiate(double(*f)(double),double x){
  return (f(x + delta_x) - f(x - delta_x))/(2*delta_x);
}

double sinCosSquared(double x){
  return sin(x)*pow(cos(x),2);
}

double expx(double x){
  return exp(x);
}
