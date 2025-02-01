#ifndef CREATEFILE_H
#define CREATEFILE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class createFile {
private:
    string usernameCreate, passwordCreate, linkCreate, notesCreate;
    string filename, line, tempFilename;
    string externalID, exPassword, exFirstName, exLastName;
    bool found = false;
    bool located = false;

    int key = 8284200971542816123;
    char c;
public:
    void getFileCreate();
};
#endif

