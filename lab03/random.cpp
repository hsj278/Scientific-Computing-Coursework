#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double nrand1(double u1, double u2);
double nrand2(double u1, double u2);
double variance(double t,double sum,double sumSquared);

const double PI = 3.14159;

int main(){
  int t;
  double nsum;
  double nsumSquared;
  double average;
  int counter1=0;
  int counter2=0;

 srand(time(NULL));

  for(t=1;t<=20;t++){
    double u1;
    u1 = (double)rand()/RAND_MAX;

    double u2;
    u2 = (double)rand()/RAND_MAX;

    double n1 = nrand1(u1,u2);
    double n2 = nrand2(u1,u2);
    
    nsum += n1+n2;
    nsumSquared += (pow(n1,2)+pow(n2,2));

    if(-1<=n1 && n1<=1){
      counter1++;
	}
    if(-1<=n2 && n2<=1){
      counter1++;
	}
    if(-2<=n1 && n1<=2){
      counter2++;
	}
    if(-2<=n2 && n2<=2){
      counter2++;
	}
}

  average = nsum/t;
  printf("sum of n is %lf\n",nsum);
  printf("squared sum of n is %lf\n",nsumSquared);
  printf("the average is %lf\n",average);
  printf("the variance is %lf\n",variance(t,nsum,nsumSquared));
  printf("the standard deviation is %lf\n",sqrt(variance(t,nsum,nsumSquared)));
  printf("the percentage between -1 and 1 is %lf\n",(double)counter1*100/(2*t));
  printf("the percentage between -2 and 2 is %lf\n",(double)counter2*100/(2*t));

  return (0);
}

  double nrand1(double u1, double u2){
    return(sqrt(-2*log(u1))*cos(2*PI*u2));
  }

  double nrand2(double u1, double u2){
    return(sqrt(-2*log(u1))*sin(2*PI*u2));
  }

double variance(double t, double sum, double sumSquared){
  return((1/(t - 1))*(sumSquared - (1/t)*(pow(sum,2))));
    }
