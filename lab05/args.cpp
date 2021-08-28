#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){ 
  int i;
  printf("%d arguments were entered at the command line\n\n",argc-1);
  /* print all command line arguments as strings */
  for (i=0; i<argc ;i++) 
    printf("argv[%d] = %s\n",i,argv[i]);
  printf("\n");
  /* translate arguments into ints and print */
  for (i=1; i<argc ;i++)
     printf("atoi(argv[%d]) = %d\n",i,atoi(argv[i]));
  printf("\n");
  /* translate arguments into floats and print */
  for (i=1; i<argc ;i++)
    printf("atof(argv[%d]) = %lf\n",i,atof(argv[i]));
}
