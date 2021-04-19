/* **************************************************
   * This file will house my structures which get
   * fIlled bu sqlite3
   * 
   ************************************************* 

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

struct Rooms {
	int roomID;
	char roomKey[12];
	char longdesc[250];
	char sgorttdesc[150];

} room;

void sqlite3_sampler() {
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;

	rc = sqlite3_open("test.db", &db);
	if (rc) {
		fprintf(stderr, "Can not open database: %s\n", sqlite3_errmsg(db));
		return 1;
	}
	else
	{
		fprintf(stderr, "Opened  Database\n");
	}
	sqlite3_close(db);
	return 0;
}*/