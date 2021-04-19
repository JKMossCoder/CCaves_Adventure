#include <stdbool.h>

#define INVENTORY_LIMIT 10
#define MAX_VERBS 10

/* Locatio Dictionay
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
	
	Travel.verbs[0].action = "goto"
	Travel.verbs[0].destination = "LOC_HILL"
	Travel.verbs[0].verb[0]="ROAD"
	Travel.verbs[0].verb[1]="WEST"
	Travel.verbs[0].verb[2]="UPWAR"
	---- REPEAT FOR EACH VERB SET -----
*/

typedef char verb[10];
void loadStructs();


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

/* USAGE:
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
	int conditionID;
	int locID;
	char name[6];
	bool value;
};

struct Location {
	int locID;
	char locName[13];
	char longDescsriptp[500];
	char shoertDescsriptp[250];
	char sound[100];
	//struct Conditions locConditions[6];
	//struct Travel locTraveel[MAX_VERBS];  // dictioinary verbsand actionsl
};

struct playerInfo {
	int curLocID; //where am I right now
	int lastLoc;  //where was I before this loc
	int oldLoc1;  //last..location i.e. two before here, used
	int oldLoc2;  //for death
	//future implementation int objCarried; //what objects do I have
	int score;
	int curTurn;
	int objects_carried[INVENTORY_LIMIT];
} plrOne;

/*
	iNSTANTIATE ALL OF OUR LOCATION OBJECTS
	HERE. PHASE iV WILL IMPLEMENT SQLITE3
	FOR THE DATA SO HARD CODED INFO HERE
	WILL NO LONGER BE NEEDED...

struct Location loc_hill;
struct Location loc_bilding;
struct Location loc_valley;
struct Location loc_forest1;
*/
struct Location loc_Start;