#pragma once
#include <iostream>
#include "./createDatabase.h"

using namespace std;

class Admin: public DataBase {
	string name_admin;
	string password_admin;
public:
	void show();
	void login_admin();
};
