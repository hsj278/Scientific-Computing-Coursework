#include <stdio.h>

unsigned long fib(unsigned long n){
  if (n<2) return 1;
  else return fib(n-1)+fib(n-2);
}

int main(){
  unsigned int nfib;
  printf("enter and integer >=0: ");
  scanf("%lu",&nfib);
  printf("Fibonacci number %d = %lu\n",nfib,fib(nfib));
  return 0;
}
