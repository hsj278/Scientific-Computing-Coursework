/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 12
Problem #: 1
Program Name: hj4c_neutron.cpp
Pledge Signature:
 */

#include <stdio.h>
#include <math.h>
#include "random.hpp"
#include "hist.hpp"

const double lambda = 10; //cm but mu becomes 10 when converted to m
const double A = 207.2; //lead amu
const double LIMIT = 0.025; //eV
const double NEUTRONS = 100000;
const double kenergy0 = 1000000; //eV
const double PI = 3.1415;
const double WALL0 = 100; //m, initial wall condition to find T
const double WALLPRECISION = pow(10,-6); //m

double kenergy(double theta,double kinetic);

int main(){
  double kinetic; 
  double theta;
  double distance = 0;
  double distancex = 0;
  double T = WALL0;
  double percent = 0;
  int count = 0;
  int n =0;

  h1 hist1, hist2;
 
  h1init(&hist1,500,0,0.06,"backscatter");
  h1init(&hist2,500,0,0.06,"penetration");//There are more points outside of 0.06 eV, but I zoomed it in to show the exponential distribution more clearly

  while(WALL0/(pow(2,n)) >= WALLPRECISION){
      count = 0;
      for(int i=0;i<NEUTRONS;i++){ //neutron loop
	distance = ranExp(lambda);
	kinetic = kenergy0;
	theta = (PI/180)*randu(88,92); //actually phi, converted degrees into radians
	distancex = distance*sin(theta);
	while(kinetic >= LIMIT){
	  distance = ranExp(lambda);
	  kinetic -= kenergy(theta,kinetic);
	  theta += ((PI/180)*randu(0,360));
	  distancex += distance*sin(PI-theta);
	  if(distancex >= T || distancex <= 0){//Setting wall length so that the loop stops if the final distance is greater than the wall length or if it backscatters into the radiation area
	    break;
	  }
	}
	if(distancex >= T){
	  count++;
	}
      }
      percent = 100*(count/NEUTRONS);
      if(percent >= 1){
	T = T + (WALL0/(pow(2,n)));
      }
      else if(percent <= 1){
	T = T - (WALL0/(pow(2,n)));
      }
      n++;
  }
  printf("%.2lf m wall is needed to block at least 99 percent of the neutrons\n",T);

  //Same loop to plot the kinetic energies of penetrated particles and backscattered particles
  for(int i=0;i<NEUTRONS;i++){ //neutron loop
    distance = ranExp(lambda);
    kinetic = kenergy0;
    theta = (PI/180)*randu(88,92); //actually phi, converted degrees into radians
    distancex = distance*sin(theta);
    while(kinetic >= LIMIT){
      distance = ranExp(lambda);
      kinetic -= kenergy(theta,kinetic);
      theta += ((PI/180)*randu(0,360));
      distancex += distance*sin(PI-theta);
      if(distancex >= 5 || distancex <= 0){//Setting wall length so that the loop stops if the final distance is greater than the wall length or if it backscatters into the radiation area
	break;
      }
    }
    if(distancex <= 0){
      h1fill(&hist1,kinetic);
    }
    if(distancex >= 5){
      h1fill(&hist2,kinetic);
    }
  }
 
  h1labels(&hist1,"kinetic energy [eV]","number of neutrons","Backscattered neutrons");
  h1labels(&hist2,"kinetic energy [eV]","number of neutrons","Penetrated neutrons");

  h1plot(&hist1);
  h1plot(&hist2);
    
  return 0;
 }

double kenergy(double theta, double kinetic){
  return (kinetic*((A*A)+(2*A*cos(theta))+1)/(pow(1+A,2)));
}
