#include "deleteFile.h"
#include "checkFile.h"

//Delete File Function
void deleteFile::getFileDelete() {
deletefile:
	//Identifiying the name of file
	cin.ignore();
	cout << "Enter the file you would like to remove: " << endl;
	getline(cin, tempfile);
	//Adding .txt in order to find file name
	delete_file = tempfile + ".txt";

	//If the file is found, it will delete the file, otherwise it will prompt the user to re-enter file
	if (FileExists(delete_file)){
		if (FileDelete(delete_file)){
			cout << "File has been deleted successfully! " << endl;
		}
		else {
			cout << "File failed to delete." << endl;
		}
	}
	else {
		cout << "File does not exist." << endl;
		cout << "\n 1. Re-attempt \n 2. Go Back \n" << endl;
	response1:
		cin >> response;
		if (response == "1") {
			goto deletefile;
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


