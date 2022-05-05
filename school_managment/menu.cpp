#include <iostream>
#include <string>
#include <set>
#include "admin.h"
#include "student.h"
#include "menu.h"
#include "teacher.h"
#include "createDatabase.h"

using namespace std;

void Menu::show() {
	int choice = 0;
	string txt = "  \
	\nWelcome to school managment system\n\n\
	1. Sign in as administrator\n\
	2. Sign in as student\n\
	3. Sign in as teacher\n\
	4. Exit\n\
	\n\
	";

	cout << txt;
}

int Menu::get(){
	cout << endl<<"Your choice: ";
		//<< string(70, 124) << string(40, '\b') << string(8, '\b');
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

void Menu::main_menu() {
	while (1) {
		Menu m;
		m.show();
		switch (m.get()) {
		case 1: {
			Admin* A = new Admin;
			A->show();
			A->login_admin();
			delete A;
			return;
			}
		case 2: {
			Student* S = new Student;
			S->show();
			delete S;
			return;
			}
		case 3: {
			Teacher* T = new Teacher;
			T->show();
			delete T;
			return;
			}
		case 4: {
			Menu* Men = new Menu;
			Men->menu_exit();
			delete Men;
			return;
			}
		default: {
			Menu* Men = new Menu;
			Men->clear_screen();
			delete Men;
			}
		}
	}
}
