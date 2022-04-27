#pragma once
#include<iostream>
#include "createDatabase.h"

using namespace std;

class Student {

public:
	void tableStudent();
	friend static int DataBase::createDB(const char* s);
};
