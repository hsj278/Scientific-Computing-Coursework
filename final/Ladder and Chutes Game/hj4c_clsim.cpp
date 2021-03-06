/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: FINAL
Problem #: 2
Program Name: hj4c_clsim.cpp
Pledge Signature:
 */

//The optimal starting place from 31 to 70 is 53!!!!
#include <stdio.h>
#include <stdlib.h>
#include "random.hpp"
#include "hist.hpp"

int main(int argc,char *argv[]){
  int PLAYER = atoi(argv[1]);
  int pseudo = atoi(argv[2]);
  int move = 0;
  int totalmove = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  double average;

  int players[PLAYER];
  int moves[pseudo];

  for(i=0;i<pseudo;i++){    
    move = 0;
    //Initializing players' starting point to 0 at the beginning of the game
    for(k=0;k<PLAYER;k++){
      players[k] = 0;
    }

    do{
      for(j=0;j<PLAYER;j++){
	players[j] += randui(1,6);

	//Chutes
	if(players[j] == 98 || players[j] == 95 || players[j] == 93){
	  players[j] -= 20;
	}
	if(players[j] == 87){
	  players[j] = 24;
	}
	if(players[j] == 64){
	  players[j] = 60;
	}
	if(players[j] == 56){
	  players[j] = 53;
	}
	if(players[j] == 62){
	  players[j] = 19;
	}
	if(players[j] == 47){
	  players[j] = 26;
	}
	if(players[j] == 49){
	  players[j] = 11;
	}
	if(players[j] == 16){
	  players[j] = 6;
	}

	//Ladders
	if(players[j] == 80 || players[j] == 71){
	  players[j] += 20;
	}
	if(players[j] == 28){
	  players[j] = 84;
	}
	if(players[j] == 51){
	  players[j] = 67;
	}
	if(players[j] == 36){
	  players[j] = 44;
	}
	if(players[j] == 21){
	  players[j] = 42;
	}
	if(players[j] == 9){
	  players[j] = 31;
	}
	if(players[j] == 4){
	  players[j] = 14;
	}
	if(players[j] == 1){
	  players[j] = 38;
	}

	//Finish line
	if(players[j] >= 100){
	 break;
	}
	//printf("%d\n",players[j]);
      }
      move++; //I interpreted "the average game length in number of moves" as number of rounds until one player finishes the game
    }while(players[j]<100);
    
    totalmove += move;
    moves[i] = move;
  }

  //Sorting
  int m, n, min, temp;
      for (m = 0;m<pseudo;m++){
        min = m;
        for (n=m;n<pseudo;n++){
          if(moves[n]<moves[min]){
            min = n;
          }
          temp = moves[m];
          moves[m] = moves[min];
          moves[min] = temp;
        }
      }


  average = (double)totalmove/(double)pseudo;

  printf("number of players: %d\nnumber of pseudomatches: %d\naverage game length in number of moves: %.2lf\nthe shortest game: %d\nthe longest game: %d\n",PLAYER,pseudo,average,moves[0],moves[pseudo-1]);
  
  /*
  //Found the optimal position, then printing pdf file for the position
  h1 hist1;

  h1init(&hist1,50,1,50,"53");

  j = 0;
    
    for(i=0;i<pseudo;i++){    
      move = 0;
      //Initializing players' starting point to 0 at the beginning of the game
	players[j] = 53;
      do{
	players[j] += randui(1,6);
	
	//Chutes
	if(players[j] == 98 || players[j] == 95 || players[j] == 93){
	  players[j] -= 20;
	}
	if(players[j] == 87){
	  players[j] = 24;
	}
	if(players[j] == 64){
	  players[j] = 60;
	}
	if(players[j] == 56){
	  players[j] = 53;
	}
	if(players[j] == 62){
	  players[j] = 19;
	}
	if(players[j] == 47){
	  players[j] = 26;
	}
	if(players[j] == 49){
	  players[j] = 11;
	}
	if(players[j] == 16){
	  players[j] = 6;
	}

	//Ladders
	if(players[j] == 80 || players[j] == 71){
	  players[j] += 20;
	}
	if(players[j] == 28){
	  players[j] = 84;
	}
	if(players[j] == 51){
	  players[j] = 67;
	}
	if(players[j] == 36){
	  players[j] = 44;
	}
	if(players[j] == 21){
	  players[j] = 42;
	}
	if(players[j] == 9){
	  players[j] = 31;
	}
	if(players[j] == 4){
	  players[j] = 14;
	}
	if(players[j] == 1){
	  players[j] = 38;
	}
	move++; //I interpreted "the average game length in number of moves" as number of rounds until one player finishes the game
      }while(players[j]<100);
      h1fill(&hist1,move);
    }

    h1labels(&hist1,"moves","occurrences","53");
  
    h1plot(&hist1,"53.pdf");
  */
    return 0;
  }

