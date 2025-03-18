#include "createFile.h"
#include "checkFile.h"

//Create file function
void createFile::getFileCreate() {
    //Gathering all of the information to store
filecreate:
    cout << "Enter the details bellow correctly. " << endl;
    cout << "Account Name: " << endl;
    getline(cin, filename);
    tempFilename = filename + ".txt";
    //Checking if file already exists to avoid data clashing
    if (FileExists(tempFilename)) {
        cout << "Account Already Exists!" << endl;
        goto filecreate;
    }
    else {
        cout << "Login (Username/Email Address): " << endl;
        getline(cin, usernameCreate);
        cout << "Password: " << endl;
        getline(cin, passwordCreate);
        cout << "Direct Access Link: " << endl;
        getline(cin, linkCreate);
        cout << "Additional Information/Notes: " << endl;
        getline(cin, notesCreate);

        //If the process doesn't find any similarities, the file will be creates    
        ofstream fileCreate(tempFilename, ios::app);
        fileCreate << filename << "\t" << usernameCreate << "\t" << passwordCreate << "\t" << linkCreate << "\t" << notesCreate << "\t";
        fileCreate.close();

        fstream fin, fout;
        // Open input file
        //Creating a duplicate file in a different name
        fin.open(tempFilename, fstream::in);
        fout.open("temp.txt", fstream::out);

        //Encrypt the inside of the duplicate file
        while (fin >> noskipws >> c) {
            int temp = (c + key);

            // Write temp as char in
            // output file
            fout << (char)temp;
        }
        // Closing both files
        fin.close();
        fout.close();

        //Removing original "unencrypted file"
        remove(tempFilename.c_str());
        //Renaming new file to original
        rename("temp.txt", tempFilename.c_str());

        cout << "Account added to the Database." << endl;
    }
}
 