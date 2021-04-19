struct Rooms {
	int room_id; 
	char name[7];
	char long_desc[200];
	char short_desc[50];
	char conditions[10][6]; //dictionary of conditions
	char travel[10][5]; //dictionary of travel verbs
	char actions[10][10]; //dict of possible actiuos base on the verb
} room;