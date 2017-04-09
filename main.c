//	include files - library
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

void playerCreate();
void humanAttributes(int a); //function for human Attributes
void ogreAttributes(int a);//function for Ogre Attributes
void elfAttributes(int a);//function for Elf Attributes
void wizardAttributes(int a);//function for Wizard Attributes
void fAssign();
void fOption();
//void moveForward(int i);
//void moveBack(int i);
void CapabilitiesChange(int i);
void fAttack(int i);
int nearestPlayer(int i);
void fContinue();
void close();
int fBoard();
int numSlots; // Stores the number of Slots, Max = 20 & Minimum = number of players
int playerLimit;//sets player limit to 6

//  Structure for player attributes
struct attributes {
	char pName[20]; // Player Name
	char pType[6]; // Player Type
	float lifePoints; //Health
	int smart;
	int strength;
	int magic;
	int luck;
	int dexterity;
	int pSlotRowNum; //current slot number
	int pSlotColNum; //current slot number
	char pSlotType[6];// current slot type
}; // End of structure

// attributes for zones (slots)
struct zone{
	char pSlotType[7]; //stores slot type
	int pSlotNum; // slot number, before being assigned to a player
	int occupied;//0 indicates slot is not occupied, 1 indicates slot is occupied
};

struct attributes player[6];
struct zone slots[20];




int main(void){

srand (time (NULL));

playerCreate();

fAssign();

fOption();

}

void playerCreate(){
int i;
printf("- - - - - - - - - - - - - - - - Crossfire - - - - - - - - - - - - - - -\n");
printf("- - - - - - - - - - - - - - - - Player Creation - - - - - - - - - - - -\n\n");

printf("\tHow many players are there: ");
scanf("%d", &playerLimit);

if(playerLimit>6) {//if user input exceeds the 6 player limit set it to max
	playerLimit = 6;//set the limit to 6
	printf("\n\tMaximum Players exceeded, Setting Players to 6!\n");
}
	else if(playerLimit<2){// prevents 1 player or less being entered as its a multiplayer game
		playerLimit = 2;//set the limit to 2
		printf("\n\tMinimum number of Players required, Setting Players to 2!\n");
	}

		for(i=1; i<=playerLimit; i++){//loop to set each characters attributes
			printf("- - - - - - - - - - - - - - - - Player[%d] Creation - - - - - - - - - -\n", i);
			printf("- - - - - - - - - - - - Types: Human - Elf - Ogre - Wizard - - - - - - - - -\n\n");

			printf("Enter Player[%d] Name: ",i);
			scanf("%s",player[i].pName); // stores up to 7 characters in player name

			printf("Enter Player[%d] Type: ", i);
			scanf("%s",player[i].pType); // stores player type

			while((strcmp(player[i].pType,"Human")!=0)&&(strcmp(player[i].pType,"Ogre")!=0)&&(strcmp(player[i].pType,"Elf")!=0)&&(strcmp(player[i].pType,"Wizard")!=0)){
				printf("The Player Types Are: Human - Elf - Ogre - Wizard\nEnter Player[%d] Type:", i);
				scanf("%s",player[i].pType); // stores player type
			}

				if(strcmp(player[i].pType,"Human")==0){
					humanAttributes(i);//when the character is a human call function to give this character attributes of a human
					}

				else if(strcmp(player[i].pType,"Ogre")==0){
					ogreAttributes(i);//when the character is an ogre call function to give this character attributes of an ogre
				}

				else if(strcmp(player[i].pType,"Elf")==0){
					elfAttributes(i);//when the character is an elf call function to give this character attributes of an elf
				}

				else if(strcmp(player[i].pType,"Wizard")==0){
					wizardAttributes(i);//when the character is a wizard call function to give this character attributes of a wizard
				}
		}

	printf("- - - - - - - - - - - - - - - - Player Details  - - - - - - - - - - - -\n\n");
	printf("Player Info\n");
	printf("\tName\t\t\tType\tHealth\tSmart\tStrength\tMagic\tLuck\tDexterity");

	for(i=1; i<=playerLimit; i++) // loop through players, printing details
	{
	printf("\n%d\t%s\t\t\t%s\t%.2f\t%d\t%d\t\t%d\t%d\t%d",i,player[i].pName,player[i].pType,player[i].lifePoints,player[i].smart,player[i].strength,player[i].magic,player[i].luck,player[i].dexterity);
	}
}

//sets the random attributes for a human
void humanAttributes(int a){
//	srand(time(NULL));
	player[a].lifePoints = 100.00;//life points set at 100
	player[a].smart=rand() % (100 +1 -1) + 1;//random numer between 1 and 100
	player[a].strength=rand() % (100 +1 -1) + 1;//random numer between 1 and 100
	player[a].magic=rand() % (100 +1 -1) + 1;//random numer between 1 and 100
	player[a].luck=rand() % (100 +1 -1) + 1;//random numer between 1 and 100
	player[a].dexterity=rand() % (100 +1 -1) + 1;//random numer between 1 and 100
	if((player[a].smart+player[a].strength+player[a].magic+player[a].luck+player[a].dexterity)>=300){
		humanAttributes(a);
	}
}
//sets the random attributes for an ogre
void ogreAttributes(int a){
	player[a].lifePoints = 100;//life points set at 100
	player[a].magic=0;//magic set at 0
	player[a].strength=rand() % (100 + 1 - 80) + 80;//random number between 80 and 100
	player[a].dexterity=rand() % (100 + 1 - 80) + 80;//random number between 80 and 100

	while((player[a].luck+player[a].smart)>50){//ensures sum of luck and smartness is <=50
	player[a].luck=rand() % (50 + 1 - 0) + 0;
	player[a].smart=rand() % (20 + 1 - 0) + 0;
	}
}
//sets the random attributes for an elf
void elfAttributes(int a){
	player[a].lifePoints = 100;//life points set at 100
	player[a].luck=rand() % (100 + 1 - 60) + 60;//random number between 60 and 100
	player[a].smart=rand() % (100 + 1 - 70) + 70;//random number between 70 and 100
	player[a].strength=rand() % (50 + 1 - 1) + 1;//random number between 1 and 50
	player[a].magic=rand() % (79 + 1 - 51) + 51;//random number between 79 and 51
	player[a].dexterity=rand() % (100 +1 -1) + 1;//random number between 1 and 100
}
//sets the random attributes for a wizard
void wizardAttributes(int a){
	player[a].lifePoints = 100;//life points set at 100
	player[a].luck=rand() % (100 + 1 - 50) + 50;//random number between 50 and 100
	player[a].smart=rand() % (100 + 1 - 90) + 90;//random number between 90 and 100
	player[a].strength=rand() % (20 + 1 - 1) + 1;//random number between 1 and 20
	player[a].magic=rand() % (100 + 1 - 80) + 80;//random number between 80 and 100
	player[a].dexterity=rand() % (100 +1 -1) + 1;//random number between 1 and 100
}



// Assign players to slots
void fAssign(){
	printf("\n\n- - - - - - - - - - - - - - - - Player Assigning  - - - - - - - - - - -\n\n");
	int i;

	for(i=1; i<=playerLimit; i++){
	fBoard(&player[i].pSlotRowNum, &player[i].pSlotColNum, &player[i].pSlotType);
	printf("%s has been assigned to Slot: (%d,%d) %s\n", player[i].pName, player[i].pSlotRowNum,player[i].pSlotColNum, player[i].pSlotType);// Prints Plyaer name, SLot number from previous function, and slot type
	}
}

// Options for current player to Attack or Move Slot
void fOption(){

int iSwap, i, j;

	for(i=1; i<=playerLimit; i++){

		printf("\n\n- - - - - - - - - - - - - - - - Player %d Options - - - - - - - - - - -\n\n",i);

		int bR = player[i].pSlotRowNum; // hold current player position, before moving backward
		int bC = player[i].pSlotColNum;
		--bR;//moves backwards 2 saces to accurately represent 1 space in the interface
		--bC;
		
		int fR= player[i].pSlotRowNum; // hold current player position, before moving forward
		int fC= player[i].pSlotColNum; // hold current player position, before moving forward
		++fR; // moves player forward 1 space
		++fC; // moves player forward 1 space

		printf("\t\tPlease Select an Option for Player[%d]: %s\n", i, player[i].pName);

		printf("\nCurrent Slot: (%d,%d)\n", player[i].pSlotRowNum, player[i].pSlotColNum);

		printf("\n\t 1. Move Forward\n");
		printf("\t 2. Move Backwards\n");
		printf("\t 3. Attack Nearest Player\n");

		for(j=1; j<=playerLimit;j++){
		printf("%s (%s, %.2f)\n", player[j].pName, player[j].pType, player[j].lifePoints);
		}

		printf("\nOption: ");
		scanf("%d", &iSwap);

		if(iSwap == 1){
			//moveForward(i); //move current player forwards
		}

		else if(iSwap == 2){
			//moveBack(i);//move current player backwards
		}

		else if(iSwap ==3){
			fAttack(i);//attack the nearest player
		}

		else{
			printf("Invalid Entry!");
		}
	}
fContinue();
}

//moving current player forward 1 slot if not occuppied
/*void moveForward(int i){
	printf("Moving Player %s Forwards.\n", player[i].pName);

	int f= player[i].pSlotNum; //f is the current slot number, will be incremented
	slots[f].occupied=0;//no longer occupied
	f = f+1;//incrementing player slot didn't work, reassigned to f after increasing
	player[i].pSlotNum = f;//player i's slot position changes to the slot behind
	strcpy(player[i].pSlotType, slots[f].pSlotType);//player i's slot position changes to the slot behind
	slots[f].occupied=1;//becomes occupied
	printf("\nPlayer %s has is now in Slot[%d]: %s", player[i].pName, player[i].pSlotNum,player[i].pSlotType);
	CapabilitiesChange(i);//load function to update players capabilities based on new slot
}

//Moving current player back 1 slot if not occuppied
void moveBack(int i){
	printf("Moving Player %s Backwards.", player[i].pName);

	int b= player[i].pSlotNum;//b is the current players slot
	slots[b].occupied=0;//no longer occupied
	b = b-1;// decremented b (--b) didn't work in testing, so reassigned to b after decreasing
	player[i].pSlotNum = b;//player i's slot position changes to the slot behind
	strcpy(player[i].pSlotType, slots[b].pSlotType);//player i's slot position changes to the slot behind
	slots[b].occupied=1;//becomes occupied
	printf("\nPlayer %s has is now in Slot[%d]: %s", player[i].pName, player[i].pSlotNum,player[i].pSlotType);
	CapabilitiesChange(i);
}

//function changes the capabilities of a player that moves
void CapabilitiesChange(int i){
	if(strcmp(player[i].pSlotType, "Hill")==0){
		if(player[i].dexterity<50){
			player[i].strength -= 10;
			printf("\n%s has lost 10 Strength from moving Slot!", player[i].pName);
		}
		else if(player[i].dexterity>=60){
			player[i].strength += 10;
			printf("\n%s has gained 10 Strength from moving Slot!\n", player[i].pName);
		}
	}

	else if(strcmp(player[i].pSlotType, "City")==0){
		if(player[i].smart>60){
			player[i].magic += 10;
			printf("\n%s has gain 10 Magic from moving Slot!", player[i].pName);
		}
		else if(player[i].smart<=50){
			player[i].dexterity -= 10;
			printf("\n%s has lost 10 Dexterity from moving Slot!\n", player[i].pName);
		}
	}

	else {
		printf("\nNo changes to Player Attributes.\n");
	}
}*/

// Function when Attacking a player
void fAttack(int i){//reduces life points when attack is preformed

	int n = nearestPlayer(i); // n is the player being attacked
	float damage;

	if(player[n].strength<=70){
		printf("%s has %.2f health before being attacking\n", player[n].pName, player[n].lifePoints);
		damage = (0.5)*player[n].strength;
		player[n].lifePoints = player[n].lifePoints - (0.5)*player[n].strength;
		printf("Critical Strike - %.2f\n", damage);
		printf("%s has %.2f health after being attacking\n", player[n].pName, player[n].lifePoints);
	}

	else if(player[n].strength>70){
		printf("%s has %.2f health before being attacking\n", player[n].pName, player[n].lifePoints);//display value of attacked player
		damage = (0.3)*player[n].strength;
		player[n].lifePoints = player[n].lifePoints - (0.3)*player[n].strength;
		printf("Normal Strike - %.2f\n", damage);//display value of attack
		printf("%s has %.2f health after being attacking\n", player[n].pName, player[n].lifePoints);//Display attacked players health
	}
}

//Function to locate the nearest player
int nearestPlayer(int i){

	int a, b, instruct;

	a=i+1; //a is the next slot
	b=i-1;// b is the previous slot

	while(a<numSlots || b>0){//while loop finds the nearest player to attack
		if(slots[a].occupied==1 && slots[b].occupied==1){
			printf("Would you prefer to attack 1.%s or 2.%s:", player[a].pName, player[b].pName);// when two players are the same distance from the player ask who they want to attack
			scanf("%d", &instruct);
			if(instruct==1){
				printf("Attacking %s\n", player[a].pName);
				return a;
			}
			else if(instruct==2){
				printf("Attacking %s\n", player[b].pName);
				return b;
			}
		}

		else if(slots[a].occupied==1 && slots[b].occupied==0){//closest player is in a slot infront
			printf("Attacking Player %s \n", player[a].pName);
			return a;
		}

		else if(slots[a].occupied==0 && slots[b].occupied==1){//closest player is in a slot behind
			printf("Attacking Player %s \n", player[b].pName);
			return b;
		}

		if(a==numSlots){
			a=0;
		}

		if(b==1)
		{
			b=numSlots;
		}

		a++; // increase to next slot until player is found
		b--;// decrease to previous slot until player is found


	}
}

void fContinue(){ //Function for reloading a second round
	int iOpt, i;

	printf("- - - - - - - - - - - - - - - - Crossfire - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - Continue Next Round?- - - - - - - - - - -\n");
	printf("Press 1 to continue another round!\n");
	scanf("%d", &iOpt);
	if(iOpt == 1){
		fOption();//reload the fOptions menu for another round
	}
	else{
	printf("\n\n- - - - - - - - - - - - - - - - Final Results  - - - - - - - - - - - -\n\n");
	printf("Player Info\n");
	printf("\tName\t\t\tType\tHealth\tSmart\tStrength\tMagic\tLuck\tDexterity");

	for(i=1; i<=playerLimit; i++) // loop through players, printing details
	{
		printf("\n%d\t%s\t\t\t%s\t%.2f\t%d\t%d\t\t%d\t%d\t%d",i,player[i].pName,player[i].pType,player[i].lifePoints,player[i].smart,player[i].strength,player[i].magic,player[i].luck,player[i].dexterity);
	}

	close();//Load the close function

	}
}

void close(){
	printf("\n\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - Crossfire - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - Thank You for Playing - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	exit(0); //closes the program
}
