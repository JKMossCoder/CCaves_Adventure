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
struct TravelCond {
	int tcId;
	int verbSetId;
	int travelid;
	verb c_verb;
	//cond:    [not, GRATE, GRATE_CLOSED], action :[goto, LOC_GRATE]
	//cond:    [pct, 65],                  action: [speak, FUTILE_CRAWL]
	//cond:    [carry, CLAM],              action :[speak, CLAM_BLOCKER]
	//cond:    ["with", SNAKE],            action: [goto, LOC_SNAKEBLOCK]
	char obj[10];
	char objCondition[20];
	char action[10];
	char destination[15];
};

struct VerbSet {
	int verbSetId;
	int travelID;			//location this travel BELONGS to	
	int numVerbs;			//how many verb objects for this loc
	int numCond;
	verb vrbs[MAX_VERBS];
	struct TravelCond tc[10];
};
//e.g. {1, 1, 3, action:'goto', dest:'LOC_BUILDING', verbs:['ENTER','UOWAR','WEST']};

struct Conditions
{
	int conditionID;	//auto generated id
	int locID;			//WHAT LOCATION DOES THS CONDITION BELONG TO
	char name[6];		//adv style name
	bool value;			//true or false
};

struct Travel {
	int travelId;
	int locID;
	int numVerbs;
	char action[7];
	char dest[15];		
	char verbs[MAX_VERBS][6];
	//struct VerbSet t_verb[MAX_VERBS];	
};
//e.g. {tid:1, locid:1, numVerbss: 3, action:'goto', dest:'LOC_BUILDING', 
// verbs:['ENTER','UOWAR','WEST']};
// {1, 1, 3, 0, {}, {"ENTER","UPWAR","WEST"}
//struct verbs: vid, tid, numverbs, numconditions, vervs[]


struct Location {
	int locID;
	int numTSets;
	char locName[13];
	char longDescsription[500];
	char shoertDescsription[250];
	char sound[100];	
	struct Conditions locConditions[3];
	struct Travel locTravel[MAX_VERBS];  // dictioinary verbsand actionsl
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

	struct Location loc_Start = { 1, 3, "LOC_START",		
	"\tYou are standing at the end of a road before a small brick building.\n\r\
	Around you is a forest.A small stream flows out of the building and\n\r\
	down a gully.",
	"You are standing next to a building",
		"GURGLE",
		{
			{1, 1, "LIT", true},
			{2, 1, "FLUID", true},
			{3, 1, "ABOVE", true}
		}, 		
		{
			{1, 1, 3, "goto", "LOC_HILL", {"WEST","ROAD","UPWAR"}},//{1, 1, 3, 0, {"WEST","ROAD","UPWAR"}}},
			{2, 1, 1, "goto", "LOC_GRATE", {"DEPRE"}},//{2, 2, 1, 0, {"DEPRE"}}},
			{3, 1, 1,"speak", "WHICH_WAY", {"DOWN"}}//{3, 3, 1, 0, {"DOWN"}}}
		},
	};

	locs[0] = loc_Start;

	struct Location loc_Hill = { 2, 5, "LOC_HILL",
	"\tYou have walked up a hill, still in the forest.  The road slopes back\n\
	down the other side of the hill.There is a building in the distance.",
	"You are on a hill",
	"none",
	{
		{4, 2, "LIT", true},		
		{5, 2, "ABOVE", true}
	},
	{		
		{4, 2, 2, "goto", "LOC_START", {"BUILD", "EAST"}},
		{5, 2, 1, "goto", "LOC_ROADEND", {"WEST"}},
		{6, 2, 1, "goto", "LOC_FOREST20", {"NORTH"}},
		{7, 2, 2, "goto", "LOC_FOREST13", {"SOUTH", "FORES"}},
		{8, 2, 1, "speak", "WHICH_WAY", "DOWN"}}
	};
	locs[1] = loc_Hill;

	struct Location loc_Building = { 3, 4, "LOC_BUILDING",
	"\tYou are inside a building, a well house for a large spring.\n",
	"\tYou are on a hill\n",
	"none",
	{
		{6, 3, "LIT", true},
		{7, 3, "FLUID", true},
		{8, 3, "ABOVE", true}
	},
	{
		{ 9, 3, 3, "goto", "LOC_START", {"OUT", "OUTDO", "WEST"}},
		{10, 3, 1,"goto", "LOC_FOOF1", {"XYZZY"}},
		{11, 3, 1,"goto", "LOC_FOOF3", {"PLUGH"}},
		{12, 3, 2,"goto", "LOC_SEWER", {"DOWNS", "STREA"}}
	}
	};
	locs[2] = loc_Building;
	/*
	struct Location LOC_GRATE = { 4, 7, "LOC_GRATE",
	"\tYou are in a 20 - foot depression floored with bare dirt.Set into the\n\
	dirt is a strong steel grate mounted in concrete.A dry streambed\n\
	leads into the depression.\0",
	"You''re outside grate.",
	"none",		
		{
			{ 9, 4, "LIT", true},
			{10, 4, "ABOVE", true}
		},
		//hints: [*grate, *jade]
		{
			{13, 4, 2, "goto", "LOC_FOREST7", {"EAST", "FORES"}},
			{14, 4, 1,  "goto","", {"SOUTH"}},
			{15, 4, 1,  "goto", "LOC_FOREST9", {"WEST" }},
			{16, 4, 1, "goto", "LOC_START9", {"BUILD"}},
			{17, 4, 3, "goto", "LOC_SLIT", {"UPSTR", "GULLY", "NORTH"}},
			{18, 4, 3, "goto", "LOC_BELOWGRATE", {"ENTER", "INWAR", "DOWN"},
				//verbset
				{25, 18, 3, 1, {"ENTER", "INWAR", "DOWN"},
					//travelcondition
					{0, 0, 0, "not", "GRATE", "GRATE_CLOSED", "goto", "LOC_BELOWGRATE"}
				}
			},
			{19, 4, 1,  "speak", "GRATE_NOWAY", {"ENTER"}},
		}
	}; */

	return locs[lID - 1];
}
