/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 5
Problem #: 2
Program Name: hj4c_trap2.cpp
Pledge Signature:
*/

#include <stdio.h>
#include <math.h>

double function(double x, double y);

double trap_rule2(double (*f)(double,double), double xmin, double xmax, double ymin, double ymax, int steps){
  int i,j;
  double sum = 0;
  double volume = 0;
  double dx = (xmax-xmin)/steps;
  double dy = (ymax-ymin)/steps;
  for(j=1;j<steps;j++){
    sum = 0;
    for(i=1;i<steps;i++){
    sum += f(xmin + i*dx,ymin + j*dy);
    }
    double area = dx*((function(xmin,ymin+j*dy)+function(xmax,ymin+j*dy))/2+sum);
    volume = volume + dy*area;
  }
  return volume;
}

int main(){
  printf("%lf\n",trap_rule2(function,0,10,10,20,200));
}

double function(double x,double y){
  return exp(cos(y+x))*exp(sin(x));
}
