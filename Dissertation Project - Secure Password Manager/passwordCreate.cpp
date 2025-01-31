#include "passwordCreate.h"

//Creating Strong Password Function
void passwordCreate::getPasswordCreate() {
	//Setting a key to generate password
	char keySet[] = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()*+,-./:;<=>?@[]^_`{|}";
	uint32_t cur = 0, charSetCard = strlen(keySet);
	char curChar = '1';

	//Storing length of the password
passwordcreate:
	//Running a loop to identify a rouge entry
	cout << "Input the length of the password:" << endl;
	while (!(cin >> length)) {

		cout << "Invalid Input!" << endl;
		//Clear the error flags and discard the contents
		//So that the process can be repeated
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

	}
	//If Statements to ensure that the number of bytes cannot be bellow 12 or higher than 256
	if (length <= 12) {
		//If the password is bellow 12 characters, it will prompt user to re-enter
		cout << "The password is too short!" << endl;
		goto passwordcreate;
	}
	else if (length > 256) {
		cout << "Invalid Input!" << endl;
		goto passwordcreate;
	}

	cout << "Your strong password is:" << endl;
	//Loop to generate a the number of bytes to create the full password
		for (int j = 0; j < length; j++)
		{
			cur = randombytes_uniform(charSetCard);
			curChar = keySet[cur];
			cout << curChar;
		}
		cout << "\n";
}