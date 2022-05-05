#include <iostream>
#include "admin.h"

using namespace std;

void Admin::show() {
	cout << "Logging into admin's panel";
}

void Admin::login_admin(){
	int tries;
	cout <<endl<< "Hello Admin, give me your login: " << endl;
	cin >> name_admin;
	cout << endl << "... and password: " << endl;
	cin >> password_admin;

	/*
			if (name_admin == "admin" && password_admin == "admin") {
				cout << "Logged in successfully";
			}
			else {
				i++;
				cout << "Wrong login or password, try again, tries remaning: "<<5-i << endl;
			}
	}*/
}