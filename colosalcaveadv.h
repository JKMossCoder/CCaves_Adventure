/**************************************************************
* Cpllossal Caves Adventure
* One Player Text Based RPG, originally peoggrammed in 1977
*
* ClaSS: ITT-310-500 Programming for Security Professonals
* Instructor: Jeremmy Wright
*
* Author: J. Kevin Moss
* 
* ModuleColossalCaveAdv.h
* file to support the main application
* 
* in thias module will be text constants
* which will be replaced with sqlite3 in
* future phases of the project
* *************************************************************
*/
const char* SPLASH_SCREEN = "\tWelcome to ADVENTURE! \n\
	\n\
	Original development by Willie Crowther \n\
	Major features added by Don Woods \n\
	Conversion to BDS C by J.R.Jaeger \n\
	Unix standardization by Jerry D.Pohl \n\
	Conversion to PHP by Matt G.S.Cox \n\
	Adapted for AMC.com by Rick Adams \n\
	\n\
	To play the game, type short phrases into the command line below. \n\
	If you type the word \"look, \" the game gives you a description of \n\
	your surroundings.Typing \"inventory\" tells you what you're \n\
	carrying.  \"Get\" \"drop\" and \"throw\" helps you interact with \n\
	objects.Part of the game is trying out different commands and \n\
	seeing what happens.Type \"help\" at any time for game \n\
	instructions.\n\0";


const char introtext[700] = "\tSomewhere nearby is Colossal Cave, where others have found fortunes in \n\
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

//next is help not  info
const char info[1500] = "\tFor a summary of the most recent changes to the game, say \"news\".\n\
	If you want to end your adventure early, say \"quit\".To suspend your\n\
	adventure such that you can continue later, say \"suspend\" (or \"pause\"\n\
	or \"save\").To see how well you're doing, say \"score\".  To get full\n\
	credit for a treasure, you must have left it safely in the building,\n\
	though you get partial credit just for locating it.You lose points\n\
	for getting killed, or for quitting, though the former costs you more.\n\
	There are also points based on how much(if any) of the cave you've\n\
	managed to explore; in particular, there is a large bonus just for\n\
	getting in(to distinguish the beginners from the rest of the pack),\n\
	and there are other ways to determine whether you've been through some\n\
	of the more harrowing sections.If you think you've found all the\n\
	treasures, just keep exploring for a while.If noting interesting\n\
	happens, you haven't found them all yet.  If something interesting\n\
	* DOES * happen(incidentally, there * ARE * ways to hasten things along),\n\
	it means you're getting a bonus and have an opportunity to garner many\n\
	more points in the Master's section.  I may occasionally offer hints\n\
	if you seem to be having trouble.If I do, I'll warn you in advance\n\
	how much it will affect your score to accept the hints.Finally, to\n\
	save time, you may specify \"brief\", which tells me never to repeat the\n\
	full description of a place unless you explicitly ask me to.\n\0";

const char game_help[1300] = "\tI know of places, actions, and things.Most of my vocabulary describes\n\
	placesand is used to move you there.To move, try words like forest,\n\
	building, downstream, enter, east, west, north, south, up or down.\n\
	I know about a few special objects, like a black rod hidden in the cave.\n\
	These objects can be manipulated using some of the action words I know.\n\
	Usually you will need to give both the objectand action words(In\n\
	either order), but sometimes I can infer the object from the verb alone.\n\
	Some objects also imply verbs; in particular, \"inventory\" implies \"take\n\
	inventory, \" which causes me to give you a list of what you're carrying.\n\
	The objects have side effects; for instance, the rod scares the bird.\n\
	Usually people having trouble moving just need to try a few more words.\n\
	Usually people trying unsuccessfully to manipulate an object are\n\
	attempting something beyond their(or my!) capabilitiesand should try a\n\
	completely different tack.To speed the game you can sometimes move long\n\
	distances with a single word.For example, \"building\" usually gets you to\n\
	the building from anywhere above ground except when lost in the forest.\n\
	Also, note that cave passages turn a lot, and that leaving a room to\n\
	the north does not guarantee entering the next from the south.Good luck!\0";

//const char long_game_help[2000] = "\
  I know of places, actions, and things. Most of my vocabulary describes\n\
  placesand is used to move you there.To move, try words like forest,\n\
  building, downstream, enter, east, west, north, south, up, or down.I\n\
  know about a few special objects, like a black rod hidden in the cave.\n\
  These objects can be manipulated using some ofthe action words that I \n\
  know.Usually you will need to give both the objectand action words(in \n\
  either order), but sometimes I can infer the object from the verb alone.\n\
  Some objects also imply verbs; in particular, \"inventory\" implies \n\
  \"take inventory\", which causes me to give you a list of what you're \n\
  carrying.  Some objects have unexpected effects; the effects are not \n\
  always desirable!Usually people having trouble moving just need to try \n\
  a few more words.Usually people trying unsuccessfully to manipulate an \n\
  object are attempting something	beyond their(or my!) capabilitiesand \n\
  should try a completely different tack.One point often confusing to \n\
  beginners is that, when there are several ways to go in a certain \n\
  direction(e.g., if there are several holes in a wall), choosing that \n\
  direction in effect chooses one of the ways at random; often, though, \n\
  by specifying the place you want to reach you can guarantee choosing \n\
  the right path. Also, to speed the game you can sometimes move long \n\
  distances with a single word.For example, \"building\" usually gets \n\
  you to the building	from anywhere above ground except when lost in the \n\
  forest.Also, note that cave passagesand forest paths turn a lot, so leaving\n\
  one place heading north doesn't guarantee entering the next from the \n\
  south. However(another important point), except when you've used a \"long\n\
  distance\" word such as \"building\", there is always a way to go back\n\
  where you just came from unless I warn you to the contrary, even\n\
  though the direction that takes you back might not be the reverse of\n\
  what got you here.Good luck, and have fun!\n\0";
