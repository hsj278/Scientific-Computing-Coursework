/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: FINAL
Problem #: 3
Program Name: hj4c_chi2fit.cpp
Pledge Signature:
 */

#include <stdio.h>
#include <math.h>
#include "hist.hpp"

const int BIN = 50;
const int PRECISION = 1000;

int main(){
  FILE *data,*back,*sig;
  int status;
  int count = 0;

  data = fopen("data.dat","r");
  back = fopen("bkgd_templates.dat","r");
  sig = fopen("signal_templates.dat","r");

  //Reading in the data file
//Determining how many data lines there are to determine the number of elements in arrays
  while(1){
    status = fgetc(data); 
    if(status == '\n') count++;
    if(status == EOF) break;
  }

  count = count-9; //Disregarding the 9 words on the top of data.dat

  fclose(data);
  fopen("data.dat","r");

  double etjet1[count],etjet2[count],etjet3[count],eta1[count],eta2[count],eta3[count],met[count],ht[count],njet[count];

  h1 hist1,hist2,hist3;
  int n = 0;
  int c = 0;
  double total = 0;
  
  h1init(&hist1,BIN,160,500,"Sig");
  h1init(&hist2,BIN,160,500,"Back");
  h1init(&hist3,BIN,160,500,"Data");
  

  while(1){
    status = fgetc(data);
    if(status == '\n') c++;
    if(c == 9) break;
  }
    
  while(1){
    status = fscanf(data,"%lf %lf %lf %lf %lf %lf %lf %lf %lf\n",&etjet1[n],&etjet2[n],&etjet3[n],&eta1[n],&eta2[n],&eta3[n],&met[n],&ht[n],&njet[n]);
    h1fill(&hist3,ht[n]);
    total += ht[n];
    if(status == EOF) break;
    n++;
  }
  

  //Reading in Signal data
  int counts = 0;
  
  while(1){
    status = fgetc(sig); 
    if(status == '\n') counts++;
    if(status == EOF) break;
  }

  counts = counts-9;
  
  fclose(sig);
  fopen("signal_templates.dat","r");

  c = 0;
  n = 0;
  
  double etjets1[counts],etjets2[counts],etjets3[counts],etas1[counts],etas2[counts],etas3[counts],mets[counts],hts[counts],njets[counts];
  double totals = 0;
  
  while(1){
    status = fgetc(sig);
    if(status == '\n') c++;
    if(c == 9) break;
  }

  while(1){
    status = fscanf(sig,"%lf %lf %lf %lf %lf %lf %lf %lf %lf\n",&etjets1[n],&etjets2[n],&etjets3[n],&etas1[n],&etas2[n],&etas3[n],&mets[n],&hts[n],&njets[n]);
    totals+=hts[n];
    h1fill(&hist1,hts[n]);
    if(status == EOF) break;
    n++;
  }
 
  fclose(sig);
   
  //Reading in the background data
  int countb = 0;
  
  while(1){
    status = fgetc(back); 
    if(status == '\n') countb++;
    if(status == EOF) break;
  }

  countb = countb-9;
  
  fclose(back);
  fopen("bkgd_templates.dat","r");

  c = 0;
  n = 0;
  
  double etjetb1[countb],etjetb2[countb],etjetb3[countb],etab1[countb],etab2[countb],etab3[countb],metb[countb],htb[countb],njetb[countb];
  double totalb = 0;
  
  while(1){
    status = fgetc(back);
    if(status == '\n') c++;
    if(c == 9) break;
  }

  while(1){
    status = fscanf(back,"%lf %lf %lf %lf %lf %lf %lf %lf %lf\n",&etjetb1[n],&etjetb2[n],&etjetb3[n],&etab1[n],&etab2[n],&etab3[n],&metb[n],&htb[n],&njetb[n]);
    totalb += htb[n];
    h1fill(&hist2,htb[n]);
    if(status == EOF) break;
    n++;
  }

  fclose(back);
  
  h1dump(&hist3,"datas.dat");
  h1dump(&hist1,"signal.dat");
  h1dump(&hist2,"back.dat");
  
  //Normalizing
  //Data file
  FILE *dat2;
   c=0;
   n=0;
  int bind[BIN],yd[BIN];
  double xd[BIN], eyd[BIN];
  double totald = 0;

  dat2 = fopen("datas.dat","r");

  while(1){
    status = fgetc(dat2);
    if(status == '\n') c++;
    if(c == 7) break;
  }
  
  while(1){
    status = fscanf(dat2,"%d\t%lf\t%d\t%lf\n",&bind[n],&xd[n],&yd[n],&eyd[n]);
    totald += yd[n];
    if(status == EOF) break;
    n++;
  }

  double datnorm[BIN];

  for(int z=0;z<BIN;z++){
    datnorm[z] = ((double)yd[z]/totald)*count;
  }

  
  //h1 hist4,hist5;

  //h1init(&hist4,BIN,160,500,"Signorm");
  //h1init(&hist5,BIN,160,500,"Backnorm");

  //Signal
  FILE *sig2,*sigout;
   c=0;
   n=0;
  int bin2[BIN],y2[BIN];
  double x2[BIN], ey2[BIN];
  double total2 = 0;

  sig2 = fopen("signal.dat","r");
  sigout = fopen("finalsignorm.dat","w");

  while(1){
    status = fgetc(sig2);
    if(status == '\n') c++;
    if(c == 7) break;
  }
  
  while(1){
    status = fscanf(sig2,"%d\t%lf\t%d\t%lf\n",&bin2[n],&x2[n],&y2[n],&ey2[n]);
    total2 += y2[n];
    if(status == EOF) break;
    n++;
  }

  double signorm[BIN];

  for(int i=0;i<BIN;i++){
    signorm[i] = ((double)y2[i]/total2)*count;
    fprintf(sigout,"%d %lf\n",i,signorm[i]);
    //h1fill(&hist4,signorm[i]);
  }

  fclose(sigout);
  //h1dump(&hist4,"finalsignorm.dat");

  //Background
  FILE *back2,*backout;
  c=0;
  n=0;
  int bin3[BIN],y3[BIN];
  double x3[BIN], ey3[BIN];
  double total3 =0;

  back2 = fopen("back.dat","r");
  backout = fopen("finalbacknorm.dat","w");

  while(1){
    status = fgetc(back2);
    if(status == '\n') c++;
    if(c == 7) break;
  }
  
  while(1){
    status = fscanf(back2,"%d\t%lf\t%d\t%lf\n",&bin3[n],&x3[n],&y3[n],&ey3[n]);
    total3 += y3[n];
    if(status == EOF) break;
    n++;
  }

  double backnorm[BIN];

  for(int j=0;j<BIN;j++){
    backnorm[j] = ((double)y3[j]/total3)*count;
    fprintf(backout,"%d %lf\n",j,backnorm[j]);
    //  h1fill(&hist5,backnorm[j]);
  }

  fclose(backout);
  //h1dump(&hist5,"finalbacknorm.dat");

  //CHI SQUARED TEST
  double chi2=0;
  FILE *htdat;
  c=0;
  n=0;

  htdat = fopen("Ht.dat","r");
  
  int bin[BIN];
  double x[BIN];
  int y[BIN];
  double ey[BIN];

  while(1){
    status = fgetc(htdat);
    if(status == '\n') c++;
    if(c == 7) break;
  }

  while(1){
    status = fscanf(htdat,"%d\t%lf\t%d\t%lf\n",&bin[n],&x[n],&y[n],&ey[n]);
    if(status == EOF) break;
    n++;
  }
  
  //Calculating chi squared assuming 50/50 mix; therefore, fs=0.5, fb=0.5
  for(int k=0;k<BIN;k++){
    if(yd[k] != 0){
      chi2 += pow((yd[k]-(0.5*backnorm[k]+0.5*signorm[k]))/(0.5*backnorm[k]+0.5*signorm[k]),2);
    }
  }
  
  printf("Chi squared assuming fb and fs are 50/50 mix is: %lf\n",chi2);
  
  //Calculating lowest chi squared with fs and fb
  double fb;
  double fbmin[PRECISION];
  double fsmin[PRECISION];
  double chimin[PRECISION];
  double chi[PRECISION];

  for(int m=0;m<PRECISION;m++){
    chi2 = 0;
    fb = (double)m/PRECISION; //fb with precision of 0.1%
  for(int l=0;l<BIN;l++){ 
    if(yd[l] != 0){
	chi2 += pow((yd[l]-(fb*backnorm[l]+(1-fb)*signorm[l]))/(fb*backnorm[l]+(1-fb)*signorm[l]),2);
	chi[m] = chi2;
	chimin[m] = chi2;
	fbmin[m] = fb;
	fsmin[m] = 1-fb;
      }
    }
  }
  
  //Sort to find minimum
  int s, t, min;
  double temp;
  for (s = 0;s<PRECISION;s++){
    min = s;
    for (t=s;t<PRECISION;t++){
      if(chimin[t]<chimin[min]){
	min = t;
      }
      temp = chimin[s];
      chimin[s] = chimin[min];
      chimin[min] = temp;
    }
  }
  
  //Looking for fb and fs based on sorted array
  int fmin = 0;
  for(int q=0;q<PRECISION;q++){
    if(chi[q] == chimin[0]){
      fmin = q;
    }
  }
 
  printf("fs: %.3lf \t fb: %.3lf \t minimum chi squared: %lf\n",fsmin[fmin],fbmin[fmin],chimin[0]);

  fclose(htdat);
  fclose(sig2);
  fclose(back2);
  fclose(dat2);


  return 0;
}
