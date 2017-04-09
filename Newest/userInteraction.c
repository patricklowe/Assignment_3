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
//changing to assign players to element slot.
void assignPlayer(int boardSize, int * row, int * col, int * pSlotRowNum, int * pSlotColNum,struct slot ** board, char * pSlotType){
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
		
		if(board[*pSlotRowNum][*pSlotColNum].SlotType == 1){
		strcpy(pSlotType,"Hill");
		}
		
		if(board[*pSlotRowNum][*pSlotColNum].SlotType == 2){
		strcpy(pSlotType,"Ground");
		}
		
		else if(board[*pSlotRowNum][*pSlotColNum].SlotType == 3){
		strcpy(pSlotType,"City");
		}
}

//THis function takes as input the size of the board and the pointers
// to the integers representing the row and the column of the slot that
// the user want to retrieve
void getDesiredElement(int boardSize, int * row, int * col){
	printf("Please enter the Row of the desired slot \n");
	printf("Note that size of the board is %d\n", boardSize);

		//it will cycle asking the user to insert the row
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Row: ");
			scanf("%d", row);
			printf("%d\n", *row);
			if(row < 0 && *row >= boardSize)
				printf("Error: Incorrect row dimension\n");
		} while(*row < 0 && *row >= boardSize);

		//it will cycle asking the user to insert the column
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Please enter the Column of the desired slot \n");
			printf("Column: ");
			scanf("%d", col);
			printf("%d\n", *col);
			if(*col < 0 && *col >= boardSize)
				printf("Error: Incorrect column dimension\n");
		} while(*col < 0 && *col >= boardSize);
}
