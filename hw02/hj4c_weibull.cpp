/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 2
Problem #: 2a
Program Name: hj4c_weibull.cpp
Pledge Signaure:
*/

#include <stdio.h>
#include <math.h>

float weibull(float x, float k);

int main() {
  int x;
  float k1,
    k2,
    k3,
    k4;
  FILE *outp;

  //Disregarded lambda since the value is 1.

  k1 = 0.5;
  k2 = 1.0;
  k3 = 1.5;
  k4 = 5.0;
  outp = fopen("weibull.dat","w");

  printf("#x    W(x) for (lambda,k)=(1.0,0.5)  (1.0,1.0)  (1.0,1.5)  (1.0,5.0)\n");
  printf("#-------------------------------------------------------------------\n");
  fprintf(outp,"#x    W(x) for (lambda,k)=(1.0,0.5)  (1.0,1.0)  (1.0,1.5)  (1.0,5.0)\n");
  fprintf(outp,"#-------------------------------------------------------------------\n");

  for (x=0; x<=25; x++) {
    float xUsed = x/10.0;

    printf("%.1f %30.1f %10.1f %10.1f %10.1f\n",xUsed,weibull(xUsed,k1),weibull(xUsed,k2),weibull(xUsed,k3),weibull(xUsed,k4));
    fprintf(outp,"%.1f %30.1f %10.1f %10.1f %10.1f\n",xUsed,weibull(xUsed,k1),weibull(xUsed,k2),weibull(xUsed,k3),weibull(xUsed,k4));
    }
  fclose(outp);
}


float weibull(float xUsed, float k) {
   return ((k)*(pow(xUsed,(k-1)))*(exp(-pow(xUsed,k))));
	}
