#ifndef CREATEFILE_H
#define CREATEFILE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class createFile {
private:
    string usernameCreate, passwordCreate, linkCreate, notesCreate;
    string filename, line, tempFileName;
    string externalID, exPassword, exFirstName, exLastName;
    bool found = false;
    bool located = false;

    int key = 493459394153;
    char c;
public:
    void getFileCreate();
};
#endif

