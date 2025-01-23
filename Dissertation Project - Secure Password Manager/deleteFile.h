#ifndef DELETEFILE_H
#define DELETEFILE_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

class deleteFile {
private:
	string tempfile;
	string delete_file;

public:
	void getFileDelete();
};

#endif