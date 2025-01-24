#include "createFile.h"

//Create file function
void createFile::getFileCreate() {
filecreate:
    //Gathering all of the information to store
    cout << "Enter the details bellow correctly: " << endl;
    cout << "Account Name: " << endl;
    getline(cin, filename);
    cout << "Login (Username/Email Address): " << endl;
    getline(cin, usernameCreate);
    //add password check here after <------------- important
    cout << "Password: " << endl;
    getline(cin, passwordCreate);
    cout << "Direct Access Link: " << endl;
    getline(cin, linkCreate);
    cout << "Additional Information/Notes: " << endl;
    getline(cin, notesCreate);
    tempFileName = filename + ".txt";

    //Open the file
    ifstream fileCreate(tempFileName);
    //Loop to check every line
    while (getline(fileCreate, line)) {
        if (line == filename) {
            found = true;
            break;
        }
    }
    fileCreate.close();
    //If the line is the same, it will promt the user to redo the process

    if (found) {
        cout << "An account with this account name already exists!" << endl;
        found = false;
        goto filecreate;
    }
    else {
        //If the process doesn't find any similarities, the file will be creates    
        ofstream fileCreate(tempFileName, ios::app);
        fileCreate << filename << "\n" << usernameCreate << "\n" << passwordCreate << "\n" << linkCreate << "\n" << notesCreate << "\n";
        //Close file   
        fileCreate.close();


        fstream fin, fout;
        // Open input file
        // ios::binary- reading file
        // character by character
        fin.open(tempFileName, fstream::in);
        fout.open(filename + "text.txt", fstream::out);

        // Reading original file till
        // end of file
        while (fin >> noskipws >> c) {
            int temp = (c + key);

            // Write temp as char in
            // output file
            fout << (char)temp;
        }

        cout << "File sucessfully Encrypted" << endl;
        // Closing both files
        fin.close();
        fout.close();
    }
    cout << "Account added to the Database." << endl;
}