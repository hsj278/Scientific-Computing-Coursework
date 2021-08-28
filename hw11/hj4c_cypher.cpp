/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 11
Problem #: 1
Program Name: hj4c_cyper.cpp
Pledge Signature:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
  if(argc == 1){
    printf("Please enter the password, name of input file, and the name of output file\n");
  }
  else{
    FILE *Infile,*Outfile;
    int n = strlen(argv[1]);
    char pswd[n];
    char realpswd[] = "phys2660";
    int pswdleng = strlen("phys2660");
    int outcond = argv[3][0]; //Outcome condition for the dash

    //Assigning input password into an array
    for(int i=0;i<n;i++){
      pswd[i]=argv[1][i];
    }

    Infile = fopen(argv[2],"rb");
    Outfile = fopen(argv[3],"wb");

    //Determining the length of the string
    int j = 0;
    while(1){
      fgetc(Infile);
      if(feof(Infile)) break;
      j++;
    }
    
    fclose(Infile);
    fopen(argv[2],"rb");

    char original[j];
    int k=0;

    //Assigning characters to an array
    while(1){
      char ch = (char) fgetc(Infile);
      if(feof(Infile)) break;
      original[k] = ch;
      k++;
    }
    
    //Encrypting the message
    char encrypt[j];

    for(int l=0;l<j;l++){
      encrypt[l] = original[l]^realpswd[l%pswdleng];
    }

    //Decrypting and printing the message
    char decrypt[j];
    for(int m=0;m<j;m++){
      decrypt[m] = encrypt[m]^pswd[m%n];
      if(outcond == 45){
	printf("%c",decrypt[m]);
      }
      else{
      fputc(decrypt[m],Outfile);
      }
    }
    if(outcond == 45){
      printf("\n");
    }
    else{
    fprintf(Outfile,"\n");
    fclose(Outfile);
    }

    fclose(Infile);
    
    return 0;
  }
}
