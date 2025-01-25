#include "checkFile.h"
#include "editFile.h"

void editFile::getEditFile() {
editingFile:
    cout << "Enter the file name you would like to edit: " << endl;
    getline(cin, fileNameEdit);
    tempFileName = fileNameEdit + ".txt";

    std::fstream fin, fout;
    fin.open(tempFileName, std::fstream::in);
    fout.open("temp.txt", std::fstream::out);

    while (fin >> std::noskipws >> c) {

        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();


    if (FileExists(tempFile)){
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

       ofstream editFile(tempFile, ios::trunc);
       editFile << fileNameEdit << "\t" << usernameEdit << "\t" << passwordEdit << "\t" << linkEdit << "\t" << notesEdit << "\t";
       //Close file   
       editFile.close();
       remove(tempFileName.c_str());

       fstream fin, fout;
       // Open input file
       // ios::binary- reading file
       // character by character
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

       remove(tempFile.c_str());

       cout << "Password file successfully edited!" << endl;
        
    }
    else {
        cout << "File does not exist." << endl;
        goto editingFile;
    }



}
