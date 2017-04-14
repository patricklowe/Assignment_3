//	include files - library
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "crossfireOperations.h"
void playerCreate();
void humanAttributes(int a); //function for human Attributes
void ogreAttributes(int a);//function for Ogre Attributes
void elfAttributes(int a);//function for Elf Attributes
void wizardAttributes(int a);//function for Wizard Attributes
void fAssign(); // Assign Players to Slots
int count = 0; // finding cells
void fOption(); // main game menu
void fMove(int i); // move slot
struct slot* currSlot = NULL; //current slot position
struct slot *foundSlots; // found slots when seraching
struct slot *upLeft; // (0,0) for searching
struct slot *upRight;// (0,6) for searching
struct slot *downLeft;// (6,0) for searching
struct slot *downRight;// (6,6) for searching
struct slot *board; // game board
void fQuit(int i); // quit game
void removePlayer(int i);
void roundResults();
void CapabilitiesChange(int i); //change player capabilities if they move slot
void fAttack(int i); // attack the player
void nearSearch(); // search nearby players
void nearAttack(); // attack the selected nearby player
void farSearch(); // search >1 <5
void farAttack(); // attack the selected far away player
void magicOption (int i);
void magicAttack(); // perform the magic attack on any player
void fContinue();  // reload the options menu
void close(); //exit the game
int fBoard(); // board functions
void moveTo(); // move to selected slot
int fBoardValue; //load board option
int playerRemaining; // remaining players in the game
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
	int pPlaying; // Still playing game
}; // End of structure

struct attributes player[6];

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
		playerRemaining = playerLimit;
	}
	else if(playerLimit<2){// prevents 1 player or less being entered as its a multiplayer game
		playerRemaining = playerLimit;//set the limit to 2
		printf("\n\tMinimum number of Players required, Setting Players to 2!\n");
	}
		playerRemaining = playerLimit;
		for(i=1; i<=playerLimit; i++){//loop to set each characters attributes
			printf("- - - - - - - - - - - - - - - - Player[%d] Creation - - - - - - - - - -\n", i);
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
	printf("\tName\t\tType\tHealth\tSmart\tStrength\tMagic\tLuck\tDexterity");

	for(i=1; i<=playerLimit; i++) // loop through players, printing details
	{
	printf("\n%d\t%s\t\t%s\t%.2f\t%d\t%d\t\t%d\t%d\t%d",i,player[i].pName,player[i].pType,player[i].lifePoints,player[i].smart,player[i].strength,player[i].magic,player[i].luck,player[i].dexterity);
	}
	fBoardValue = 1;
	fBoard(&count, &board, &player[i].pSlotRowNum, &player[i].pSlotColNum, &player[i].pSlotType, fBoardValue, &upLeft, &upRight, &downLeft, &downRight, &foundSlots, &currSlot);
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
	player[a].pPlaying = 1;
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
	player[a].pPlaying = 1;
	
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
	player[a].pPlaying = 1;
}

//sets the random attributes for a wizard
void wizardAttributes(int a){
	player[a].lifePoints = 100;//life points set at 100
	player[a].luck=rand() % (100 + 1 - 50) + 50;//random number between 50 and 100
	player[a].smart=rand() % (100 + 1 - 90) + 90;//random number between 90 and 100
	player[a].strength=rand() % (20 + 1 - 1) + 1;//random number between 1 and 20
	player[a].magic=rand() % (100 + 1 - 80) + 80;//random number between 80 and 100
	player[a].dexterity=rand() % (100 +1 -1) + 1;//random number between 1 and 100
	player[a].pPlaying = 1;
}

// Assign players to slots
void fAssign(){
	printf("\n\n- - - - - - - - - - - - - - - - Player Assigning  - - - - - - - - - - -\n\n");
	int i;
	fBoardValue = 2;
	for(i=1; i<=playerLimit; i++){
	fBoard( &count, &board, &player[i].pSlotRowNum, &player[i].pSlotColNum, &player[i].pSlotType, fBoardValue, &upLeft, &upRight, &downLeft, &downRight, &foundSlots, &currSlot);
	printf("\n%s has been assigned to Slot: (%d,%d) %s", player[i].pName, player[i].pSlotRowNum,player[i].pSlotColNum, player[i].pSlotType);// Prints Plyaer name, SLot number from previous function, and slot type
	}
}

// Options for current player to Attack or Move Slot
void fOption(){
	int iSwap, i, j;
	do{
	if(playerRemaining == 0){
		close();
	}
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

		printf("\n\t\tCurrent Slot: (%d,%d) %s\n", player[i].pSlotRowNum, player[i].pSlotColNum, player[i].pSlotType);

		printf("\t\t 1. Move\n");
		printf("\t\t 2. Attack\n");
		printf("\t\t 3. Quit\n");

		for(j=1; j<=playerLimit;j++){
		printf("\t\t%s (%s, %.2f) Slot[%d][%d] %s\n", player[j].pName, player[j].pType, player[j].lifePoints, player[j].pSlotRowNum,player[j].pSlotColNum, player[j].pSlotType);
		}
		printf("\nOption: ");
		scanf("%d", &iSwap);

		if(iSwap == 1){
			fMove(i); //move current player
		}

		else if(iSwap == 2){
			fAttack(i);//Attack nearby player
		}

		else if(iSwap ==3){
			removePlayer(i);//remove player from game
			i--;//ensures a next player is not skipped when it is there turn
		}

		else{
			printf("Invalid Entry!");
		}
		}
	}while(playerRemaining != 0);
roundResults();
fContinue();
}


//moving current player forward 1 slot if not occuppied
void fMove(int i){
	printf("\n\n- - - - - - - - - - - - - - - - Moving Player %d - - - - - - - - - - -\n\n",i);
	
	//Load Function to find a slot
	printf("Current Slot (%d,%d) %s\n", player[i].pSlotRowNum, player[i].pSlotColNum, player[i].pSlotType);
	fBoardValue = 3;
	fBoard(&count, &board, &player[i].pSlotRowNum, &player[i].pSlotColNum, &player[i].pSlotType, fBoardValue, &upLeft, &upRight, &downLeft, &downRight, &foundSlots, &currSlot);

	//change capabilites depending on new slot
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
}

// Function when Attacking a player
void fAttack(int i){//reduces life points when attack is preformed
	printf("\n\n- - - - - - - - - - - - - - - - Attacks for Player %d - - - - - - - - - - -\n\n",i);
	int iOpt;
	
	printf("\tSelect an Attack:\n");
	printf("\t1. Near Attack\n");
	printf("\t2. Far Attack\n");
	printf("\t3. Magic Attack\n");
	printf("\n\tAttack Type: ");
	scanf("%d", &iOpt);
	
	if(iOpt == 1){
		nearSearch(i); //move current player
	}

	else if(iOpt == 2){
		farSearch(i);//Attack nearby player
	}

	else if(iOpt ==3){
		if((player[i].smart+player[i].magic)>150){
		magicOption(i);//Attacks any player
		}
	}

	else{
		printf("Invalid Entry!");
	}
	}

void nearSearch(int a){

	int j;
	char attack;

	for(j=1; j<=playerLimit; j++){//loop through each player to see if they are nearby to attack
		//if player is in same slot
//	printf("\n\nJ = %d \nA = %d", j, a);
		if((player[j].pSlotRowNum==player[a].pSlotRowNum)&&(player[j].pSlotColNum==player[a].pSlotColNum)&&(j!=a)){
			//would you like to attack
			printf("Enter 'a' to preform a Near Attack on Player %d. %s in your Slot\n\tEnter any other character to continue searching\n", j, player[j].pName);
			scanf(" %c", &attack);
			if(attack=='a'){
				nearAttack(j, a);
			}
		}
		//if player is in slot above
		if((player[j].pSlotRowNum==player[a].pSlotRowNum+1)&&(player[j].pSlotColNum==player[a].pSlotColNum)&&(j!=a)){
			//would you like to attack
			printf("\tEnter a to preform a Near Attack on Player %d. %s above you\n\tEnter any other character to continue searching\n", j, player[j].pName);
			scanf(" %c", &attack);
			if(attack=='a'){
				nearAttack(j, a);
			}
		}
		//if player is in slot to the right
		if((player[j].pSlotRowNum==player[a].pSlotRowNum)&&(player[j].pSlotColNum+1==player[a].pSlotColNum)&&(j!=a)){
			//would you like to attack
			printf("\tEnter a to preform a Near Attack on Player %d. %s to your Right\n\tEnter any other character to continue searching\n", j, player[j].pName);
			scanf(" %c", &attack);
			if(attack=='a'){
				nearAttack(j, a);
			}
		}
		//if player is in slot below
		if((player[j].pSlotRowNum==player[a].pSlotRowNum-1)&&(player[j].pSlotColNum==player[a].pSlotColNum)&&(j!=a)){
			//would you like to attack
			printf("\tEnter a to preform a Near Attack on Player %d. %s below you\n\tEnter any other character to continue searching\n", j, player[j].pName);
			scanf(" %c", &attack);
			if(attack=='a'){
				nearAttack(j, a);
			}
		}
		//if player is in slot to the left
		if((player[j].pSlotRowNum==player[a].pSlotRowNum)&&(player[j].pSlotColNum-1==player[a].pSlotColNum)&&(j!=a)){
			//would you like to attack
			printf("\tEnter a to preform a Near Attack on Player %d. %s to your left\n\tEnter any other character to continue searching\n",j, player[j].pName);
			scanf(" %c", &attack);
			if(attack=='a'){
				nearAttack(j, a);
			}
		}
		// if nobody is near by
		else if((player[j].pSlotRowNum!=player[a].pSlotRowNum)&&(player[j].pSlotColNum!=player[a].pSlotColNum)&&(j!=a)){
			printf("\n\tNo Players are Nearby!");
//			fAttack(a);
		}
	}
}

void nearAttack(int n,int i){//reduces life points when attack is preformed
double damage;

	if(player[n].strength<=70){
		damage = (0.5)*player[n].strength;
		player[n].lifePoints -= damage;
		printf("Critical Strike - %.2f\n", damage);
		printf("%s has %.2f health after being attacked\n", player[n].pName, player[n].lifePoints);//display health of attacked player
	}

	else if(player[n].strength>70){
		damage = (0.3)*player[n].strength;
		player[i].lifePoints -= damage;
		printf("Defensive Strike - %.2f\n", damage);//display value of attack
		printf("%s has %.2f health after being attacked\n", player[n].pName, player[n].lifePoints);//display health of attacked player
	}
	if(player[n].lifePoints<=0){
		removePlayer(n);
	}

	if(player[i].lifePoints<=0){
		removePlayer(i);
	}
}

void farSearch(int a){
	printf("Far Search Function");
	// search code
	int n;
	//loading far attack function
	farAttack(n,a);
}

void farAttack(int n, int i){
	printf("Far Attack Function");
}

void magicOption (int i){
//i==player that is attacking
int b,attack;//b==player to be attacked, attack==intruct who to attack
	for(b=1; b<=playerLimit; b++){
		if(i!=b){
			printf("Enter %d to preform a magic attack on %s\n", b, player[b].pName);
			scanf("%d", &attack);
			magicAttack(i, attack);
		}
		
		else if(i==b){
		printf("This will result in attacking yourself, please enter a number from the options provided\n");
		scanf("%d", &attack);
		magicAttack(i, attack);
	}
}
}

void magicAttack(int i, int n){//implements magic attack
// i== is attacking player, n==attacked player,
double damage;

	damage = ((0.5*player[i].magic)+(0.2*player[i].smart));
	printf("Magical Strike - %.2f\n", damage);
	player[n].lifePoints -= damage;
	printf("%s has %.2f health after being attacked\n", player[n].pName, player[n].lifePoints);//display health of attacked player
	if(player[n].lifePoints<=0){
		removePlayer(n);
	}
}

void removePlayer(int i){
	int iOpt;

	printf("- - - - - - - - - - - - - - - - Crossfire - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - You have been Eliminated! - - - - - - - - - - -\n");	
	player[i].pPlaying = 0;
	playerRemaining -= 1;
	printf("\n\n\t\t\tPlayers remaining: %d\n", playerRemaining);
	roundResults();
}

void roundResults(){ //Function for printing results after a round
	printf("- - - - - - - - - - - - - - - - End of Round Results - - - - - - - - - - - - - - -\n");
	printf("\n\tName\t\tType\tHealth\tSmart\tStrength\tMagic\tLuck\tDexterity");
	int i;
	for(i=1; i<=playerLimit; i++) // loop through players, printing details
	{
	printf("\n%d\t%s\t\t%s\t%.2f\t%d\t%d\t\t%d\t%d\t%d",i,player[i].pName,player[i].pType,player[i].lifePoints,player[i].smart,player[i].strength,player[i].magic,player[i].luck,player[i].dexterity);
	}
}

void fContinue(){
fOption();	
}

void close(){
	printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - Thank You for Playing Crossfire - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\tName\t\tType\tHealth\tSmart\tStrength\tMagic\tLuck\tDexterity");
	int i;
	for(i=1; i<=playerLimit; i++) // loop through players, printing details
	{
	printf("\n%d\t%s\t\t%s\t%.2f\t%d\t%d\t\t%d\t%d\t%d\n",i,player[i].pName,player[i].pType,player[i].lifePoints,player[i].smart,player[i].strength,player[i].magic,player[i].luck,player[i].dexterity);
	}
	exit(0);
}
