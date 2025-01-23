#include "login.h"

//Login Function
void Login::getLogin() {
tryAgain:
	//Stores the user password as a variable
	cout << "Please enter your master password: " << endl;
	cin >> masterPassword;
	
	//Checks stored variable against hardcoded password
	//Side Note (the idea is that a 2 step verification code would be the "master key"
	if (masterPassword == masterPassword_Check) {
		cout << "Welcome to Pass Manager!" << endl;
	}
	//Checking for amount of tries, if equal to 3, shuts down the app
	//If the amount of tries is bellow 3, it promts the user to try again
	else {
		if (passwordTry == 3) {
			cout << "Too many login attempts. Shutting down.";
			exit;
		}
		else {
			passwordTry++;
			cout << "Password is incorrect, try again!" << endl;
			cout << "You have " << (4 - passwordTry) << " attempts left." << endl;
			goto tryAgain;
		}
	}
	
}