/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 9
Problem #: 1
Program Name: hj4c_resist.cpp
Pledge Signature:
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "random.hpp"
#include "hist.hpp"

const double g = 9.8;
const double PI = 3.1415;
const int NTRIALS = 1000;

int main(int argc,char* argv[]){
  if(argc == 1){
    printf("please put the angle in degrees, the initial velocity, and k/m value.\n");
  }
  else{
    double v0 = atof(argv[2]);
    double theta = (PI/180.)*atof(argv[1]);
    double kdivm = atof(argv[3]);
    double Delta_t = 0.01;
    FILE *outp;
    h1 hist1;

    outp = fopen("resist.dat","w");

    h1init(&hist1,100,500);

    double vx=v0*cos(theta);
    double vy=v0*sin(theta);
    double x=0;
    double y=0;
    double t_total = 0;

    while(y >= 0){
      x += vx*Delta_t;
      y += vy*Delta_t;

      vx += -(vx*(kdivm))*Delta_t;
      vy += -(vy*(kdivm)+g)*Delta_t;

      t_total += Delta_t;

      fprintf(outp,"%lf %lf %lf %lf %lf\n",t_total,x,y,vx,vy);
    }

    double array[NTRIALS];
    double x_total =0;

    for(int m=0;m<NTRIALS;m++){
      double vx=v0*cos(theta);
      double vy=v0*sin(theta);
      double x=0;
      double y=0;
      double t_total = 0;
      double kdivm_uncer = randu((kdivm/2),2*kdivm);
      while(y >= 0){
	x += vx*Delta_t;
	y += vy*Delta_t;
	
	vx += -(vx*(kdivm_uncer))*Delta_t;
	vy += -(vy*(kdivm_uncer)+g)*Delta_t; 
	
	t_total += Delta_t;
      }
      h1fill(&hist1,x);
      array[m] = x;
      x_total += x;
    }

    int i, j, min;
    double temp;
      for (i = 0;i<NTRIALS-1;i++){
	min = i;
	for (j=i;j<NTRIALS-1;j++){
	  if(array[j]<array[min]){
	    min = j;
	  }
	  temp = array[i];
	  array[i] = array[min];
	  array[min] = temp;
	}
      }

      /*
      for(int n=0;n<NTRIALS-1;n++){
	printf("%lf\n",array[n]);
      }
*/ 
    double mean = x_total/NTRIALS;
    double mean_array = array[(int)((NTRIALS-1)/2.)];

    double s_l = fabs(mean_array-array[(int)(NTRIALS*0.32)]);
    double s_r = fabs(mean_array-array[(int)(NTRIALS*0.68)]);
      //standard deviations

    printf("The accurate mean is %lf\n",mean);
    printf("The mean from the array is %lf\n",mean_array);
    printf("The standard deviation to the left is %lf\n", s_l);
    printf("The standard deviation to the right is %lf\n", s_r);

    h1plot(&hist1);
    fclose(outp);

    system("echo \"plot \'resist.dat\' using 2:3 with lines; q \" | gnuplot -persist");
    system("echo \"plot \'resist.dat\' using 1:4 with lines; q \" | gnuplot -persist");
    system("echo \"plot \'resist.dat\' using 5:3 with lines; q \" | gnuplot -persist");

    return 0;
  }
}

