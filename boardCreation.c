#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include "crossfireOperations.h"
int fBoard( int * count, struct slot *board, int * pSlotRowNum, int * pSlotColNum, char * pSlotType, int fBoardValue, struct slot **upLeft,struct slot **upRight, struct slot **downLeft, struct slot **downRight, struct slot *foundSlots,struct slot *currSlot){
	int row = *pSlotRowNum, column = *pSlotColNum;
	bool explored[BOARD_SIZE][BOARD_SIZE];
	//Creates the board
	if(fBoardValue == 1){
	createBoard(BOARD_SIZE, &board, upLeft, upRight, downLeft, downRight);
	}
	if(fBoardValue == 2){
	assignPlayer(BOARD_SIZE, &row, &column, pSlotRowNum, pSlotColNum, &board, pSlotType);
	} // end of creating function
	
	// searches the board
	if(fBoardValue == 3){
	//getDesiredElement(BOARD_SIZE, &row, &column);
	printf("\nSearching for adjacent slots to (%d,%d)\n", *pSlotRowNum, *pSlotColNum);
	/*If the the required slot is closer to the down-right
	 * corner of the board the search starts from downRight,
	 * which points to slot at position (boardSize-1, boarSize -1)*/
	if(row >= BOARD_SIZE/2){
	if(column >= BOARD_SIZE/2){
	currSlot = reachDesiredElement(*pSlotRowNum, *pSlotColNum, *downRight);
	}
		/*If the the required slot is closer to the down-left
		* corner of the board the search starts from downLeft,
		* which points to slot at position (boardSize-1, 0)*/
	else{
	currSlot = reachDesiredElement(*pSlotRowNum, *pSlotColNum, *downLeft);
	}
	} 
	else{
		/*If the the required slot is closer to the up-right
		* corner of the board the search starts from upRight,
		* which points to slot at position (0, boarSize -1)*/
		if(column >= BOARD_SIZE/2){
		currSlot = reachDesiredElement(*pSlotRowNum, *pSlotColNum, *upRight);
		}
		/*If the the required slot is closer to the up-left
		* corner of the board the search starts from upLeft,
		* which points to slot at position (0, 0)*/
		else {
		currSlot = reachDesiredElement(*pSlotRowNum, *pSlotColNum, *upLeft);
	}
	}
	int i,j;
	for( i=0; i<BOARD_SIZE; i++){
		for(j=0; j<BOARD_SIZE;j++){
			explored[i][j] = false;
		}
	}

	foundSlots = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
	if(currSlot!= NULL){
	findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, count, explored);
	}

	int iSlot;
	printf("\nSelect a Slot to Move To: \n");
	for(j=0; j<*count; j++){
	printf("%d. (%d,%d)\n", j+1, foundSlots[j].row, foundSlots[j].column);
	}
	scanf("%d", &iSlot);
	*pSlotRowNum = foundSlots[iSlot-1].row;
	*pSlotColNum = foundSlots[iSlot-1].column;
		int t = 0;
		t = rand() % 3; //random between 0 and 100
		if(t == 0){
		strcpy(pSlotType,"City");
		}
		if(t == 1){
		strcpy(pSlotType,"Ground");
		}
		else if(t == 2){
		strcpy(pSlotType,"Hill");
		}
	printf("\n New Slot is (%d,%d) %s\n", *pSlotRowNum, *pSlotColNum, pSlotType);
	*count = 0;
}
}
