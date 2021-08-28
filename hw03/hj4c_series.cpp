/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 3
Problem #: 1
Program Name: hj4c_series.cpp
Pledge Signature:
*/

#include <stdio.h>
#include <math.h>

double pseries(int n,int p);

int main() {
  int n=1;
  int p;
  double elimit = pow(10,-8);
  double error;
  double sum = 0;
  double sumtotal;

  printf("Enter the value of p: ");
  scanf("%i",&p);

  do {
    sumtotal = sum + pseries(n,p);
    error = fabs(sumtotal - sum);
    sum = sumtotal;
    n++;
  } while (error > elimit);

  printf("x = %lf\n",sum);
  return 0;
}

double pseries(int n,int p){
  return(pow((1.0/n),p));
  }
