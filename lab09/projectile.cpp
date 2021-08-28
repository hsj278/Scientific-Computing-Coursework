#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "random.hpp"
#include "hist.hpp"

const double g = 9.8;
const double PI = 3.1415;
const int NTRIALS = 10000;


double range(double v0,double theta);
double max_height(double v0,double theta);
double total_time(double v0,double theta);

int main(int argc,char* argv[]){
  if(argc == 1){
    printf("please put the angle in degrees and the initial velocity\n");
  }
  else{
  double v0 = atof(argv[2]);
  double theta = (PI/180.)*atof(argv[1]);
  int count = 0;
  int count_norm=0;
  h1 hist1,hist2;
  
  h1init(&hist1,10,30);
  h1init(&hist2,10,30);

  for(int i=0;i<NTRIALS;i++){
    double v0_err = v0 + randu(-0.3,0.3);
    double theta_err = theta + randu(-(PI/180.)*0.35,(PI/180.)*0.35);
    double v0_norm = randn(v0,0.3);
    double theta_norm = randn(theta,(PI/180.)*0.35);

    double x_range = range(v0_err,theta_err);
    double x_range_norm = range(v0_norm,theta_norm);
    //double y_max = max_height(v0_err,theta_err);
    //double time = total_time(v0_err,theta_err);
  
    h1fill(&hist1,x_range);
    h1fill(&hist2,x_range_norm);

    //  printf("%lf\n",x_range);
    //  printf("%lf\n",y_max);
    //p+rintf("%lf\n",time);
    // printf("\n");

    if(x_range<=21 && x_range>=19){
      count++;
    }
    if(x_range_norm<=21 && x_range_norm>=19){
      count_norm++;
    }
  }
  double prob = 100.*((double)count/(double)NTRIALS);
  double prob_norm = 100.*((double)count_norm/(double)NTRIALS);
  printf("The probility of hitting the target is: %lf percent\n",prob);
  printf("The probility of hitting the target is with normal distribution is: %lf percent\n",prob_norm);
  h1plot(&hist1);
  h1plot(&hist2);
  return 0;
  }
}

double range(double v0,double theta){
  double x = (v0*cos(theta))*((2*v0*sin(theta))/g);
  return x;
}

double max_height(double v0,double theta){
  double height = (pow(v0*sin(theta),2))/(2*g);
  return height;
}

double total_time(double v0,double theta){
  double time = (2*v0*sin(theta))/g;
  return time;
}
