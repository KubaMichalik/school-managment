#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "tableSubject.h"
#include "createDatabase.h"


using namespace std;


static int createTableSubject(const char* s);


void Subject::tableSubject() {
	const char* dir = "C:\\DeleteMe\\STUDENT.db";
	sqlite3* DB;

	DataBase::createDB(dir);
	createTableSubject(dir);
}


static int createTableSubject(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS SUBJECT("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"SUBJECT_NAME        CHAR(50) );";


	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTableSubject function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table of subjects created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}

	return 0;
}
