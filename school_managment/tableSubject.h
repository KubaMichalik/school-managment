#pragma once
#include<iostream>
#include "createDatabase.h"

using namespace std;

class Subject {

public:
	void tableSubject();
	friend static int DataBase::createDB(const char* s);
};

