#include "viewFile.h"
#include "disoverFile.h"

void viewFile::getViewFile() {
   
viewfiles:
    cout << "Enter the directory path of the stored files: " << endl;
    getline(cin, directoryPath);

    fs::path dirPath(directoryPath);
    if (!fs::exists(dirPath) || !fs::is_directory(dirPath)) {
        std::cerr << "The specified path is not a valid directory." << std::endl;
        goto viewfiles;
    }

    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            df2.geDiscoverFile(entry.path());
            cout << "Contents of " << entry.path() << ":\n";
        }
    }

}
  

void viewFile::getViewInsideFile() {
    cout << "Which account would you like to view?: " << endl;
    getline(cin, response);
    accountFile = response + ".txt";

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

    ifstream passwordFile("temp.txt");
    //loop to check all lines in the file
    //if the enrolement number insered is detected print out the line
    while (getline(passwordFile, line)) {
        if (line.find(response) != string::npos) {
            cout << line << endl;
            located = true;
        }
    }
    //if no value detected, print out message
    if (located == false) {
        cout << "No Match found!" << endl;
    }
    //close file
    passwordFile.close();
    remove(tempFile.c_str());

}