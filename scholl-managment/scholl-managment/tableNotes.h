#pragma once
#include<iostream>
#include "createDatabase.h"

using namespace std;

class Notes {

public:
	void tableNotes();
	friend static int DataBase::createDB(const char* s);
};

