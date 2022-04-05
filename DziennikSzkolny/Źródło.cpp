#include <iostream>
#include "sqllite/sqlite3.h"
#include <string>
#include "student.h"

#define MAX_CAPACITY 2

using namespace std;



int main() {
	char* err;
	sqlite3* db;
	sqlite3_stmt* stmt;
	sqlite3_open("myDb.db", &db);
	int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS algolancer(x1 INT, x2 INT, name varchar(100));", NULL, NULL, &err);
	if (rc != SQLITE_OK) {
		cout << "error: " << err;
	}
	for (int i = 0; i < 10; i++) {
		string query = "insert into algolancer VALUES ("+to_string(i)+", " + to_string(i+5) + ", 'fsadfdas');";
		cout << query << endl;
		rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
		if (rc != SQLITE_OK) {
			cout << "insert error: " << err;
		}
	}
	sqlite3_prepare_v2(db, "select x1, x2, name from algolancer where x1 > 7", -1, &stmt, 0);
	int a1, a2;
	const unsigned char* myname;
	while (sqlite3_step(stmt)!= SQLITE_DONE) {
		a1 = sqlite3_column_int(stmt, 0);
		a2 = sqlite3_column_int(stmt, 1);
		myname = sqlite3_column_text(stmt, 2);
		cout << "a1 = " << a1 << " a2 = " << a2 << " name = " << myname << endl;
	}
	


	/*Student s[MAX_CAPACITY];
	for (int i = 0; i < MAX_CAPACITY; i++) {
		cout << "Enter data for student number: " << i + 1 << endl;
		s[i].getData();
	}
	cout << endl << endl;
	
	s[0].heading();
	
	for (int i = 0; i < MAX_CAPACITY; i++) {
		s[i].listData();
	}
	cout << endl << endl;*/

}

