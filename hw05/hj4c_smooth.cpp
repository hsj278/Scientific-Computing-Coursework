/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 5
Problem #: 1
Program Name: hj4c_smooth.cpp
Pledge Signature:
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
  int index = 0;
  int status;
  int nsmooth = atoi(argv[1]);
  int MAX_SIZE = 10000;
  int n;
  double data_point[MAX_SIZE];
  double sum;
  double average;
  FILE *inp;

  inp = fopen("noisy.dat","r");
  
  while (1){
    status = fscanf(inp,"%d %lf\n",&n,&data_point[index]);
    if (status == EOF) break;
    index++;
  }
  
  for(int j = 0; j < MAX_SIZE-nsmooth;j++){
    sum = 0;
    for(int i = j; i < j+nsmooth;i++){
      sum = sum + data_point[i];
    }
    average = sum/(double)nsmooth;
    printf("%d\t %lf\n",j,average);
  }  
  fclose(inp);
  return 0;
}
