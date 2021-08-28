/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 4
Problem #: 2
Program Name: hj4c_man3d.cpp
Pledge Signature:
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int mandel_test(double c_re, double c_im);
void throw_point(double *x, double *y, double *z);

const int NTRIALS = 100;
const int SAMPLE = 100000;

int main(){
  double xmin = -2.0;
  double xmax = 0.5;
  double ymin = -1.25;
  double ymax = 1.25;
  double zmin = -1.25;
  double zmax = 1.25;
  double x,y,z;
  int scount; //sample count

  srand(time(NULL));
  for (int i=0; i<SAMPLE; i++){
    throw_point(&x,&y,&z);
    double r = sqrt(y*y+z*z);
    if(mandel_test(x,r) == NTRIALS)
      scount++;
  }

  double volume = (xmax-xmin)*(ymax-ymin)*(zmax-zmin)*((double)scount/(double)SAMPLE);
  printf("volume: %lf\n",volume);

  return 0;
}

int mandel_test(double c_re, double c_im){
  double z_re = c_re;
  double z_im = c_im;
  int counts = 0;
  while ((z_re*z_re+z_im*z_im)<=4.0 && counts<NTRIALS){
    counts++;
    double re=z_re;
    double im=z_im;

    z_re = re*re-im*im;
    z_im = 2*re*im;

    z_re = z_re + c_re;
    z_im = z_im + c_im;
  }
  return counts;
}

void throw_point(double *x, double *y, double *z){
  *x = 2.5*((double)rand()/(double)RAND_MAX) - 2.0;
  *y = 2.5*((double)rand()/(double)RAND_MAX) - 1.25;
  *z = 2.5*((double)rand()/(double)RAND_MAX) - 1.25;
}
