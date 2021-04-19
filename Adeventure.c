/*
* Cpllossal Caves Adventure
* One Player Text Based RPG, originally peoggrammed in 1977
* 
	  Note that this is psudocode for 
	  the file, so not functional

#include <stdio.h>
need the filee io header for save/read from file

initial output is beginning text RoomID 0

Milestone 2 needs me to demostrate:
	1. The use of Looping and decisions
	2. Use of bult-in data types
	3. Input via std in
	4. Output to console via std out
	5. use of the preprocessor

	read initial screen information
	Output it to user via the console

	for thistoworkineed to  use sqlite3
	to work with the texts so I dont put
	them in the code files. #include <sqlite3>

Mioestone 3/Release 2
	1. Demenstratre the use of user defined functions
	2. Use arrays or pointers, or both

	For this release, I aleeady hevely use usee functions
	and have arrays in use. Since sentences are nothing 
	more than arrays of char's I think I have this one
	covered as well.

	Fore elease 2 I will provide a bit more functionality
	as well as look at more advanced features of pointers
	if they will make my life easer. I may look into linked
	lists but that may be a phase 3 release since I only
	have this week to finish this benchmark. (Deadline of
	04/26.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>
#include "colosalcaveadv.c"
#include "CC_Structs.c"

bool intro = false;

//function prototypes: 
int  m2(int x, int y);              //position cursor on screen
void drawScreen(char prompt[81], char str[1000]); //playscreen
//const char * playintro();				  //game introducton
int  start();					  //show loc_start text
int readVerbs(char* str);
void Typewriter(char * ptr);


const char introtext[700] = "\n\
	Somewhere nearby is Colossal Cave, where others have found fortunes in \n\
	treasureand gold, though it is rumored that some who enter are never \n\
	seen again.Magic is said to work in the cave.I will be your eyes \n\
	and hands.Direct me with commands of 1 or 2 words.I should warn \n\
	you that I look at only the first five letters of each word, so you'll \n\
	have to enter \"northeast\" as \"ne\" to distinguish it from \"north\". \n\
	You can type \"help\" for some general hints.For information on how \n\
	to end your adventure, scoring, etc., type \"info\". \n\
	\t\t\t - -- \n\
	This program was originally developed by Willie Crowther.Most of the \n\
	features of the current program were added by Don Woods.\n\0";


	//fprintf(stderr, "%s\n", introtxt);
	//ntro[]=introtxt;
//	return 0;
//}

int m2(int x, int y) {
	//move cursor to specified coordinate on the screen
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(hConsole, pos);	
	return 0;
}

void drawScreen(char prompt[81], char strDisplay[1000])
{
	int retVal;
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
	printf("Colossol Caves Adventure  |  score: %d |  Turns %d",plrOne.score, plrOne.curTurn);
	for (int j = 1; j <= 15; j++) {
		printf(" ");
	}
	printf("\n");
	//top line complete, set test to green on black
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  //green on black	
	retVal = m2(0, 2);
	printf("%s", myString);
	printf("\n");
																   //draw the last line
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	retVal = m2(0, 25);
	//prompt = "Press enter to continue  > ";
	printf("%s", prompt);
	for (int j = 15; j <= 80; j++) {
		printf(" ");
	}

	//top line complete, set test to green on black	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  //green on black		
	//display the splash screen
	retVal = m2(28, 25); //move cursor to end of input line


}

struct Location init(int lID)
{
	//lID = Location_ID of the location I want to display
	struct Location locs[10];
	//locs[0].locID = 1;
	//locs[0].locName = "LOC_START";
	//locs[1].locID = 2;
	//locs[2].locID = 3;

	struct Location loc_Start = { 1, "LOC_START",
	"\n\
	You are standing at the end of a road before a small brick building.\n\
	Around you is a forest.A small stream flows out of the building and\n\
	down a gully.",
	"You are standing next to a building",
	"GURGLE"
	};
	locs[0] = loc_Start;

	struct Location loc_Hill = { 2, "LOC_HILL",
	"\n\
	 You have walked up a hill, still in the forest.  The road slopes back\n\
		  down the other side of the hill.There is a building in the distance.",
	"You are on a hill",
	"none"
	};
	locs[1] = loc_Hill;

	struct Location loc_Building = { 3, "LOC_BUILDING",
	"You are inside a building, a well house for a large spring.\n",
	"You are on a hill\n",
	"none"
	};
	locs[2] = loc_Building;
	
	return locs[lID-1];
}


int main(void) {
	
	int retVal = 0;
	bool yummy;
	char input[80];
	bool valid = 1;
	int c;

	//struct playerInfo plrOne;
	plrOne.curLocID = 1;
	plrOne.lastLoc = 1;
	plrOne.oldLoc1 = 1;
	plrOne.oldLoc2 = 1;
	plrOne.score = 20;
	plrOne.curTurn = 1;

	struct Location lone = init(1); //we are at the start
	
	//rewrite drawScreen to accept the prompt and  the text to display

	drawScreen("Press enter to continuee. >", SPLASH_SCREEN);		//draws top and bottom banners
	
	
	c = getchar(); //wait for enter to be entered	

	//show intro text
	drawScreen("Would you like instructions? > ", introtext);
	            
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	retVal = m2(31, 25);
	
	retVal = scanf_s("%[^\n]%*c", &input, sizeof(input));
	//change input to all lower case
	// convert ch to lowercase using toLower()
	printf("Input %s is %d characters long and last character is ASCII %d\n", input, strlen(input), (int)input[strlen(input)]);
	char ch;
	int j = 0;
	while (input[j]) {
		ch = input[j];
		input[j] = tolower(ch);

		j++;
	}
	printf("Input to lower case: %s\n", input);

	if (strcmp(input, "no") == 0)
	{		
		do
		{ 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			retVal = m2(0, 5);
						
			drawScreen("What do you want to do? > ", lone.longDescsriptp);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
			retVal = m2(28, 25);

			retVal = scanf_s("%[^\n]%*c", &input, sizeof(input));
			printf("Input = %s\n", input);
			//wenow need to read the input line
			//and decide what to do

			retVal = readVerbs(input, lone);
			if (retVal <= 0) {				
				break;
			}
			else {
				lone = init(retVal);
			}
		} while (true);
	}
	else if(strcmp(input,"yes") == 0)
	{
		//we need to display the information screen which isn't designed yet!
		//yummy = playintro();
		printf("So...\n");
	}
	else {
		printf("What do you meam by %s", input);
	}
	
	/*
	do
	{	
		drawScreen("What do you want to do? >", lone.longDescsriptp);
		retVal = m2(0, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  //green on black			
		//retVal = start(); //this needs to change to show current location description
		retVal = m2(28, 25);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
		//get users input

		retVal = scanf_s("%[^\n]%*c", &input, sizeof(input));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);  //green on black			

		if ((char)input[0] >= 0) {
			retVal = readVerbs(input);
			if (retVal == 0)
				break;
		}
	} while (1==1);
	*/

	//this is the end of the game so clean it up stupid
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	//printf("...%d...\n", c);
	
	return 0;
}



int start() {
	char startTxt[] = "\n\
	 You are standing at the end of a road before a small brick building.\n\
	 Around you is a forest.A small stream flows out of the buildingand\n\
	 down a gully.\n\0";
	//Typewriter(startTxt);
	fprintf(stderr, "%s\n", startTxt);

	return 1;
}

/* UNIMPLEMENTED CURRENTLOCATION
int currentLocation(int locID) {
	//phase 2 or 3 will implement this function
	//using sqlite3. for phase 1, the number of rooms is limited
	//so haard coding a switch statment here
	//will suffice
	int rc;
	system("cls"); //clear the screen

	switch (locID) //siaplay location bssed on id
	{
	case 1:
		rc = start();
		break;
	case 2:
		break;
	case 3:
		break;

	default:
		break;
	}
	rc = m2(); //movecursortoinputline
	return locID;
	printf("What would you like to do now? ");
}
*/

int readVerbs(char* sentence, struct Location loc) {
	//we parse the input string getting first and last words
	//if they match then assume they mean goto

	char newString[10][10];
	char* firstword = "";
	char* lastword = "";
	int i, j, ctr, wordcnt = -1;

	//printf("\n\n Split string by space into words :\n");
	//printf("---------------------------------------\n");
	j = 0; ctr = 0;

	for (i = 0; i <= (strlen(sentence)); i++)
	{
		//printf("sentence[%i] is a %d\n", i, &sentence[i]);

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
	}
	//TRODO: change first and last words to lower case for string compairs
	//use routone from main, I could do this with a function with viariable # of args
	//but that would be phase 5

	if (strlen(firstword) > 0) {
		printf("\n Strings or words %d after split by space are :\nFirst: %s\nLast: %s\n", wordcnt + 1, firstword, lastword);
		//for now we look at last word to see where we want to go
		if (strcmp(lastword, "hill") == 0)
		{
			//hill = 2
			//struct Location lone = init(2);
			//loc = init(2);
			return 2;
		}
		else if (strcmp(lastword, "building") == 0)
		{
			//building is 3
			//struct Location lone = init(3);
			return 3;
			//loc = init(3);
		}
		else if (strcmp(lastword, "start") == 0) {
			return 1;
		}
		else {
			return -1;
		}
		//look up the last word in the travel for this location
		//and if the action matches, then perform that action
		//otherwise fail the input and reprompt...

		
		return 0;
	}
	else {
		return -1;
	}
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