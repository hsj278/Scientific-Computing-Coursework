/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 4
Problem #: 3
Program Name: hj4c_legendre.cpp
Pledge Signature:
*/

#include <stdio.h>
#include <math.h>

double Pn(double x,int n);

int main(){
  int n, i;
  double x;
  FILE *outp;

  outp = fopen("legendre.txt","w");
  
  for(i=0;i<=100;i++){
    x = ((double)i/50) - 1;
    fprintf(outp,"%lf\t",x);
    printf("%lf\t",x);
    for(n=0;n<=5;n++){
      Pn(x,n);
      fprintf(outp,"%lf\t",Pn(x,n));
      printf("%lf\t",Pn(x,n));
    }
    fprintf(outp,"\n");
    printf("\n");
  }
  fclose(outp);
  return 0;
}
  
double Pn(double x,int n){
  if (n == 0) return 1;
  else if (n == 1) return x;
  else return (((2.0*n-1)/(n))*x*Pn(x,n-1))-(((n-1.0)/(n))*Pn(x,n-2));
}
