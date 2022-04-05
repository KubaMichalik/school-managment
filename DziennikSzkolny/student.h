#pragma once
#include <iostream>
using namespace std;


class Student {
	
	int age;
	int id;
	char firstname[20];
	char lastname[20];
	char gender;
	char phonenumber[20];
	char studentEmail[20];
	char motherFirstname[20];
	char motherLastname[20];
	char parentsPhonenumber[20];

public:
	void heading();

	void listData();

	void showData();

	void getData();
	

};