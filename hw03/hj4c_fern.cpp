/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 3
Problem #: 2
Program Name: hj4c_fern.cpp
Pledge Signature:
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double rand0_1();

int main(){
  double x,
    y,
    x_n,
    y_n,
    f;
  int n;
  FILE *outp;
  const int NLOOPS = 1000000;

  outp = fopen("fern.dat","w");

  srand(time(NULL));
  
  x = 0;
  y = 0;

  for(n=0;n<NLOOPS;n++){
    f = rand0_1();
    if(f <= 0.01){
      x_n = 0;
      y_n = 0.16*y;
    }
    else if(f > 0.01 && f <= 0.86){
      x_n = 0.85*x + 0.04*y;
      y_n = -0.04*x + 0.85*y + 1.6;
    }
    else if(f > 0.86 && f <= 0.93){
      x_n = 0.2*x - 0.26*y;
      y_n = 0.23*x + 0.22*y + 1.6;
    }
    else {
      x_n = -0.15*x + 0.28*y;
      y_n = 0.26*x + 0.24*y + 0.44;
    }
    fprintf(outp,"%lf\t %lf\n",x_n,y_n);
    x = x_n;
    y = y_n;
  }
  fclose(outp);

  system("echo \"plot \'fern.dat\' with dots; q \" | gnuplot -persist");
  return 0;
}

double rand0_1(){
  double percent;
  do {
    percent = rand()/(double)RAND_MAX;
  } while (!percent);
  return percent;
}
