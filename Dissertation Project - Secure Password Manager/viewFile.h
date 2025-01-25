#ifndef VIEWFILE_H
#define VIEWFILE_H
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "disoverFile.h"
using namespace std;
namespace fs = filesystem;

class viewFile {
private:
	bool located = false;
	string response, accountFile;
	string line;
	string directoryPath;
	string insideFile;

	discoverFile df2;

	string tempFile = "temp.txt";
	int key = 493459394153;
	char c;

public:
	void getViewFile();
	void getViewInsideFile();
};

#endif

