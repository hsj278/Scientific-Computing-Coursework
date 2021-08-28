#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int n;
  double x[MAX_SIZE];

  srand(time(NULL));
  for(n=0;n<15;n++){
    x = rand();
    printf("%d,\n",&x[n];
  }
  return 0;
}
