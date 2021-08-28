#include<stdio.h>
#include<math.h>
 
const int NPOINTS = 25;
const double TWOPI = 2*3.14159;
int main(){
  int i;
  FILE *outp;
  outp= fopen("table.out","w");

  for (i=0; i<NPOINTS; i++){
  double val = (double) i / (NPOINTS-1) * 10;  // val in range[0:10]
  fprintf(outp, "%8d %8.4f %8.4f %8.4f %8.4f\n", 
	  i, val, 3*sin(val)/(val+1), cos(val)*sqrt(val), sin(val)*cos(val));
 ``
 }
  fclose(outp);
}
