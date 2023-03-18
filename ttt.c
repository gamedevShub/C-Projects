#include<stdio.h>
#include<stdlib.h>
int printBoard();  
char updateBoard(int slotNum, char mark, char markPrint[]);
int checkWin(char markPrint[],char mark);
/*	Write a code to print tic-tac-toe board table -Done
	Write a code to read slot number from user and print the respectively assigned mark(x/o) on TTT board -Done
	Write a code to re-read a players input if he accidentally entered an pre-occupied slot number -Done
	Write a code to input player names and to display the winner's name -Done
	Write a function to check the winner using TTT win combinations -Done
	Write a code to clean the previous board prints -Done
	Write a code to print  if the game is tie -Done
*/

int main()
{
	printf("***** Tic-Tac-Toe *****\n\n");  /* Introductory Design */
	printBoard();
	char player1[20],player2[20];		/* variables to store player names, select slot numbers and store marks(x/o) */
	int i, slotNum, isOver = 0;
	char mark = 'x',tempMark;
	char markPrint[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; /* array to store 'x/o' mark in slots */

	printf("Enter Player 1 name : ");
	scanf("%s",&player1);				/* Read Player names */
	printf("Enter Player 2 name : ");
	scanf("%s",&player2);
	fflush(stdin);

	while(isOver != 1)
	{
		tempMark = mark;						/* stores the mark to be used in isOver function */
		if(mark == 'x') {
			printf("%s's turn :\n",player1);	
		}										/* Assign 'X' and 'O' to both players respectively */
		else if(mark == 'o') {					/* Print the Player's Turn depending on the respective mark */
			printf("%s's turn :\n",player2);
		}
		printf("Which slot you want to mark on? : "); 	/* read a slot number to assign a mark on that slot */
		scanf("%d",&slotNum);
		fflush(stdin);
		system("cls");								/* Clears the previous display messages/printf's */
		mark = updateBoard(slotNum,mark,markPrint);	 /* Pass selected slot number, mark and slot array to functions */
		isOver = checkWin(markPrint,tempMark);		/* Check if the game is over or not */
		if(isOver == 2) {							
			break;									/* Check if the game is tie or not*/
		}
	}

	if(isOver == 2) {	
		printf("The Game is a Tie\n");				/* IF game is tie then print it */
	}				
	else if(mark == 'o') {
		printf("\n*** %s has Won!! ***\n",player1);
	}												/* if someone won then Print the winners name */
	else if(mark == 'x') {
		printf("\n*** %s has Won!! ***\n",player2);
	}

	printf("Game has ended\n");
}
int printBoard() {
	int i,j,count = 0;
	int numPrint[9];		 			 /* print a basic TTT board layout and */
	for(i = 0; i < 3; i++) {			/* display 1-9 numbers in respective slots(rule guide) */	
		printf("|");
		for(j = 0; j < 3; j++) {
			numPrint[count] = count+1;
			printf("%d|", numPrint[count]);
			count++;
		}
		printf("\n");
	}
}
char updateBoard(int slotNum, char mark, char markPrint[]) {
	int i,j,count = 0;
	printf("\n");

	if(markPrint[slotNum-1] != ' ') {
		printf("Slot is already marked! Retry-!\n",mark);	/* if the selected slot number is already marked then */
		return mark;										/* the player will get a retry to select another slot */
	}
	else {
		for(i = 0; i < 3; i++) {	/* or if the selected slot is empty then that slot will be available to mark on */
			printf("|");				
			for(j = 0; j < 3; j++) {
				markPrint[slotNum-1] = mark;
				printf("%c|", markPrint[count]);	 /* Print all slots i.e print the slot array with all assigned marks*/
				count++;
			}
			printf("\n");
		}
		if(mark == 'o') {
			return 'x';
		}							/* Once selected slot is assigned with a mark then the player's turn will switch */
		else if(mark == 'x') {
			return 'o';
		}
	}
}

int checkWin(char markPrint[],char mark) {	/* There are 8 ways to win TTT */ 
	int i, count = 0;						/* i.e 8 combinations of a mark appearing 3 times on board eg. (|x||x||x|) */ 
	for(i = 0; i < 9; i++) {
		if(markPrint[i] != ' '){			/* if all 9 slots are marked and no combination is seen then */
			count++;						/* this loops return the value '2' to 'isOver' variable which indicates */
		}									/* The game is a tie */
		if(count == 9) {
			return 2;
		}

	}
	if(	(markPrint[0] == mark && markPrint[1] == mark && markPrint[2] == mark) ||  	
		(markPrint[0] == mark && markPrint[3] == mark && markPrint[6] == mark) ||  	/* This function check if the mark */
		(markPrint[0] == mark && markPrint[4] == mark && markPrint[8] == mark) ||	/* has appeared thrice in any of */
		(markPrint[1] == mark && markPrint[4] == mark && markPrint[7] == mark) || 	/* those 8 combinations, if yes */
		(markPrint[2] == mark && markPrint[4] == mark && markPrint[6] == mark) ||	/* then it returns value 1 to */
		(markPrint[2] == mark && markPrint[5] == mark && markPrint[8] == mark) || 	/* 'isOver' flag variable */
		(markPrint[3] == mark && markPrint[4] == mark && markPrint[5] == mark) ||
		(markPrint[6] == mark && markPrint[7] == mark && markPrint[8] == mark) ) {
		return 1;
	}
}
