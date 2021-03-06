/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 7
Problem #: 1
Program Name: hj4c_bite.cpp
Pledge Signature:
 */

#include <stdio.h>
#include <stdlib.h>
#include "hist.hpp"
#include "random.hpp"

const int NTRIALS = 500;
const int MOSQUITO = 100;
const double BITEPROB = 0.0001;

int main(int argc,char *argv[]){
  if(argc == 1){
    printf("include the distance value\n");
  }
  else{
    int count;
    h1 hist1;
    double distance = atof(argv[1]);

    h1init(&hist1,0.,50.);

    for(int i=0;i<=NTRIALS;i++){
      count = 0;
      for(int j=0;j<=distance;j++){
	for(int k=0;k<MOSQUITO;k++){
	  double prob = randu(0,1);
	  if(prob <= BITEPROB){
	    count++;
	  }
	}
	h1fill(&hist1,count);
      }
    }
    h1plot(&hist1,"");
    return 0;
  }
}
