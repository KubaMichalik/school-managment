#pragma once
#include<iostream>
#include "createDatabase.h"

using namespace std;

class Attendance {

public:
	void tableAttendance();
	friend static int DataBase::createDB(const char* s);
};
