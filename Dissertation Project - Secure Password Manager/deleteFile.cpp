#include "deleteFile.h"
#include "checkFile.h"

//Delete File Function
void deleteFile::getFileDelete() {
deletefile:
	//Identifiying the name of file
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
		goto deletefile;
	}
}


