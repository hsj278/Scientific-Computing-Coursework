/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 6
Problem #: 1
Program Name: hj4c_wordstats.cpp
Pledge Signature:
 */

#include <stdio.h>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include "hist.hpp"

void noPunctuation(char word[]);

h1 hist1,hist2;

int main(){
  int status = 0;
  FILE *inp,*outp,*outp2;
  char word[50];

  inp = fopen("alice.txt","r");
  outp = fopen("alice_letter.txt","w");
  outp2 = fopen("alice_word.txt","w");

  h1init(&hist1,0.5,50.5);
  h1init(&hist2,0.5,50.5);

  while(status != EOF){
      status = fgetc(inp);
      if(status >= 65 && status <= 90){
	status = status-64;
        fprintf(outp,"%d\n",status);
	h1fill(&hist1,status);
      }
      else if(status >= 97 && status <= 122){
	status = status-96;
	fprintf(outp,"%d\n",status);
	h1fill(&hist1,status);
      }
  }
  fclose (inp);
  
  inp = fopen("alice.txt","r");
  status = 0;

  for(int n=0;n<50;n++){
    while(status != EOF){
      status = fscanf(inp,"%s",&word);
      noPunctuation(word);
    }
  }
    
  fclose (inp);
  fclose (outp);
  fclose (outp2);

  h1plot(&hist1,"");
  h1plot(&hist1,"character.pdf");
  h1plot(&hist2,"");
  h1plot(&hist2,"words.pdf");
  return 0;
}

void noPunctuation(char word[]){
  int n;
  char noPunc[strlen(word)];
  int k=0;
  char* common[50] = {"the","be","to","of","and","a","in","that","have","I","it\
","for","not","on","with","he","as","you","do","at","this","but","his","by","fr\
om","they","we","say","her","she","or","an","will","my","one","all","would","th\
ere","their","what","so","up","out","if","about","who","get","which","go","me"}\
  ;

  for(unsigned int j=0;j<strlen(word);j++){
    if(ispunct(word[j]) == 0){
      noPunc[k] = word[j];
      k++;
    }
  }
  noPunc[k] = '\0';
  strcpy(word,noPunc);
    for(n=0;n<50;n++){
  if(strcasecmp(word,common[n])==0){
    h1fill(&hist2,n+1);
  }
    }
}
