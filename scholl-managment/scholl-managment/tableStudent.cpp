#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "tableStudent.h"
#include "createDatabase.h"


using namespace std;


static int createTableStudent(const char* s);


void Student ::tableStudent() {
	const char* dir = "C:\\DeleteMe\\STUDENT.db";
	sqlite3* DB;
	
    DataBase::createDB(dir);
	createTableStudent(dir);
}


static int createTableStudent(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS STUDENT("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"STUDENT_FIRSTNAME    CHAR(50), "
		"STUDENT_LASTNAME     CHAR(50), "
		"STUDENT_AGE          INT NOT NULL, "
		"STUDENT_PHONENUMBER  INT NOT NULL, "
		"STUDENT_EMAIL        CHAR(50), "
		"MOTHER_FIRSTNAME     CHAR(50), "
		"MOTHER_LASTNAME      CHAR(50), "
		"PARENTS_PHONENUMBER  CHAR(50) );";



	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table of students created successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}

	return 0;
}
