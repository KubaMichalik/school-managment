#include <iostream>
#include"student.h"
#include <iomanip>
using namespace std;

void Student::showData() {

	cout << "***STUDENT DETAILS***" << endl;
	cout << "ID                  : " << id <<endl;
	cout << "Firstname           : " << firstname << endl;
	cout << "Lastname            : " << lastname << endl;
	cout << "Student phone number: " << phonenumber << endl;
	cout << "Student e-mail      : " << studentEmail << endl;
	cout << "Gender              : " << gender << endl;
	cout << "Age                 : " << age << endl;
	cout << "Mother firstname    : " << motherFirstname << endl;
	cout << "Mothet lastname     : " << motherLastname << endl;
	cout << "Parents phone number: " << parentsPhonenumber << endl;
	

}

void Student::getData() {
	cout << "***ENTER STUDENT DETAILS***"<<endl;
	cout << "ID                  : ";
	cin >> id;
	cout << "Firstname           : ";
	cin >> firstname;
	cout << "Lastname            : "; 
	cin >> lastname;
	cout << "Student phone number: ";
	cin >> phonenumber;
	cout << "Student e-mail      : ";
	cin >> studentEmail;
	cout << "Gender              : ";
	cin >> gender;
	cout << "Age                 : ";
	cin >> age;
	cout << "Mother firstname    : ";
	cin >> motherFirstname;
	cout << "Mothet lastname     : ";
	cin >> motherLastname;
	cout << "Parents phone number: ";
	cin >> parentsPhonenumber;

}

void Student::listData(){
	
	cout.setf(ios::left);
	cout << setw(10) << id;
	cout << setw(10) << firstname;
	cout << setw(10) << lastname;
	cout << setw(15) << phonenumber;
	cout << setw(20) << studentEmail;
	cout << setw(8) << gender;
	cout << setw(5) << age;
	cout << setw(10) << motherFirstname;
	cout << setw(10) << motherLastname;
	cout << setw(15) << parentsPhonenumber;
	cout << endl;
}

void Student::heading() {
	cout.setf(ios::left);
	cout << setw(10) << "ID";
	cout << setw(10) << "Firstname";
	cout << setw(10) << "Lastname";
	cout << setw(15) << "St. phone number";
	cout << setw(20) << "St. email";
	cout << setw(8) << "Gender";
	cout << setw(5) << "Age";
	cout << setw(10) << "Mother firstname";
	cout << setw(10) << "Mother lastname";
	cout << setw(15) << "Parents phone number";
	cout << endl;

}