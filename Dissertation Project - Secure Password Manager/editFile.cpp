#include "checkFile.h"
#include "editFile.h"

//Edit File Function
void editFile::getEditFile() {
editingFile:
    //Identifying the name of the file
    cin.ignore();
    cout << "Enter the file name you would like to edit: " << endl;
    getline(cin, fileNameEdit);
    //Adding .txt in order to find file name
    tempFileName = fileNameEdit + ".txt";

    //Creating a duplicate file of the original file
    std::fstream fin, fout;
    fin.open(tempFileName, std::fstream::in);
    fout.open("temp.txt", std::fstream::out);

    //Decrypting original file
    while (fin >> std::noskipws >> c) {
        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }
    fin.close();
    fout.close();

    //If the file exists, enter the account details
    if (FileExists(tempFileName)){
        //Gathering all of the information to store
        cout << "Enter the details bellow correctly. " << endl;
        cout << "Login (Username/Email Address): " << endl;
        getline(cin, usernameEdit);
        cout << "Password: " << endl;
        getline(cin, passwordEdit);
        cout << "Direct Access Link: " << endl;
        getline(cin, linkEdit);
        cout << "Additional Information/Notes: " << endl;
        getline(cin, notesEdit);

       //Create the file if it exists
       ofstream editFile(tempFile, ios::trunc);
       editFile << fileNameEdit << "\t" << usernameEdit << "\t" << passwordEdit << "\t" << linkEdit << "\t" << notesEdit << "\t";
       //Close file   
       editFile.close();
       //Removing original file
       remove(tempFileName.c_str());

       fstream fin, fout;
       //Creating duplicate file of the decrypted file
       fin.open(tempFile, fstream::in);
       fout.open(tempFileName, fstream::out);

       // Reading original file till
       // end of file
       while (fin >> noskipws >> c) {
           int temp = (c + key);
           // Write temp as char in
           // output file
           fout << (char)temp;
       }

       // Closing both files
       fin.close();
       fout.close();

       //Removing the temporary file leaving the file still encrypted with the original name
       remove(tempFile.c_str());
       cout << "Password file successfully edited!" << endl;
    }
    else {
        cout << "File does not exist." << endl;
        cout << "\n 1. Re-attempt \n 2. Go Back \n" << endl;
    response1:
        cin >> response;
        if (response == "1") {
            goto editingFile;
        }
        else if (response == "2") {
            cout << "\nGoing back...." << endl;
        }
        else {
            cout << "\n This option doesn't exist!" << endl;
            goto response1;
        }
    }

}
