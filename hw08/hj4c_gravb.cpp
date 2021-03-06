/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 8
Problem #: 1
Program Name: hj4c_gravb.cpp
Pledge Signature:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAX_ENTRIES = 100;
const double G = 6.67e-11;
FILE *Outfile;

typedef struct {
  double s_vec[3];
  double v_vec[3];
  double f_vec[3];
  double mass;
} body;

body object[MAX_ENTRIES];

int readData(const char* file, body *grava);
double distance(double *svec1, double *svec2);
void vsub(double *v1, double *v2, double *vlm2);
void forces(body *object, int entry);
void evolve(body *object,int entry, double Delta_t);

int main(int argc,char* argv[]){
  if(argc == 1){
    printf("Please enter the file name\n");
  }
  else{
    int entry = readData(argv[1],object);
    double time = atof(argv[2]);
    double Delta_t = atof(argv[3]);

    Outfile = fopen("location.dat","w");

    for(int t=0;t<((int)time/(int)Delta_t);t++){
      forces(object,entry);
      for(int n=0;n<entry;n++){
	    evolve(object,entry,Delta_t);
	    fprintf(Outfile,"%lf %lf %lf\n",object[n].s_vec[0],object[n].s_vec[1],object[n].s_vec[2]);
	    }
      fprintf(Outfile,"\n\n");
    }
  }
  fclose(Outfile);
  return 0;
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
    status=fscanf(data_f,"%lf %lf %lf %lf %lf %lf %lf",&object[count].s_vec[0],&(object[count].s_vec[1]),&(object[count].s_vec[2]),&(object[count].v_vec[0]),&(object[count].v_vec[1]),&(object[count].v_vec[2]),&(object[count].mass));
    if (status==EOF || status!= 7) break;
    count++;
  }
  fclose(data_f);
  printf("%d bodies read from file\n",count);
  return count;
}

double distance(double *svec1,double *svec2){
   double dist2=0;
   int i;
   for(i=0;i<3;i++){
     dist2 += (svec1[i]-svec2[i])*(svec1[i]-svec2[i]);
   }
   return sqrt(dist2);
 }

void vsub(double *v1, double *v2, double *v1m2=0){
  int i;
  for(i=0;i<3;i++){
    v1m2[i] = v1[i]-v2[i];
  }
}

void forces(body *object, int entry){
  double dist, force;
  double dirvec[3];

  for(int i=0;i<entry;i++){
    object[i].f_vec[0]=0;
    object[i].f_vec[1]=0;
    object[i].f_vec[2]=0;
    for(int j=0;j<entry;j++){
      if(i!=j){
	dist = distance(object[i].s_vec,object[j].s_vec);
	vsub(object[j].s_vec,object[i].s_vec,dirvec);
	dirvec[0] /= dist;
	dirvec[1] /= dist;
	dirvec[2] /= dist;
	force = G*object[i].mass*object[j].mass/(dist*dist);
	for(int k=0;k<3;k++){
	  object[i].f_vec[k] += force*dirvec[k];
	}
      }
    }
  }
}

void evolve(body *object, int entry, double Delta_t){
  for(int l=0;l<entry;l++){
    for(int m=0;m<3;m++){
      double acceleration_m = (object[l].f_vec[m])/(object[l].mass);
      object[l].s_vec[m] += object[l].v_vec[m]*(Delta_t) + (0.5*acceleration_m*Delta_t*Delta_t);
      object[l].v_vec[m] += acceleration_m * Delta_t;
    }
  }
}
