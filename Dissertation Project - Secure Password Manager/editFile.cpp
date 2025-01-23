#include "checkFile.h"
#include "editFile.h"

void editFile::getEditFile() {
editingFile:
    cout << "Enter the file name you would like to edit: " << endl;
    getline(cin, fileNameEdit);
    tempFileName = fileNameEdit + ".txt";

    if (FileExists(tempFileName)){
        //Gathering all of the information to store
        cout << "Enter the details bellow correctly: " << endl;
        cout << "Login (Username/Email Address): " << endl;
        getline(cin, usernameEdit);
        //add password check here after <------------- important
        cout << "Password: " << endl;
        getline(cin, passwordEdit);
        cout << "Direct Access Link: " << endl;
        getline(cin, linkEdit);
        cout << "Additional Information/Notes: " << endl;
        getline(cin, notesEdit);

       ofstream editFile(fileNameEdit + ".txt", ios::trunc);
       editFile << fileNameEdit << "\t" << usernameEdit << "\t" << passwordEdit << "\t" << linkEdit << "\t" << notesEdit << "\t";
       //Close file   
       editFile.close();
       cout << "Password file successfully edited!" << endl;
        
    }
    else {
        cout << "File does not exist." << endl;
        goto editingFile;
    }



}
