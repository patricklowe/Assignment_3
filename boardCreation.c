/*
 * main.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */


#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"
int fBoard(struct slot *board,int * pSlotRowNum, int * pSlotColNum, char * pSlotType, int fBoardValue, struct slot **upLeft,struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot *SlotType,struct slot *foundSlots,struct slot *currSlot){
	int row = *pSlotRowNum, column = *pSlotColNum;
	bool explored[BOARD_SIZE][BOARD_SIZE];
	int count =0;
	
	//Creates the board
	if(fBoardValue == 1){
	createBoard(BOARD_SIZE, &board, &SlotType, &upLeft, &upRight, &downLeft, &downRight);
	}
	
	if(fBoardValue == 2){
	assignPlayer(BOARD_SIZE, &row, &column, pSlotRowNum, pSlotColNum, &board, pSlotType);
	} // end of creating function
	
	// searches the board
	else if(fBoardValue == 3){
	//getDesiredElement(BOARD_SIZE, &row, &column);
	printf("\nSearching for adjacent slots to %d %d\n", *pSlotRowNum, *pSlotColNum);
	/*If the the required slot is closer to the down-right
	 * corner of the board the search starts from downRight,
	 * which points to slot at position (boardSize-1, boarSize -1)*/
	if(row >= BOARD_SIZE/2){
		if(column >= BOARD_SIZE/2){
			printf("\nhere1");
			printf("\ndownRight %d", *downRight);
		currSlot = reachDesiredElement(*pSlotRowNum, *pSlotColNum, *downRight);
		printf("\nhere2");
	}
		/*If the the required slot is closer to the down-left
		* corner of the board the search starts from downLeft,
		* which points to slot at position (boardSize-1, 0)*/
	else{
		printf("\nhere3");
		printf("\ndownLeft %d", *downLeft);
	currSlot = reachDesiredElement(*pSlotRowNum, *pSlotColNum, *downLeft);
	printf("\nhere4");
	}
	} 
	else{
		/*If the the required slot is closer to the up-right
		* corner of the board the search starts from upRight,
		* which points to slot at position (0, boarSize -1)*/
		if(column >= BOARD_SIZE/2){
		printf("\nhere5");
		printf("\nupRight %d", upRight);
		currSlot = reachDesiredElement(*pSlotRowNum, *pSlotColNum, *upRight);
		printf("\nhere6");
		}
		/*If the the required slot is closer to the up-left
		* corner of the board the search starts from upLeft,
		* which points to slot at position (0, 0)*/
		else {
		printf("\nhere7");
		printf("\nupLeft %d", upLeft);
		currSlot = reachDesiredElement(*pSlotRowNum, *pSlotColNum, *upLeft);
	printf("\nhere8");
	}
	}
printf("here9");
	int i,j;
	for( i=0; i<BOARD_SIZE; i++){
		for(j=0; j<BOARD_SIZE;j++){
			explored[i][j] = false;
		}
	}


	foundSlots = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
	printf("\n\nFunction findSlotsinvoked:\n");

	if(currSlot!= NULL){
		printf("\nalarm 0");
		//invokes function findSlots. The required distance is a constant
		//However you can reuse this function providing as input any arbitrary distance
		findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
		printf("\nalarm 1");
		for( i=0; i<count; i++){
			printf("(%d, %d)-> ",foundSlots[i].row, foundSlots[i].column);
		}
		printf("\nalarm 2");
	}

	return 0;
}
}


