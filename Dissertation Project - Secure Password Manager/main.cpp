#include <iostream>
#include "login.h"
#include "passwordCheck.h"
#include "createFile.h"
#include "deleteFile.h"
#include "viewFile.h"
#include "editFile.h"
#include "passwordCreate.h"
#include "sodium.h"
using namespace std;

//TODO:
//Add Password Strength Check to Edit&Create files
//Re write the login option - create a file with the password stored there, if the file is there create a file etc.


int main()
{
//Variables
	Login l1;
	passwordCheck pc1;
	createFile cf1;
	deleteFile df1;
	viewFile vf1;
	editFile ef1;
	passwordCreate pcr1;
	string response;

//Login
	l1.getLogin();

//Account Acctions
Start:
	cout << "What would you like to do next?:" << endl;
	cout << "\n1. Add New Account \n2. Edit Existing Account(s) \n3. View Existing Account(s) \n4. Delete Account(s) \n5. Password Options \n6. Exit" << endl;
	cin >> response;

	if (response == "1") {
		cf1.getFileCreate();
		goto Start;
	}
	else if (response == "2") {
		ef1.getEditFile();
		goto Start;
	}
	else if (response == "3") {
	Viewing:
		cout << "1. List Account(s)" << "\n" << "2. View Existing Account(s)" << "\n" << "3. Go Back" << endl;
		cin >> response;
		if (response == "1") {
			vf1.getViewFile();
			goto Viewing;
		}
		else if (response == "2") {
			vf1.getViewInsideFile();
			goto Viewing;
		}
		else if (response == "3") {
			goto Start;
		}
		else {
			cout << "This Option Does Not Exist!" << endl;
			goto Viewing;
		}
	}
	else if (response == "4") {
		df1.getFileDelete();
		goto Start;
	}
	else if (response == "5") {
	Passwords:
		cout << "1. Generate Password" << "\n" << "2. Check Password Strength" << "\n" << "3. Go Back" << endl;
		cin >> response;
		if (response == "1") {
			pcr1.getPasswordCreate();
			goto Passwords;
		}
		else if (response == "2") {
			pc1.getStrengthCheck();
			goto Passwords;
		}
		else if (response == "3") {
			goto Start;
		}
		else {
			cout << "This Option Does Not Exist!" << endl;
			goto Passwords;
		}
	}
	else if (response == "6") {
		cout << "Shutting Down KeeStash...." << endl;
		exit(0);
	}
	else {
		cout << "This Option Does Not Exist!" << endl;
		goto Start;
	}
	return 0;
}