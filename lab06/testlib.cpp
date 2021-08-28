#include <stdio.h>
#include <stlib.h>
#include "mcomplex.hpp"

int main(){

  Complex *z;
  z -> re = 5;
  z -> im = 3;

  printf("The conjugate is %lf\n",complex_conjugate(&z));
  printf("The magnitude is %lf\n",magnitude(&z));
  printf("The complex number you gave is %d\n",print(&z));

  return(0);
}
