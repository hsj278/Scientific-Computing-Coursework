/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 4
Problem #: 1
Program Name: hj4c_4sphere.cpp
Pledge Signature:
*/

//When the number of sample points were increased by factor of 4, the standard deviation or the uncertainty decreased by half.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int SAMPLE = 1000;
const int NEXP = 100; //number of experiments
const double PI = 3.1415;

void throw_point(double *x, double *y, double *z, double *t);

int main(){
  double x;
  double y;
  double z;
  double t;
  double r = 1.0;
  double standard; //standard deviation
  double variance; //variance
  double sum;
  double sumpow;
  int count = 0;


  sum = 0;
  sumpow = 0;
  srand(time(NULL));
  for(int n=0; n<NEXP; n++){
    for(int i=0; i<SAMPLE; i++){
      throw_point(&x,&y,&z,&t);
      double hyp = sqrt(x*x+y*y+z*z+t*t);
      if(hyp < r)
	count++;
    }
    double volume = pow(2.0*r,4)*((double)count/(double)SAMPLE);
    
    count = 0;

    sum = volume + sum;
    sumpow = pow(volume,2) + sumpow;
  }

  variance = (1.0/((double)NEXP-1))*(sumpow - (((1.0/(double)NEXP)*pow(sum,2))));
  standard = sqrt(variance);

  double average = sum/NEXP;
  double real = pow(PI,2)/2;
  double difference = fabs(real - average)/standard;

  printf("The estimated average volume is: %lf\n",average);
  printf("The variance is: %lf\n",variance);
  printf("The uncertainty is: %lf\n",standard);
  printf("The calculation differs from the true result by: %lf\n",difference);

  return 0;
}

void throw_point(double *x, double *y, double *z, double *t){
  *x = 2.0*((double)rand()/(double)RAND_MAX) - 1.0;
  *y = 2.0*((double)rand()/(double)RAND_MAX) - 1.0;
  *z = 2.0*((double)rand()/(double)RAND_MAX) - 1.0;
  *t = 2.0*((double)rand()/(double)RAND_MAX) - 1.0;
}
