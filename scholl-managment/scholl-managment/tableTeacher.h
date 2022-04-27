#pragma once
#include<iostream>
#include "createDatabase.h"

using namespace std;

class Teacher {

public:
	void tableTeacher();
	friend static int DataBase::createDB(const char* s);
};