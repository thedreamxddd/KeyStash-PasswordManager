#include "passwordCreate.h"

//Creating Strong Password Function
void passwordCreate::getPasswordCreate() {
	//Setting a key to generate password
	char keySet[] = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()*+,-./:;<=>?@[]^_`{|}";
	uint32_t cur = 0, charSetCard = strlen(keySet);
	char curChar = '1';
	//Storing length of the password
passwordcreate:
	cout << "Input the length of the password:" << endl;
	cin >> length;
	if (length <= 12) {
		//If the password is bellow 12 characters, it will prompt user to re-enter
		cout << "The password is too short! Make sure that the Password is more than 12 Characters Long." << endl;
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