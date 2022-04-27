#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "tableAttendance.h"
#include "createDatabase.h"

using namespace std;


static int createTableAttendance(const char* s);


void Attendance::tableAttendance() {
	const char* dir = "C:\\DeleteMe\\STUDENT.db";
	sqlite3* DB;

	DataBase::createDB(dir);
	createTableAttendance(dir);
}


static int createTableAttendance(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS ATTENDANCE("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"PRESENCE             CHAR(50), "
		"DATE                 DATE, "
		"LESSON_ID_LESSON     INTEGER FOREGIN_KEY REFERENCES LESSON(ID), "
		"STUDENT_ID_STUDENT   INTEGER FOREGIN_KEY REFERENCES STUDENT(ID) );";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTableAttendance function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table of attendance created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}

	return 0;
}

