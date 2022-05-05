#pragma once
#include<iostream>
#include "createDatabase.h"

using namespace std;

class Grades {

public:
	void tableGrades();
	friend static int DataBase::createDB(const char* s);
};