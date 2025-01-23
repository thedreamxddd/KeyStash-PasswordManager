#include "checkFile.h"

bool FileExists(const string& tempfile) {
	ifstream file(tempfile);
	return file.good();
}

bool FileDelete(const string& tempfile) {
	return (remove(tempfile.c_str()) == 0);
}






