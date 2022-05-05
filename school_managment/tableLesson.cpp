#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "tableLesson.h"
#include "createDatabase.h"

using namespace std;


static int createTableLesson(const char* s);


void Lesson::tableLesson() {
	const char* dir = "C:\\DeleteMe\\STUDENT.db";
	sqlite3* DB;

	DataBase::createDB(dir);
	createTableLesson(dir);
}


static int createTableLesson(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS LESSON("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"LESSON_NAME          CHAR(50), "
		"CLASSROOM_NUMBER     INT NOT NULL, "
		"STUDENTS_NUMBER      INT NOT NULL, "
		"SUBJECT_ID_SUBJECT   INTEGER FOREGIN_KEY REFERENCES SUBJECT(ID) );";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTableLesson function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table of lesson created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}

	return 0;
}

