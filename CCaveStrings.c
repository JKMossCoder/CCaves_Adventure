/*
* Module for colossal string
* support for messages, objects, etc.
*/
#define MAX_STR_LENGTH  5000
#define MAX_WORDS         10
#define MAX_WORD_LENGTH   20

#include <stdbool.h>

typedef struct {
	int msgId;   //unique id
	int msgPtr;  //pointer to the structure
	char* amessageText[MAX_STR_LENGTH];
} MessageStr;

typedef struct {
	int worduID;
	char * word[MAX_WORD_LENGTH];
} DictWordStr;

typedef struct {
	int dictId;
	char base5[6];
	DictWordStr wordList[MAX_WORDS];
} DictionaryStr;

typedef struct {
	int stateid;
	char* state[10];
} CStateStr;

typedef struct {
	int objectId;
	//MessageStr inventory;
	bool immovable;
	bool treasure;
	int treasureValue;
	char * locations[10][MAX_WORD_LENGTH];
	CStateStr objStates[10];
	char * descriptions;
	char * changes;
	char * texts;
	char * sounds;	
	DictWordStr wlist[MAX_WORDS];	
} CaveObjectStr;
