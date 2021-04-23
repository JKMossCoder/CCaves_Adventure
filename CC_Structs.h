/**************************************************************
* Cpllossal Caves Adventure
* One Player Text Based RPG, originally peoggrammed in 1977
*
* ClaSS: ITT-310-500 Programming for Security Professonals
* Instructor: Jeremmy Wright
*
* Author: J. Kevin Moss
* 
* CC_Structs.h
* header/support file with
* definations for structures and
* structure specific functons
* ************************************************************
*/

#include <stdbool.h>

#define INVENTORY_LIMIT 10
#define MAX_VERBS 10
#define GAMEVERSION 2

/* Location Dictionay
LOC_START:
	description:
	long : | -
		You are standing at the end of a road before a small brick building.
		Around you is a forest.A small stream flows out of the building and
		down a gully.
	short : 'You''re in front of building.'
	conditions : {FLUID: true, ABOVE : true, LIT : true}
	sound: STREAM_GURGLES
	travel : [
		{verbs: [ROAD, WEST, UPWAR] , action : [goto, LOC_HILL] },
		{ verbs: [ENTER, BUILD, INWAR, EAST] , action : [goto, LOC_BUILDING] },
		{ verbs: [DOWNS, GULLY, STREA, SOUTH, DOWN] , action : [goto, LOC_VALLEY] },
		{ verbs: [FORES, NORTH] , action : [goto, LOC_FOREST1] },
		{ verbs: [DEPRE] , action : [goto, LOC_GRATE] },
	]

  Example Tracwl Array	
	Travel.verbs[0].action = "goto"
	Travel.verbs[0].destination = "LOC_HILL"
	Travel.verbs[0].verb[0]="ROAD"
	Travel.verbs[0].verb[1]="WEST"
	Travel.verbs[0].verb[2]="UPWAR"
	---- REPEAT FOR EACH VERB SET -----
*/

/* TypeDefs */
typedef char verb[10];

void loadPlayer();
/*
	the following is the routine to
	initialize our locations
 */
struct Location init(int);


/* Structure Definations */
struct Verbs {
	int id;
	int travelID; //location this travel BELONGS to	
	int numVerbs; //how many verb objects for this loc
	char action[6]; //speak  or goto
	char destination[10]; //readable location name	
	verb _verb[MAX_VERBS];
};

struct Travel {

	int travelID;
	int locID; //what location is this travel dict for?		
	int numVerbSets;
	struct Verbs t_verbs[MAX_VERBS]; //this travel verbset
};

/* TRAVEL Structure
	USAGE:

	struct Verbs myVerb;
	myVerb.id = 1;
	myVerb.numVerbs = 3;
	strcpy_s(myVerb.action, 5, "goto");
	strcpy_s(myVerb.destination, 9, "LOC_HILL");
	strcpy_s(myVerb._verbs[0], 5, "ROAD");
	strcpy_s(myVerb._verbs[1], 5, "WEST", 5);
	strcpy_s(myVerb._verbs[2], 6, "UPWAR", 6);

*/

struct Conditions
{
	int conditionID;	//auto generated id
	int locID;			//WHAT LOCATION DOES THS CONDITION BELONG TO
	char name[6];		//adv style name
	bool value;			//true or false
};

struct Location {
	int locID;
	char locName[13];
	char longDescsription[500];
	char shoertDescsription[250];
	char sound[100];
	struct Conditions locConditions[3];
	//struct Travel locTraveel[MAX_VERBS];  // dictioinary verbsand actionsl
};

/*
	Function to initilize a players information
*/
struct playerInfo {
	int curLocID; //where am I right now
	int lastLoc;  //where was I before this loc
	int oldLoc1;  //last..location i.e. two before here, used
	int oldLoc2;  //for death
	//future implementation int objCarried; //what objects do I have
	int score;
	int curTurn;
	int Treasures;
	int objects_carried[INVENTORY_LIMIT];
} plrOne;

/*
struct Location loc_start..0,
struct Location loc_hill..1;
struct Location loc_bilding..2;
struct Location loc_valley..3;
struct Location loc_forest1..4;
*/
struct Location loc_Start;
/*
	Structurer Initilzaation
	Function
	This will load stucture
	information into a location
	structure based on the ID 
	passed to it
	the data is hard coded in this
	function until we get to use
	of sqlite3 around phase III
*/
struct Location init(int lID)
{
	//lID = Location_ID of the location I want to display
	struct Location locs[10]; //array of 10 locations max for this phase

	struct Location loc_Start = { 1, "LOC_START",
		"\t\tYou are standing at the end of a road before a small brick building.\n\r\
		Around you is a forest.A small stream flows out of the building and\n\r\
		down a gully.",
		"You are standing next to a building",
		"GURGLE",
		{
			{1, 1, "LIT", true},
			{2, 1, "FLUID", true},
			{3, 1, "ABOVE", true}
		}
	};

	locs[0] = loc_Start;

	struct Location loc_Hill = { 2, "LOC_HILL",
	"\n\
	 You have walked up a hill, still in the forest.  The road slopes back\n\
		  down the other side of the hill.There is a building in the distance.",
	"You are on a hill",
	"none",
	{
		{1, 1, "LIT", true},
		{2, 1, "FLUID", true},
		{3, 1, "ABOVE", true}
	}
	};
	locs[1] = loc_Hill;

	struct Location loc_Building = { 3, "LOC_BUILDING",
	"You are inside a building, a well house for a large spring.\n",
	"You are on a hill\n",
	"none",
	{
		{1, 1, "LIT", true},
		{2, 1, "FLUID", true},
		{3, 1, "ABOVE", true}
	}
	};
	locs[2] = loc_Building;

	return locs[lID - 1];
}
