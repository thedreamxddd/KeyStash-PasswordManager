#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <string>
using namespace std;

class Login {
private:
	string masterPassword;
	string masterPassword_Check = "password";
	int passwordTry = 0;
public:
	void getLogin();
};

#endif

