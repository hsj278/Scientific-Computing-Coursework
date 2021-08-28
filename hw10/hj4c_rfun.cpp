/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 10
Problem #: 1
Program Name: hj4c_rfun.cpp
Pledge Signature:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.hpp"
#include "hist.hpp"

/* EXTRA CREDIT
The solution could have been executed without the static variable if the for loop for 10000 random number generation was used in the rand_fun function, and calling the function for the three different probability distribution functions. By calling rand_fun three times inside the main function, the ymax value will go back to 0 for each function, and they will separately calculate the ymax values.
 */

const double PI = 3.1415;
const int STEPS = 100;
const int RAND = 10000;

double rand_fun(double(*pdf)(double), double xmin, double xmax);
double func1(double x);
double func2(double x);
double func3(double x);

int main(){
  double xmin1=-3;
  double xmax1=3;
  double xmin2=60;
  double xmax2=140;
  double xmin3=-10;
  double xmax3=10;
  h1 hist1,hist2,hist3;

  h1init(&hist1,STEPS,xmin1,xmax1,"func1");
  h1init(&hist2,STEPS,xmin2,xmax2,"func2");
  h1init(&hist3,STEPS,xmin3,xmax3,"func3");

  for(int j=0;j<RAND;j++){
    h1fill(&hist1,rand_fun(func1,xmin1,xmax1));
    h1fill(&hist2,rand_fun(func2,xmin2,xmax2));
    h1fill(&hist3,rand_fun(func3,xmin3,xmax3));
  }
  
  h1labels(&hist1,"x","probability","Function 1 e^(-x^2)");
  h1labels(&hist2,"x","probability","Function 2 10/((2pi)(x-100)^2+25)");
  h1labels(&hist3,"x","probability","Function 3 (cos(x)^2)(e^((-x^2)/25))");
  
  h1errors(&hist1,1);
  h1errors(&hist2,1);
  h1errors(&hist3,1);
  
  h1plot(&hist1);
  h1plot(&hist2);
  h1plot(&hist3);

  return 0;
}

double func1(double x){
  return exp(-(x*x));
}

double func2(double x){
  return 10/(2*PI*(pow(x-100,2)+pow(5,2)));
    }   

double func3(double x){
  return (pow(cos(x),2))*(exp(-((x*x)/25)));
    }

double rand_fun(double(*pdf)(double), double xmin, double xmax){
  double x = xmin;
  static double ymax = 0;
  double yvalue[STEPS];
  
  if(ymax == 0){
    for(int i=0;i<STEPS;i++){
       yvalue[i] = (*pdf)(x);
       
       if(ymax < yvalue[i]){
	 ymax = yvalue[i];
       }
     
     x = x + fabs(xmax-xmin)/STEPS;
    }
  }

  //Box limit y maximum
  double boxmax = 1.05*ymax;

  double xrand;
  double yrand;

  do{
  xrand = randu(xmin,xmax);
  yrand = randu(0,boxmax);
  }while((*pdf)(xrand) <= yrand);

  return xrand;
}
