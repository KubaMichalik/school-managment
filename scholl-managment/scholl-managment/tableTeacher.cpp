#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "tableTeacher.h"
#include "createDatabase.h"


using namespace std;


static int createTableTeacher(const char* s);


void Teacher::tableTeacher() {
	const char* dir = "C:\\DeleteMe\\STUDENT.db";
	sqlite3* DB;

	DataBase::createDB(dir);
	createTableTeacher(dir);
}


static int createTableTeacher(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS TEACHER("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"TEACHER_FIRSTNAME    CHAR(50), "
		"TEACHER_LASTNAME     CHAR(50), "
		"TEACHER_PHONENUMBER  INT NOT NULL, "
		"TEACHER_EMAIL        CHAR(50) );";
		
		
		



	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTableTeacher function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table of teachers created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}

	return 0;
}
