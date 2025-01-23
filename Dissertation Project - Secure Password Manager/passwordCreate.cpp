#include "passwordCreate.h"

void passwordCreate::getPasswordCreate() {
	char keySet[] = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()*+,-./:;<=>?@[]^_`{|}";
	uint32_t cur = 0, charSetCard = strlen(keySet);
	char curChar = '1';
passwordcreate:
	cout << "Input the length of the password:" << endl;
	cin >> length;
	if (length <= 12) {
		cout << "The password is too short!" << endl;
		goto passwordcreate;
	}

	cout << "Your strong password is:" << endl;

		for (int j = 0; j < length; j++)
		{
			cur = randombytes_uniform(charSetCard);
			curChar = keySet[cur];
			cout << curChar;
		}
		cout << "\n";
}