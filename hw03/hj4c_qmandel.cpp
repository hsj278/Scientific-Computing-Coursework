/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 3
Problem #: 3
Program Name: hj4c_qmandel.cpp
Pledge Signature:
*/

#include <stdio.h>
#include <math.h>

double magnitude(double re, double im){
  return sqrt(re*re+im*im);
}

int mandel_test(double c_re, double c_im);

const int NTRIALS=100;

int main(){
  double xmin = -2.0;
  double xmax = 1.0;
  double ymin = -2.0;
  double ymax = 1.5;
  double c_re, c_im;
  int nim,nre, counts;
  const int NSTEPS = 250;

  FILE *outp = fopen ("qmandel.dat","w");

  for (nre=0; nre<NSTEPS ; nre++){
    c_re = xmin + (xmax-xmin) * nre/NSTEPS;
    for (nim=0; nim<NSTEPS; nim++){
      c_im = ymin + (ymax-ymin) * nim/NSTEPS;
      counts = mandel_test(c_re,c_im);
      fprintf(outp,"%g\t %g\t %d\n",c_re,c_im,counts);
    }
  }
  fclose(outp);
  return 0;
}

int mandel_test(double c_re, double c_im){
  double z_re = c_re;
  double z_im = c_im;
  int counts = 0;
  while (magnitude(z_re,z_im)<=2.0 && counts<NTRIALS){
    counts++;
    double re=z_re;
    double im=z_im;

    z_re = (pow(re,4))-(6*pow(re,2)*pow(im,2))+(pow(im,4));
    z_im = (4*pow(re,3)*im)-(4*re*pow(im,3));
    
    z_re = z_re + c_re;
    z_im = z_im + c_im;
  }
  return counts;
}
