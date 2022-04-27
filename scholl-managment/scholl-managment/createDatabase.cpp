#include<iostream>
#include<stdio.h>
#include<sqlite3.h>
#include"createDatabase.h"
#include"tableStudent.h"
#include"tableGrades.h"
#include"tableTeacher.h"
#include"tableSubject.h"
#include"tableLesson.h"
#include"tableAttendance.h"
#include"tableNotes.h"

using namespace std;

int DataBase::createDB(const char* s) {

	sqlite3* DB;

	int exit = 0;
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);

	return 0;
}

void DataBase::launchTables() {

	Student table;
	table.tableStudent();

	Grades gr;
	gr.tableGrades();

	Teacher tea;
	tea.tableTeacher();

	Subject sub;
	sub.tableSubject();

	Lesson less;
	less.tableLesson();

	Attendance at;
	at.tableAttendance();

	Notes no;
	no.tableNotes();

}
