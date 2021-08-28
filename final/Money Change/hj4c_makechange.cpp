#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
  //First choice: without any command, just add all the possibilities of denominations
  if(argc == 1){
    double coin;
    int count =0;
    int countsum =0;
    int f,t,o,h,q,d,n,p; //Five,two,one,half,quarter,dime,nickel,penny
    int total =0;
    int coinlist[] = {1,5,10,25,50,100,200,500};
    int c; //8 denominations

    //Floor function so that the divided number gets rounded down
    for(c=0;c<8;c++){
      coin = coinlist[c];
      for(f=0; f<=floor(coin/500);f++){
	for(t=0; t<=floor(coin/200);t++){
	  for(o=0; o<=floor(coin/100);o++){
	    for( h=0; h<=floor(coin/50);h++){
	      for( q=0; q<=floor(coin/25);q++){
		for( d=0; d<=floor(coin/10);d++){
		  for( n=0; n<=floor(coin/5);n++){
		    for( p=0;p<floor(coin);p++){
		      total = (f*500)+(t*200)+(o*100)+(h*50)+(q*25)+(d*10)+(n*5)+p;
		      if(total == coin ){
			count++;
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
      countsum += count;
    }

    printf("%d\n",countsum);
  }

  //Specified command, calculating the number of ways
  else if(atof(argv[1]) == 5 || atof(argv[1]) == 2 || atof(argv[1]) == 1 || atof(argv[1]) == 0.5 || atof(argv[1]) == 0.25 || atof(argv[1]) == 0.10 || atof(argv[1]) == 0.05 || atof(argv[1]) == 0.01){
  double coin = 100*atof(argv[1]);
  int count =0;
  int f,t,o,h,q,d,n,p; //Five,two,one,half,quarter,dime,nickel,penny
  int total =0;

  //Floor function so that the divided number gets rounded down
  for(f=0; f<=floor(coin/500);f++){
    for(t=0; t<=floor(coin/200);t++){
      for(o=0; o<=floor(coin/100);o++){
	for( h=0; h<=floor(coin/50);h++){
	  for( q=0; q<=floor(coin/25);q++){
	    for( d=0; d<=floor(coin/10);d++){
	      for( n=0; n<=floor(coin/5);n++){
		for( p=0;p<floor(coin);p++){
		  total = (f*500)+(t*200)+(o*100)+(h*50)+(q*25)+(d*10)+(n*5)+p;
		  if(total == coin ){
		    count++;
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }

  printf("%.2lf dollar\t%d\n",atof(argv[1]),count);
  }
 
  //Warning message to pick the specified denomination
  else{
    printf("Please pick specified denomination (5,2,1,0.5,0.25,0.10,0.05,0.01 dollars)\n");
  }
  return 0;
}
