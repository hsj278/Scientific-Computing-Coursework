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
 
  fscanf(inp,"%lf",&height);
  printf("The height is %.2f\n", height);
  fscanf(inp,"%lf",&mass);
  printf("The mass is %.2f\n", mass);

  potentialenergy = mass*height*gravity;
  finalvelocity = sqrt(2*potentialenergy/mass);
  time = finalvelocity/gravity;
  printf("Hello World\n");
  printf("The potential energy is %.2f J. \n", potentialenergy);
  printf("The final velocity is %.2f m/s. \n", finalvelocity);
  printf("The time it takes for it to fall is %.2f seconds. \n", time);
 return 0;  
}
