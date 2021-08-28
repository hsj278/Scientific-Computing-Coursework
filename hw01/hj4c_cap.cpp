/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 01
Problem #: 01
Program Name: hj4c_cap.cpp
Pledge Signature: HeeSeok Joo
*/

#include <stdio.h>
#include <math.h>
#define INPUT "input.dat"

/* I mainly used examples 2.4 and 2.5 from the book as my reference. I modified the example codes into the code that answered the problems. */

int main()
{
  FILE *Infile;
  int count=0;
  float C1;
  float C2;
  float C3;
  float C4;
  int status;
  float parallel_capacitance;
  float series_capacitance;
  
  Infile=fopen(INPUT,"r");
  while(1)
    {
      status=fscanf(Infile, "%f %f %f %f microFarads", &C1,&C2,&C3,&C4);
      if (status == EOF) break;
      printf("\nC1 = %.3f microFarads\nC2 = %.3f microFarads\nC3 = %.3f microFarads\nC4 = %.3f microFarads\n\n", C1,C2,C3,C4);
      count=count+1;
	}
  fclose(Infile);
 
  parallel_capacitance = C1 + C2 + C3 + C4;
  series_capacitance = (1/((1/C1)+(1/C2)+(1/C3)+(1/C4)));

  printf("The total capacitance for all capacitors arranged in parallel is %.3f\n", parallel_capacitance);
  printf("The total capacitance for all capacitors arranged in series is %.3f\n\n", series_capacitance);

  return 0;
}

