/*
 * boardCreation.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "crossfireOperations.h"



/*
 * This function creates the board
 * Parameters:
 * 	size: the size of the board
 * 	upLeft: pointer of pointer to slot at position (0, 0)
 * 	upRight: pointer of pointer to slot at position (0, boardSize -1)
 * 	downLeft: pointer of pointer to slot at position (boardSsize -1, 0)
 * 	upLeft: pointer of pointer to slot at position (boardSize - 1, boardSize -1)
 */
void createBoard(int boardSize, struct slot **board, struct slot **SlotType, struct slot ***upLeft, struct slot ***upRight, struct slot ***downLeft, struct slot ***downRight){

	//The board is represented as a pointer of pointer to slots
	//This allocates in memory the space for the pointers to each row of the board
	printf("\n");
	for(int i =0; i< boardSize; i++){
		//This allocates in memory the space for the slots in each row of the board
		board[i] = malloc(boardSize * sizeof(struct slot));
		//For each slot it sets up the row and column number
		for(int j=0;j < boardSize; j++){
			board[i][j].row = i;
			board[i][j].column = j;
			printf("(%d,%d)",board[i][j].row, board[i][j].column);
		int t = 0;
		int r = 0;
		r = rand() % 100; //random between 0 and 100
		t = r % 3; // bring the value down to between 0 and number of slots specified by player
		if(t == 0){
		board[i][j].SlotType = 1;
		}
		if(t == 1){
		board[i][j].SlotType = 2;
		}
		else if(t == 2){
		board[i][j].SlotType = 3;
		}
	}
	printf("\n");
}
printf("It sets up the adjacent slots for the slots that are not at the borders. These slots have 4 adjacent elements");
	for(int i =1; i< boardSize-1; i++){
		for(int j=1;j < boardSize-1; j++){
			board[i][j].up = &board[i-1][j];
			printf("\nboard[%d][%d].up = %d",i,j, board[i-1][j]);
			board[i][j].right = &board[i][j+1];
			printf("\nboard[%d][%d].right = %d",i,j, board[i][j+1]);
			board[i][j].down = &board[i+1][j];
			printf("\nboard[%d][%d].down = %d", i,j,board[i+1][j]);
			board[i][j].left = &board[i][j-1];
			printf("\nboard[%d][%d].left = %d", i,j,board[i][j-1]);
		}
	}

	//It sets up the adjacent slots for the slots that are
	//in the first and the last row, except the slots at the edges.
	//
		printf("\n\nIt sets up the adjacent slots for the slots that are in the first row."
		"These slots don't have an adjacent element on top of them"
		"because they are on the first row of the board");
	for(int j = 0; j < boardSize -1; j++){
		board[0][j].right = &board[0][j+1];
		printf("\nboard[0][%d].right = %d",j, board[0][j+1]);
		board[0][j].left = &board[0][j-1];
		printf("\nboard[0][%d].left = %d", j,board[0][j-1]);
		board[0][j].down = &board[1][j];
		printf("\nboard[0][%d].down = %d", j,board[1][j]);
		board[0][j].up = 0;
		printf("\nboard[0][%d].up = 0",j);
		//It sets up the adjacent slots for the slots that are in the last row.
		//These slots don't have an adjacent element on down them
		// because they are on the last row of the board
		board[boardSize - 1][j].right = &board[boardSize - 1][j+1];
		printf("\nboard[boardSize - 1][%d].right = %d", j,board[boardSize - 1][j+1]);
		board[boardSize -1][j].left = &board[boardSize - 1][j-1];
		printf("\nboard[boardSize - 1][%d].left = %d", j,board[boardSize - 1][j-1]);
		board[boardSize - 1][j].up = &board[boardSize - 2][j];
		printf("\nboard[boardSize - 1][%d].up = %d", j,board[boardSize - 2][j]);
		board[boardSize - 1][j].down = 0;
		printf("\nboard[boardSize - 1][%d].down = %d",j, 0);
	}
	printf("\n\nIt sets up the adjacent slots for the slots that are"
	"in the first and the last column, except the slots at the edges");
	for(int i = 1; i < boardSize -1; i++){
		//It sets up the adjacent slots for the slots that are in the first column.
		//These slots don't have an adjacent element on the left
		// because they are on the first column of the board
		board[i][0].right = &board[i][1];
		printf("\nboard[%d][0].right = %d",i, board[i][1]);
		board[i][0].up = &board[i-1][0];
		printf("\nboard[%d][0].up = %d", i,board[i-1][0]);
		board[i][0].down = &board[i+1][0];
		printf("\nboard[%d][0].down = %d", i,board[i+1][0]);
		board[i][0].left = 0;
		printf("\nboard[%d][0].left = %d", i,0);

		//It sets up the adjacent slots for the slots that are in the last column.
		//These slots don't have an adjacent element on the right
		// because they are on the last column of the board
		board[i][boardSize-1].left = &board[i][boardSize-2];
		printf("\nboard[%d][boardSize-1]..left = %d",i, board[i][boardSize-2]);
		board[i][boardSize -1].up = &board[i -1][boardSize-1];
		printf("\nboard[%d][boardSize-1].up = %d",i, board[i -1][boardSize-1]);
		board[i][boardSize -1].down = &board[i+1][boardSize -1];
		printf("\nboard[%d][boardSize-1].down = %d",i, board[i+1][boardSize -1]);
		board[i][boardSize -1].right = 0;
		printf("\nboard[%d][boardSize-1].right = %d", i,0);
	}

		printf("\n\nIt sets up the adjacent slots for the slot at position (0,0). This only has only 2 adjacent slots: right and down");
		board[0][0].right = &board[0][1];
		printf("\nboard[0][0].right = %d", board[0][1]);
		board[0][0].down = &board[1][0];
		printf("\nboard[0][0].down = %d", board[1][0]);
		printf("\nIt sets up the adjacent slots for the slot at position (0,boardSize -1). This only has only 2 adjacent slots: left and down");
		board[0][boardSize-1].left = &board[0][boardSize-2];
		printf("\nboard[0][boardSize-1].left = %d", board[0][boardSize-2]);
		board[0][boardSize -1].down = &board[1][boardSize -1];
		printf("\nboard[0][boardSize-1].down = %d", board[1][boardSize-1]);

		printf("\nIt sets up the adjacent slots for the slot at position (boarSize -1 ,0)."
		"This only has only 2 adjacent slots: up and right");
		board[boardSize -1][0].right = &board[boardSize -1][1];
		printf("\nboard[boardSize -1][0].right = %d", board[boardSize -1][1]);
		board[boardSize -1][0].up = &board[boardSize -2][0];
		printf("\nboard[boardSize -1][0].up = %d", board[boardSize -2][0]);

		printf("\nIt sets up the adjacent slots for the slot at position (boarSize -1 ,boardSize-1)."
		"This only has only 2 adjacent slots: up and left");
		board[boardSize - 1][boardSize-1].up = &board[boardSize-2][boardSize-1];
		printf("\nboard[boardSize - 1][boardSize -1].up = %d", board[boardSize-2][boardSize-1]);
		board[boardSize - 1][boardSize -1].left = &board[boardSize -1][boardSize -2];
		printf("\nboard[boardSize - 1][boardSize -1].left = %d", board[boardSize -1][boardSize -2]);
		
printf("\n\t\t\tboard[6][0] = %d", board[6][0]);
printf("\n\t\t\tboard[boardSize - 1][0] = %d", board[boardSize - 1][0]);
printf("\n\n\nBefore Assigning board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);
printf("Before Assigning board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);
	//assigns a pointer to slot at position (0, 0)
	**upLeft = &board[0][0];
	printf("\n\n\nboard[0][0] / upLeft: %d\n", board[0][0]);

printf("\n\t\t\tafter upLeft board[6][0] = %d", board[6][0]);
printf("\n\t\t\tafter upLeft board[boardSize - 1][0] = %d", board[boardSize - 1][0]);
printf("\n\n\nafter upLeft Assigning board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);
printf("after upLeft Assigning board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);

	//assigns pointer of pointer to slot at position (0, boardSize -1)
	**upRight = &board[0][boardSize -1];
	printf("board[0][boardSize -1] / upRight: %d\n", board[0][boardSize -1]);

printf("\n\t\t\tafter upRight board[6][0] = %d", board[6][0]);
printf("\n\t\t\tafter upRight board[boardSize - 1][0] = %d", board[boardSize - 1][0]);
printf("\n\n\nafter upRight Assigning board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);
printf("after upRight Assigning board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);



	//assigns pointer of pointer to slot at position ( boardSize -1,)
	printf("\n\n\nBefore board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);
	printf("Before board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);
	**downLeft = &board[boardSize -1][0];
	printf("After board[boardSize -1][0] / downLeft: %d\n", board[boardSize -1][0]);
	printf("After board[boardSize -1][0]  / downLeft: %d\n", board[boardSize -1][0]);
	//assigns pointer of pointer to slot at position (boardSize -1, boardSize -1)
	**downRight = &board[boardSize -1][boardSize -1];
	printf("\n\nboard[boardSize -1][boardSize -1] / downRight: %d\n", board[boardSize -1][boardSize -1]);
/*	printf("\n upLeft: %d %d\n", &upLeft->column, &upLeft->row);
	printf("\n upRight: %d %d\n", &upRight->column, &upRight->row);
	printf("\n downLeft: %d %d\n", &downLeft->column, &downLeft->row);
	printf("\n downRight: %d %d\n", );
*/
}

/*
 * This function traverses the board to find a slot at a predefined
 * position (row, column). This function returns a pointer to the desired slot
 * Loaded after userInteraction.c function getDesiredElement
 * Parameters:
 * 	row: the row in which the desired slot is located
 * 	column: the column in which the desired slot is located
 * 	initialSlot: the slot from which the slot search should start
 */
struct slot * reachDesiredElement(int row, int column, struct slot * initialSlot){
	printf("\nloadded reachDesired");
	bool found = false;
	printf("\npassed bool setup");
	//printf("initial col %d\n", initialSlot->column);
	//printf("\ninitial row %d\n", initialSlot->row);
	//current slot
	struct slot * currentSlot = initialSlot;

	//prints the column and the row of the initial slot from which the search starts
	printf("Initial slot (%d, %d) -> \n", initialSlot->row, initialSlot->column);

	//while the slot is not found
	while(found == false){
		
		//if the column of the current slot is > of the column of the desired slot,
		//we move left
		if(currentSlot->column > column){
			//the current slot now points to the slot one column left
			currentSlot = currentSlot->left;
			//prints the row and the column of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);
		}

		//if the column of the current slot is < of the column of the desired slot,
		//we move right
		if(currentSlot->column < column){
			//the current slot now points to the slot one column right
			currentSlot = currentSlot->right;
			//prints the row and the column of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);
		}
		//if the row of the current slot is > of the row of the desired slot,
		//we move up
		if(currentSlot->row > row){
			//the current slot now points to the slot one row up
			currentSlot = currentSlot->up;
			//prints the column and the row of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);
		}
		//if the row of the current slot is < of the row of the desired slot,
		//we move down
		if(currentSlot->row < row){
			//the current slot now points to the slot one row down
			currentSlot = currentSlot->down;
			//prints the row and the column of the current slot
			printf("Current slot (%d, %d) -> \n",currentSlot->row,currentSlot->column);

		}
		else {
			printf("not found");
		}
		//if the current slot is at a column and a row equal to the desired column and row, respectively
		// we found the slot
		if(currentSlot->column == column){
			printf("\nFound Column\n");
		}
		if(currentSlot->row == row){
			printf("Found Row\n");
		}
		if(currentSlot->column == column && currentSlot->row == row){
			printf("Found\n");
			found = true;
		}
	}
	//returns the found slot
	return currentSlot;
}

/*
 * The recursive function that traverses the board to find the slots at a predefined
 * distance from the current slot and place them in foundSlots.
 * Parameters:
 * 	reqDist: the required distance from the starting slot
 * 	currDist: the distance of the current slot from the starting slot
 * 	currSlot: a pointer to the current slot that is traversed
 * 	foundSlots: the array of slots that are at a required distance from the starting slot
 * 	count: pointer to an integer representing the number of slots that are found to be at a required distance from the starting slot
 * 	explored: matrix indicating for each slot at row x and column y has been traversed (true) or not (false)
 */
void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[BOARD_SIZE][BOARD_SIZE]){



	//The base case: the current slot is at the required distance from the starting slot
	if(currDist == reqDist){
		printf("\nAlert1\n");
		//the current slot was not explored
		if(explored[currSlot->row][currSlot->column] == false){
			printf("\nAlert2\n");
			//The next availbale position (indicated by count) at foundSlots points to the current slot
			*(foundSlots + *count) = *currSlot;
			//the counter is incremented
			(*count)++;
			//the matrix of the explored slots set to true the element at the row and column of the current slot
			explored[currSlot->row][currSlot->column] = true;
		}
	}
	//The recursive call: the current slot is at a distance that is less than the required distance (more slots still have to be traversed)
	else{
		printf("\nAlert3\n");
		//if the current slot has the up slot != NULL (i.e. the slot is not in the first row)
		if(currSlot->up != NULL){
			printf("\nAlert4\n");
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the up slot
			findSlots(reqDist, currDist +1,  currSlot->up, foundSlots, count, explored);
		}
		//if the current slot has the right slot != NULL (i.e. the slot is not in the last column)
		if(currSlot->right != NULL){
			printf("\nAlert5\n");//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the right slot
			findSlots(reqDist, currDist +1,  currSlot->right, foundSlots, count, explored);
		}
		//if the current slot has the down slot != NULL (i.e. the slot is not in the last row)
		if(currSlot->down != NULL){
			printf("\nAlert6\n");
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the down slot
			findSlots(reqDist, currDist +1,  currSlot->down, foundSlots, count, explored);
		}
		//if the current slot has the left slot != NULL (i.e. the slot is not in the first column)
		if(currSlot->left != NULL){
			printf("\nAlert7\n");
			//invokes function find slots incrementing the current Distance (currDist) and setting the current slot to the left slot
			findSlots(reqDist, currDist +1,  currSlot->left, foundSlots, count, explored);
		}

	}


}





