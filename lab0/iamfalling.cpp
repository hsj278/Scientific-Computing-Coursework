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
  printf("Enter the height in meters, yo.");
  scanf("%lf",&height);
  printf("Enter the mass in kilograms, please.");
  scanf("%lf",&mass);
  potentialenergy = mass*height*gravity;
  finalvelocity = sqrt(2*potentialenergy/mass);
  time = finalvelocity/gravity;
  printf("Hello World\n");
  printf("The potential energy is %lf J. \n", potentialenergy);
  printf("The final velocity is %lf m/s. \n", finalvelocity);
  printf("The time it takes for it to fall is %lf seconds. \n", time);
 return 0;  
}
