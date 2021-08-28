#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void norm2(double *n1, double *n2);

int main(){
  double ranu1, ranu2;
  int i, n68=0;
  const int NLOOPS = 1000;  // increase this number for more statistics
  int nvalues = NLOOPS*2;
  double sum = 0, sum2 = 0;

  for (i=0; i<NLOOPS; i++){
    norm2(&ranu1,&ranu2);
    printf("%lf      %lf\n", ranu1, ranu2);
    //if (fabs(rann1)<1.0) n68++;
    //if (fabs(rann2)<1.0) n68++;
    //sum  += (rann1+rann2);
    //sum2 += (rann1*rann1
  }
  //printf("Completed calculation with %d trials\n",NLOOPS*2);
  //printf("%% of values found within the range +- 1.0 = %5.2f%%\n",
  // (float)n68/(float)nvalues*100);
  //double variance = 1.0/(nvalues-1)*(sum2-sum*sum/nvalues);
  //printf("Variance = %lf\n",variance);
  //printf("Standard Deviation = %lf\n",sqrt(variance));
  return 0;
}

void norm2(double *n1, double *n2){
  static int i = 0;
  if (i==0) {
    srand(time(NULL));
    i=1;
  }

  *n1 = rand()/(double)RAND_MAX;
  *n2 = rand()/(double)RAND_MAX;

  *n1 = sqrt(-2*log(*n1))*cos(2*M_PI**n2);
  *n2 = sqrt(-2*log(*n1))*sin(2*M_PI**n2);
}
