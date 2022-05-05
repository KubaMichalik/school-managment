#include <iostream>
#include <string>
#include <set>
#include "menu.h"

using namespace std;

void Menu::show() {
	int choice = 0;
	string txt = "  \
	Welcome to scholl managment system\n\n\
	1. Sign in as administrator\n\
	2. Sign in as student\n\
	3. Sign in as teacher\n\
	4. Exit\n\
	\n\
	";

	cout << txt;
}

int Menu::get(){
	cout << endl << string(70, 124) << string(40, '\b') << string(8, '\b');
	int choice;
	cin >> choice;
	return choice;
}

void Menu::menu_exit() {
	cout << "Goodbye!!" << endl;
}

void Menu::clear_screen() {
	cout << string(1000, 10) << endl;
	return;
}

