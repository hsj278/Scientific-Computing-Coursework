// fcnplot.cpp
// plot the function y=x*x 
// compile with
// g++ -O -Wall -I$P2660LIBV0 fcnplot.cpp -ofcnplot -L$P2660LIBV0 -lp2660
 
 
#include "hist.hpp"
#include <math.h> 

int main(){
  h1 hist1,hist2,hist3,hist4;
  h1init(&hist1,-10.,10.);
  h1init(&hist2,0.,10.);
  h1init(&hist3,0.,10.);
  h1init(&hist4,1.,pow(10,5));
  for (int i=0; i<200000; i++){
    h1fill(&hist1 ,((i/10000.)-10)+.5, (((i/10000.)-10)+0.5)*(((i/10000.)-10)+0.5));
  }
  for (int i=0;i<100000;i++){
    h1fill(&hist2 ,(i/10000.)+.5,sin((i/10000.)+0.5));
    h1fill(&hist3, (i/10000.)+.5,exp((i/10000.)+0.5));
    h1fill(&hist4, (i)+.5,log((i)+0.5));
  }
  h1plot(&hist1);
  h1plot(&hist2);
  h1plot(&hist3);
  h1plot(&hist4);
  return 0;
}

