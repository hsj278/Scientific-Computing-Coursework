#include <stdio.h>
#include <math.h>
#include "hist.hpp"

const int BIN = 50;

int main(){
  FILE *data,*back,*sig;
  int status;
  int count = 0;

  data = fopen("data.dat","r");
  back = fopen("bkgd_templates.dat","r");
  sig = fopen("signal_templates.dat","r");

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

  
  h1init(&hist1,BIN,160,500,"Sig");//Set it so that most data are present with the bins
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
  
  //Scaling the data file so that the area under the histogram equals to 1
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
  
  h1dump(&hist1,"signal.dat");
  h1dump(&hist2,"back.dat");

  return 0;
}
