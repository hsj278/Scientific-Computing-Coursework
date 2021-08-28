#include <stdio.h>
#include <math.h>
#include "hist.hpp"

const int BIN = 50;

int main(int argc, char *argv[]){
  FILE *inp;
  int status1;
  int status;
  int count = 0;

  inp = fopen(argv[1],"r");

  //Determining how many data lines there are to determine the number of elements in arrays
  while(1){
    status1 = fgetc(inp); 
    if(status1 == '\n') count++;
    if(status1 == EOF) break;
      }

  count = count-9; //Disregarding the 9 words on the top of data.dat

  fclose(inp);
  fopen(argv[1],"r");

  double etjet1[count],etjet2[count],etjet3[count],eta1[count],eta2[count],eta3[count],met[count],ht[count],njet[count];

  h1 hist1, hist2;
  int n = 0;
  int c = 0;
  double total = 0;

  h1init(&hist1,BIN,160,500,"Ht");
  h1init(&hist2,BIN,160,500,"Ht normalized");

  while(1){
    status = fgetc(inp);
    if(status == '\n') c++;
    if(c == 9) break;
  }
    
  while(1){
    status = fscanf(inp,"%lf %lf %lf %lf %lf %lf %lf %lf %lf\n",&etjet1[n],&etjet2[n],&etjet3[n],&eta1[n],&eta2[n],&eta3[n],&met[n],&ht[n],&njet[n]);
    h1fill(&hist1,ht[n]);
    total += ht[n];
    if(status == EOF) break;
    n++;
  }
  
    //Scaling the data file so that the area under the histogram equals to 1
  double hts1[count];
  double totals1 = 0;

  for(int i=0;i<count;i++){
    hts1[i] = ht[i]/total;
    totals1 += hts1[i];
  }

  //Scaling the data file so that the area under the histogram equals to the number of observed
  double hts2[count];
  double totals2 = 0;
 
  for(int j=0;j<count;j++){
    hts2[j] = hts1[j]*count;
    h1fill(&hist2,hts2[j]);
    totals2 += hts2[j];
  }

  printf("%lf\n",totals2);

  fclose(inp);


  //h1dump(&hist1,argv[2]);
  //h1dump(&hist2,argv[2]);
  //h1dump_entries(&hist1,argv[3]);

  h1plot(&hist1);
  h1plot(&hist2);

  return 0;
}
