// Hello, World
// This is the preferred notation for comments
/* This is the passé comment format */
#include <stdio.h>
#include <math.h>
#define gravity 9.81
int main(){
  double height,
         mass,
         potentialenergy,
         finalvelocity,
         time;
  FILE   *inp, *outp;

  inp = fopen("vertigo.dat", "r");
  outp = fopen("vertigo.out", "w");
  fscanf(inp,"%lf",&height);
  fprintf(outp,"The height is %.2f\n", height);
  fscanf(inp,"%lf",&mass);
  fprintf(outp,"The mass is %.2f\n", mass);

  potentialenergy = mass*height*gravity;
  finalvelocity = sqrt(2*potentialenergy/mass);
  time = finalvelocity/gravity;
  fprintf(outp,"Hello World\n");
  fprintf(outp,"The potential energy is %.2f J. \n", potentialenergy);
  fprintf(outp,"The final velocity is %.2f m/s. \n", finalvelocity);
  fprintf(outp,"The time it takes for it to fall is %.2f seconds. \n", 
time);
 return 0;  
}
