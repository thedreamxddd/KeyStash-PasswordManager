#ifndef EDITFILE_H
#define EDITFILE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class editFile {
private:
	string usernameEdit, passwordEdit, linkEdit, notesEdit;
	string fileNameEdit, tempFileName;

	string tempFile = "temp.txt";
	int key = 493459394153;
	char c;
public:
	void getEditFile();
};

#endif
