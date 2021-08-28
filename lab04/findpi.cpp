#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int SAMPLE = 100000;

void throw_point(double *x, double *y);

int main(){
  double x;
  double y;
  double r = 1;
  int count = 0;
  srand(time(NULL));
  for(int i=0; i<SAMPLE;i++){
    throw_point(&x,&y);
    double hyp = sqrt(x*x+y*y);
    if(hyp<=r)
      count++;
  }

  double area = 4*r*r*count/SAMPLE;
  double pi = area/(r*r);

  printf("The value of pi is: %lf\n", pi);
  
  return 0;
}

void throw_point(double *x, double *y){
  static int i=0;
  if(i==0) {
    srand(time(NULL));
    i=1;
  }
  
  *x = 2*(rand()/(double)RAND_MAX)-1;
  *y = 2*(rand()/(double)RAND_MAX)-1;
}
