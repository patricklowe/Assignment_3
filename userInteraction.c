/*
 * userInteraction.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */

#include <stdio.h>
#include "crossfireOperations.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

//This function returns the board size provided as input by the user
int getBoardSize(){
	int boardSize;
	printf("Please enter the required size of the board\n");
	//asks the user to enter the desired board size
	scanf("%d", &boardSize);
	return boardSize;
}

//THis function takes as input the size of the board and the pointers
// to the integers representing the row and the column of the slot that
// the user want to retrieve
////////changing to assign players to element slot.
void getDesiredElement(int boardSize, int * row, int * col, int * pSlotRowNum, int * pSlotColNum, char * pSlotType){
		int r=0;
		//it will cycle asking the user to insert the row
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			//printf("Row: ");
			r = rand() % 100; //random between 0 and 100
			*row = r % boardSize; // bring the value down to between 0 and number of slots specified by player
			*pSlotRowNum = *row;
			//printf("(%d,", *row);
		//	if(row < 0 && *row >= boardSize)
		//		printf("Error: Incorrect row dimension\n");
		} while(*row < 0 && *row >= boardSize);
		r = 0;
		//it will cycle asking the user to insert the column
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			r = rand() % 100; //random between 0 and 100
			*col = r % boardSize; // bring the value down to between 0 and number of slots specified by player
			*pSlotColNum = *col;
			//printf("%d)\n", *col);
		//	if(*col < 0 && *col >= boardSize)
		//		printf("Error: Incorrect column dimension\n");
		} while(*col < 0 && *col >= boardSize);
		
		int t = 0;
		r = 0;
		r = rand() % 100; //random between 0 and 100
		t = r % 3; // bring the value down to between 0 and number of slots specified by player
		
		if(t == 1){
			strcpy(pSlotType,"Ground");
		}
		if(t == 2){
			strcpy(pSlotType,"City");
		}
		else if(t == 0){
			strcpy(pSlotType,"Hill");
		}
}

