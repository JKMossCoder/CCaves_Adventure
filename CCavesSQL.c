#include "sqlite3.h"

extern char* version;

/* Function Prototypes here*/
int getCCVersion();
void getLocation(struct Location, int LocationID);

sqlite3* db;
char* err_msg = 0;
sqlite3_stmt* res;

int openDB(char* dbName) {
    int rc = sqlite3_open(dbName, &db);
    if (rc != SQLITE_OK) {
        err_msg = sqlite3_errmsg(db);
        sqlite3_close(db);
        return rc;
    }
    return 0;
}

void closeDB() {
    sqlite3_close(db);
}

int getCCVersion() {
    //char *name = "Flavio";
    //return name;
    //char* name;

    int rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);
    if (rc != SQLITE_OK) {
        err_msg = sqlite3_errmsg(db);
        //sqlite3_close(db);
        return rc;
    }

    rc = sqlite3_step(res);
    char* name;
    
    version = sqlite3_column_text(res, 0);
        
    return 0;    
}

void getLocation(struct Location locs[], int LocationID)
{
    //we pull the location informationm
    //and out it into thr init[] array
    char *sql = "";

}

/*
#include <sqlite3.h>
#include <stdio.h>

int main(void) {

    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;

    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "SELECT Id, Name FROM Cars WHERE Id = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK) {

        sqlite3_bind_int(res, 1, 3);
    } else {

        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW) {

        printf("%s: ", sqlite3_column_text(res, 0));
        printf("%s\n", sqlite3_column_text(res, 1));

    }

    sqlite3_finalize(res);
    sqlite3_close(db);

    return 0;
}
In the example, a question mark (?) is used as a placeholder which is later replaced with an actual value.

char *sql = "SELECT Id, Name FROM Cars WHERE Id = ?";
The question mark is used to provide an Id to the SQL query.

rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
The sqlite3_prepare_v2() function compiles the SQL query.

sqlite3_bind_int(res, 1, 3);
The sqlite3_bind_int() binds an integer value to the prepared statement. The placeholder is replaced with integer value 3. The function's second parameter is the index of the SQL parameter to be set and the third parameter is the value to bind to the parameter.

int step = sqlite3_step(res);
The sqlite3_step() function evaluates the SQL statement.

if (step == SQLITE_ROW) {

    printf("%s: ", sqlite3_column_text(res, 0));
    printf("%s\n", sqlite3_column_text(res, 1));

}
If there is some row of data available, we get the values of two columns with the sqlite3_column_text() function.

$ ./parameterized
3: Skoda
The example returns the Id and the car's name.

The second example uses parameterized statements with named placeholders.

named_placeholders.c
#include <sqlite3.h>
#include <stdio.h>

int main(void) {

    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;

    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "SELECT Id, Name FROM Cars WHERE Id = @id";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK) {

        int idx = sqlite3_bind_parameter_index(res, "@id");
        int value = 4;
        sqlite3_bind_int(res, idx, value);

    } else {

        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW) {

        printf("%s: ", sqlite3_column_text(res, 0));
        printf("%s\n", sqlite3_column_text(res, 1));

    }

    sqlite3_finalize(res);
    sqlite3_close(db);

    return 0;
}
*/