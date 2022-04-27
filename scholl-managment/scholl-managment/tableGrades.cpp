#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "tableGrades.h"
#include "createDatabase.h"

using namespace std;


static int createTableGrades(const char* s);


void Grades::tableGrades() {
	const char* dir = "C:\\DeleteMe\\STUDENT.db";
	sqlite3* DB;

	DataBase::createDB(dir);
	createTableGrades(dir);
}


static int createTableGrades(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS GRADES("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"GRADE                INT NOT NULL, "
		"DESCRIPTION          CHAR(50), "
		"STUDENT_ID_STUDENT   INTEGER FOREGIN_KEY REFERENCES STUDENT(ID) );";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTableGrades function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table of grades created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}

	return 0;
}

