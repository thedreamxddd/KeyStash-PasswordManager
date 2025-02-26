#include "viewFile.h"
#include "disoverFile.h"

//Viewing Files Stored Function
void viewFile::getViewFile() {
viewfiles:
    //Identifying the directory path to find files
    cin.ignore();
    cout << "Enter the directory path of the stored files: " << endl;
    getline(cin, directoryPath);

    //Checking for a valid directory
    fs::path dirPath(directoryPath);
    if (!fs::exists(dirPath) || !fs::is_directory(dirPath)) {
        std::cerr << "The specified path is not a valid directory." << std::endl;
        goto viewfiles;
    }

    //Search for any files that end with the ".txt" extension and list if found.
    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            df2.geDiscoverFile(entry.path());
            cout << "Contents of " << entry.path() << ":\n";
        }
    }
}
  
//Viewing Inside of The File Function
void viewFile::getViewInsideFile() {
    //Identifying which file to view
    cin.ignore();
    viewingFile:
    cout << "Which account would you like to view?: " << endl;
    getline(cin, response);
    accountFile = response + ".txt";

    //Decrypting the original file
    std::fstream fin, fout;
    fin.open(accountFile, std::fstream::in);
    fout.open("temp.txt", std::fstream::out);

    while (fin >> std::noskipws >> c) {

        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }
    fin.close();
    fout.close();

    //Opening the decrypted file
    ifstream passwordFile("temp.txt");
    //Loop to check all lines in the file
    //If the file name matches, the inside of the file will be printed out
    while (getline(passwordFile, line)) {
        if (line.find(response) != string::npos) {
            cout << line << endl;
            located = true;
        }
    }
    //If file does not match, file does not exist.
    if (located == false) {
        cout << "File does not exist." << endl;
        cout << "\n 1. Re-attempt \n 2. Go Back \n" << endl;
    response1:
        cin >> response;
        cin.ignore();
        if (response == "1") {
            goto viewingFile;
        }
        else if (response == "2") {
            cout << "\nGoing back...." << endl;
        }
        else {
            cout << "\n This option doesn't exist!" << endl;
            goto response1;
        }
    }
    else {
        //Closing file & Removing the temporary decrypted file
        passwordFile.close();
        remove(tempFile.c_str());
    }
    

}