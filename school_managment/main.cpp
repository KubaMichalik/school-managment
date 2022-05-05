#include<iostream>
#include<stdio.h>
#include<sqlite3.h>
#include"createDatabase.h"
#include "menu.h"
using namespace std;


int main()
{
	DataBase dat;
	dat.launchTables();

	Menu M;
	M.main_menu();

	return 0;
}



	


