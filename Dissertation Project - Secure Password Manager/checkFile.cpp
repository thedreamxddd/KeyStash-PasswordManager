#include "checkFile.h"

//Checking if a File Exists Function
bool FileExists(const string& tempfile) {
	ifstream file(tempfile);
	return file.good();
}

//Deleting a File Function
bool FileDelete(const string& tempfile) {
	return (remove(tempfile.c_str()) == 0);
}






