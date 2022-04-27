#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "tableNotes.h"
#include "createDatabase.h"

using namespace std;


static int createTableNotes(const char* s);


void Notes::tableNotes() {
	const char* dir = "C:\\DeleteMe\\STUDENT.db";
	sqlite3* DB;

	DataBase::createDB(dir);
	createTableNotes(dir);
}


static int createTableNotes(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS NOTES("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"NOTE_DESCRIPTION     CHAR(50), "
		"LESSON_ID_LESSON     INTEGER FOREGIN_KEY REFERENCES LESSON(ID), "
		"STUDENT_ID_STUDENT   INTEGER FOREGIN_KEY REFERENCES STUDENT(ID) );";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTableNotes function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table of notes created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}

	return 0;
}

