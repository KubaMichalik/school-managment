#pragma once
#include<iostream>
#include "createDatabase.h"

using namespace std;

class Lesson {

public:
	void tableLesson();
	friend static int DataBase::createDB(const char* s);
};
