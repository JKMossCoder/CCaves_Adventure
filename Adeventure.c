/**************************************************************
* Cpllossal Caves Adventure
* One Player Text Based RPG, originally peoggrammed in 1977
* 
* ClaSS: ITT-310-500 Programming for Security Professonals
* Instructor: Jeremmy Wright
* 
* Author: J. Kevin Moss
* 	Original development by Willie Crowther
*	Major features added by Don Woods
*	Conversion to BDS C by J.R.Jaeger
*	Unix standardization by Jerry D.Pohl
*	Conversion to PHP by Matt G.S.Cox
*	Adapted for AMC.com by Rick Adams \n\
*  
*	This is a derivitive work (scaled down)
*   to demonstrate techniques in C.
*	
*   Note that while based on the previous works,
*   I have not studied the c source code or used
*   any of that work in this program. All of the
*   C Code is original.
**************************************************************
*/

/* windows / standard c header files */
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>

/* custom header files */
#include "colosalcaveadv.h"
#include "CC_Structs.h"

/* function prototypes: */
int  m2(int x, int y);               
void drawScreen(char prompt[81], char str[1500]); 
int readVerbs(char* sentence, struct Location);
void Typewriter(char * ptr);
void makeLCase(char *input, size_t);
bool quitGame(struct Location);
void getHelp();
 
/* Global Variables */
bool intro = false; //to prevent intro from re-firing
int c, retVal = 0, j = 0;
char ch, input[80];
char ch, input[80];

/* Begin Main Function */
int main(void) {

	//Define local variables
	bool valid = 1;

	loadPlayer();
	//we are at the start. initilize location 
	//structure to loc_start
	struct Location activeLocation = init(1);

	drawScreen("Press any key to continuee. >", SPLASH_SCREEN);		//draws top and bottom banners

	c = _getch(); //wait for a key press	

	//show intro text
	//drawScreen("Do you need instructions? > ", introtext);
	//retVal = m2(2, 24);
	//printf("Press (Y)es, (N)o, (Q)uit or ((H)elp *or ?)");

	//retVal = m2(31, 25);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	do
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		retVal = m2(0, 5);
		drawScreen("Do you need instructions? > ", introtext);
		retVal = m2(2, 24);
		printf("Press (Y)es, (N)o, (Q)uit or ((H)elp *or ?)");
		retVal = m2(31, 25);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);

		//retVal = m2(31, 25);
		//Get input, yes, no, help or quit only
		retVal = scanf_s("%[^\n]%*c", &input, sizeof(input));
		//change input to all lower case			
		makeLCase(&input, strlen(input));

		if (
			strcmp(input, "n") == 0 || strcmp(input, "no") == 0 ||
			strcmp(input, "y") == 0 || strcmp(input, "yes") == 0 ||
			strcmp(input, "q") == 0 || strcmp(input, "quit") == 0 ||
			strcmp(input, "h") == 0 || strcmp(input, "help") == 0 ||
			strcmp(input, "?") == 0
			)
		{
			//We hve a valid input so now decide where to go
			if (strcmp(input, "no") == 0 || strcmp(input, "n") == 0)
			{
				do
				{
					//No instructtions, so move to first location (loc_start)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					retVal = m2(0, 5);
					drawScreen("What's next? > ", activeLocation.longDescsription);
					retVal = m2(2, 24);
					printf("Enter BUILD, START, HILL ie (Q)uit or ((H)elp *or ?)");
					retVal = m2(15, 25);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);

					retVal = scanf_s("%[^\n]%*c", &input, sizeof(input));
					makeLCase(&input, strlen(input));
					
					retVal = readVerbs(input, activeLocation);
					if(retVal > 0) 
						activeLocation = init(retVal);
					else if(retVal == -2)
						return 0; //we are ending gaame...					
					//else if (retVal <= 0) {
					//		break;
					//}
				} while (true);
			}
			else if (strcmp(input, "yes") == 0 || strcmp(input, "y") == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				retVal = m2(0, 5);
				drawScreen("Press any key to continue ", info);
				retVal = m2(31, 25);
				c = _getch();
			}
			else if (strcmp(input, "help") == 0 || strcmp(input, "h") == 0 || strcmp(input, "?") == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				retVal = m2(0, 5);
				drawScreen("Press any key to continue ", game_help);
				retVal = m2(31, 25);
				c = _getch();
			}
			else if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0)
			{
				if (quitGame(activeLocation))
					return 0;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				retVal = m2(0, 5);
				printf("What do you meam by %s", input);
				c = _getch();
			}
		//this is the end of the game so clean it up
		}
	} while (true);

	system("clr");
	retVal = m2(0, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return 0;
}

/* Begin of custom routines */
int m2(int x, int y) {
	//move cursor to specified coordinate on the screen
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void drawScreen(char prompt[81], char strDisplay[2000])
{	
	char* myString;
	myString = strDisplay;
	//this function is called each time we move
	//or otherwise need to write to the screen

	//1. clear the screen
	system("cls");

	//set top of window to white on blue
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	for (int j = 1; j <= 15; j++) {
		printf(" ");
	}
	printf("Colossol Caves Adventure  |  Score: %d |  Turns %d", plrOne.score, plrOne.curTurn);
	for (int j = 1; j <= 15; j++) {
		printf(" ");
	}
	printf("\n");

	//top line complete, set texst to green on black
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  //green on black		
	retVal = m2(0, 2);
	printf("%s", myString);
	printf("\n");

	//display text complete, move to last line of the console (25)	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	retVal = m2(0, 25);
	printf("%s", prompt);
	for (int j = 0; j <= 80; j++) {
		printf(" ");
	}
	//bottom line complete, set test to green on black	
	retVal = m2(28, 25); //move cursor to end of input line
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  //green on black		
}

void loadPlayer()
{
	//initilize player
	//struct playerInfo plrOne;
	plrOne.curLocID = 1;
	plrOne.lastLoc = 1;
	plrOne.oldLoc1 = 1;
	plrOne.oldLoc2 = 1;
	plrOne.score = 200;
	plrOne.curTurn = 1250;
	plrOne.Treasures = 15;

	return;

}

int readVerbs(char* sentence, struct Location loc) {
	//we parse the input string getting first and last words
	//if they match then assume they mean goto

	char newString[10][10];
	char* firstword = "";
	char* lastword = "";
	int i, j, ctr, wordcnt = -1;

	j = 0; ctr = 0;

	for (i = 0; i <= (strlen(sentence)); i++)
	{
		// if space or NULL found, assign NULL into newString[ctr]
		if (sentence[i] == ' ' || sentence[i] == '\0')
		{
			newString[ctr][j] = '\0';
			wordcnt += 1;
			
			ctr++;  //for next word
			j = 0;    //for next word, init index to 0
		}
		else
		{
			newString[ctr][j] = sentence[i];
			j++;
		}
	}

	//first word = action
	//last word = destination or item
	
	if (wordcnt >= 0) {
		firstword = newString[0];
		lastword = newString[wordcnt];
		//limit words to either 5 or entered
		
	}

	if (strlen(firstword) > 0) {
		//for now we look at last word to see where we want to go
		if (strcmp(lastword, "hill") == 0)
		{
			//hill = 2
			//struct Location activeLocation = init(2);
			//loc = init(2);
			return 2;
		}
		else if (strcmp(lastword, "build") == 0)
		{
			//building is 3
			//struct Location activeLocation = init(3);
			return 3;
			//loc = init(3);
		}
		else if (strcmp(lastword, "start") == 0) {
			return 1;
		}
		else if (strcmp(lastword, "q") == 0 || (lastword, "quit") == 0) {
			if (quitGame(loc))
				return -2;// loc.locID;
			else
				return loc.locID;
		}
		else if (strcmp(lastword, "h") == 0 || (lastword, "help") == 0 || (lastword, "?") == 0) {
			getHelp();
			return loc.locID;
		}
	}
	return 0; //default return
}

void Typewriter(char * p)
{
	if (NULL == p)
		return;
	while (*p)
	{
		printf("%c\xDB", *p++);
		Beep(460, 15);
		Sleep(25);
		printf("\b \b");
		Sleep(25);
	}
	Sleep(100);

	return;
}

void makeLCase(char *input, size_t length) {
	int j = 0;
	char ch;
	//ensure that the entered text is all lower case?
	while (j <= length) {
		ch = input[j];		
		input[j] = tolower(ch);
		j++;
	}
	
	return;
}

bool quitGame(struct Location activeLocation) {
	//here we quit the game	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	retVal = m2(0, 5);

	drawScreen("Are you sure ? >", activeLocation.longDescsription);		//draws top and bottom banners
	retVal = m2(2, 24);
	printf("Press (Y)es or (N)o?)");
	retVal = m2(15, 25);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	retVal = scanf_s("%[^\n]%*c", &input, sizeof(input));
	makeLCase(&input, strlen(input));

	if (
		strcmp(input, "y") == 0 || strcmp(input, "yes") == 0
		)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		drawScreen("**Game Over **", activeLocation.longDescsription);		//draws top and bottom banners
		retVal = m2(2, 22);
		printf("Treasures\t%d", plrOne.Treasures);
		retVal = m2(2, 23);
		printf("Score\t\t%d", plrOne.score);
		retVal = m2(2, 24);
		printf("Turns\t\t%d", plrOne.curTurn);
		retVal = m2(15, 25);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		c = _getch();

		drawScreen("Good Bye!", activeLocation.longDescsription);		//draws top and bottom banners
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		retVal = m2(0, 2);
		return true;
	}
	else
		return false;
}

void getHelp() {
	//display the help information
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	retVal = m2(0, 5);
	drawScreen("Press any key to continue ", game_help);
	retVal = m2(31, 25);
	c = _getch();
	return;
}

/* Test Cases
	1.
		1. From initial screen, press any key
		2. without entering any key, press enter
		RESULT: system goes into endless loop
	
	2.	1. press h, or enter help and press return/enter
		2. press any key to continue
		3. press enter/return without entering anything
		RESULT: system goes into endless looP
	
	3. Saying No to quit in 'main game loop' crashes game
	   instead of returning to last location
		1. press any key		
		2. enter n or no, then return
		3. press q or quit, then return
		4. Press n or no then return
		RESULT: system terminates abruptly
	
*/
