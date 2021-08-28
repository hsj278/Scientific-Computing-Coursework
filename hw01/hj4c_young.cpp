/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 01
Problem #: 02
Program Name: hj4c_young.cpp
Pledge Signature: HeeSeok Joo
*/

#include <stdio.h>
#include <math.h>
#define YOUNG "young.dat"
const float PI = 3.14159;

int main()
{
  FILE *Infile,*Outfile;
  int count=0;
  char material[20];
  float young_modulus; /*N/m^2*/
  float elastic_limit; /*N/m^2*/
  int status;
  float DeltaL1N; //m
  float DeltaL100N; //m
  float DeltaLMax; //m
  float L; /*Length in m*/
  float R; /*Radius in cm*/

  Infile=fopen(YOUNG,"r");
  Outfile=fopen("young.out","w");

  printf("Enter a length of a cylindrical rod in meters: ");
  scanf("%f",&L);
  printf("Enter a radius of a cylindrical rod in centimeters: ");
  scanf("%f",&R);

  fprintf(Outfile,"    Material Young's Modulus Elastic Limit DeltaL@1N(m) DeltaL@100N(m) DeltaLMax\n(m)");
  printf("    Material Young's Modulus Elastic Limit DeltaL@1N(m) DeltaL@100N(m) DeltaLMax(m)\n");

  while(1)
    {
      status=fscanf(Infile,"%s %f %f", material, &young_modulus, &elastic_limit);
      if (status == EOF) break;

      young_modulus = young_modulus*pow(10,10);
      elastic_limit = elastic_limit*pow(10,8);

      DeltaL1N = (L)/((young_modulus)*(PI)*(R*0.01));
      DeltaL100N = ((100)*(L))/((young_modulus)*(PI)*(R*0.01));
      DeltaLMax = ((L)*(elastic_limit))/(young_modulus);
 
      fprintf(Outfile,"%12s %15.1e %13.1e %9.1e %11.1e %9.1e\n",material,young_modulus,elastic_limit,DeltaL1N,DeltaL100N,DeltaLMax);
      printf("%12s %15.1e %13.1e %12.1e %14.1e %12.1e\n",material,young_modulus,elastic_limit,DeltaL1N,DeltaL100N,DeltaLMax);


      count=count+1;
    }
  fclose(Infile);
  fclose(Outfile);
  return 0;
}

