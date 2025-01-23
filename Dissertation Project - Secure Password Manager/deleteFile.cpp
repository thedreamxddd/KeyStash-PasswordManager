#include "deleteFile.h"
#include "checkFile.h"

void deleteFile::getFileDelete() {
	deletefile:
	cout << "Enter the file you would like to remove: " << endl;
	getline(cin, tempfile);
	delete_file = tempfile + ".txt";

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


