/*
Name: HeeSeok Joo
UserId: hj4c
Homework #:6
Problem #: 2
Program Name: hj4c_circt_bd.cpp
Pledge Signature:
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
  double T1 = atof(argv[3]),
    T2 = atof(argv[4]),
    T3 = atof(argv[5]),
    T4 = atof(argv[6]);
  int row = atoi(argv[1]);
  int col = atoi(argv[2]);
  int count = 0;
  int k,l;
  double nodes[row][col];
  const double LIMIT = pow(10,-6);

  double Tavg = (T1+T2+T3+T4)/4;

  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(i == 0 && j == 0 || i == row-1 && j ==0 || i == 0 && j == col-1 || i==row-1 && j == col-1){
	nodes[i][j] = 0;
      }
      else if(i == 0 && j>=1 && j<col){
	nodes[i][j] = T1;
      }
      else if(j == col-1 && i>=1 && i<row){
	nodes[i][j] = T2;
      }
      else if(i == row-1 && j>=1 && j<col){
	nodes[i][j] = T3;
      }
      else if(j == 0 && i>=1 && i<row){
	nodes[i][j] = T4;
      }
      else {nodes[i][j] = Tavg;
	}
    }
  }

  do{
    count = 0;
    for(k=1;k<row-1;k++){
      for(l=1;l<col-1;l++){
	  double old = nodes[k][l];
	  nodes[k][l] = (nodes[k-1][l]+nodes[k+1][l]+nodes[k][l+1]+nodes[k][l-1])/4;
	if(fabs(nodes[k][l]-old) <= LIMIT){
	  count++;
      }
    }
    }
  }while(count != (row-2)*(col-2));

  for(int m=0;m<row;m++){
    for(int n=0;n<col;n++){
      printf("%.4lf\t",nodes[m][n]);
      }
    printf("\n");
  }
  return 0;
    }
