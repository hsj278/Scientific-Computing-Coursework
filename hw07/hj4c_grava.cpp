/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 7
Problem #: 2
Program Name: hj4c_grava.cpp
Pledge Signature:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double s_vec[3];
  double v_vec[3];
  double f_vec[3];
  double mass;
} body;

int readData(const char* file, body *grava);

const int MAX_ENTRIES = 100;
const double G = 6.67e-11;

int main(int argc,char* argv[]){
  if(argc == 1){
    printf("Please enter the file name\n");
  }
  else{
  body object[MAX_ENTRIES];
  int entry = readData(argv[1],object);
  
  double totalm = 0;
  double xm = 0;
  double ym = 0;
  double zm = 0;

  for(int i=0;i<entry;i++){
    double x=object[i].s_vec[0];
    double y=object[i].s_vec[1];
    double z=object[i].s_vec[2];
    double m=object[i].mass;

    totalm += m;

    xm += x*m;
    ym += y*m;
    zm += z*m;
  }
  double comx = xm/totalm;
  double comy = ym/totalm;
  double comz = zm/totalm;

  printf("center of mass in x: %lf\ncenter of mass in y: %lf\ncenter of mass in z: %lf\n",comx,comy,comz);

  for(int k=0;k<entry;k++){
    object[k].f_vec[0]= (G*(totalm-object[k].mass)*object[k].mass)/pow(fabs(comx),2);
    object[k].f_vec[1]= (G*(totalm-object[k].mass)*object[k].mass)/pow(fabs(comy),2);
    object[k].f_vec[2]= (G*(totalm-object[k].mass)*object[k].mass)/pow(fabs(comz),2);

    printf("Body %3d Force = (%8.2lg,%8.2lg,%8.2lg)\n",k+1,object[k].f_vec[0],object[k].f_vec[1],object[k].f_vec[2]);
  }

    return 0;
  }
}

int readData(const char* fileName, body *object){
  FILE *data_f=fopen(fileName,"r");
  if ( data_f==NULL ){
    printf("Error: file not found!\n");
    return -1;
  }
  int status;
  int count=0;
  while(count<MAX_ENTRIES) {
    status=fscanf(data_f,"%lf %lf %lf %lf %lf %lf %lf",&object[count].s_vec[0], 
		  &(object[count].s_vec[1]),&(object[count].s_vec[2]),&(object[count].v_vec[0]),&(object[count].v_vec[1]),&(object[count].v_vec[2]),&(object[count].mass));
    if (status==EOF || status!= 7) break;
    count++;
  }
  fclose(data_f);
  printf("%d bodies read from file\n",count);  
  return count;
}
