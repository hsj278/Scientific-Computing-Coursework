// This program tests our simple histograming tools
// Compile with:
// g++ -Wall -O test_hist.cpp -o test_hist-I$P2660LIBV0 -L$P2660LIBV0 -lp2660

#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"

int main(){
  h1 hist1, hist2, hist3;  // create 3 histograms 
  int i;

  h1init(&hist1,0.,1000.);   // init the histograms 
  h1init(&hist2,-10.,10.);   // using the range -10:10
  h1init(&hist3,0.,1500.);

  for (i=0; i<10000; i++) {
    double u1=randu(-10.,10.);
    h1fill(&hist2,u1);  // fill hist1 w/ uniform distro.
    double n1=randn(300.,100.);
      // fill hist2 w/ normal distro.
    h1fill(&hist1,n1);
    double n2=randn(700.,60.);
    h1fill(&hist1,n2);
    h1fill(&hist3,n2 + n1);
  }
  for(i=0;i<20000;i++){
    double n3=randn(0.,2.);
    h1fill(&hist2,n3);
  }
  h1dump(&hist1,"");           // dumps histogram data to screen 
  h1dump(&hist1,"hist1.dat");  // dumps histogram data to file 
  h1plot(&hist1,"");           // plots histogram to screen, X11 assumed 
  h1plot(&hist1,"hist1.pdf");  // plots histogram to in pdf format to file
  h1dump(&hist2,"hist2.dat");  // dumps histogram data to file 
  h1plot(&hist2,"" );          // plots histogram to screen, X11 assumed
  h1plot(&hist2,"hist2.pdf");
  h1dump(&hist3,"hist3.dat");
  h1plot(&hist3,"");
  h1plot(&hist3,"hist3.pdf");
  
  return 0;
}
