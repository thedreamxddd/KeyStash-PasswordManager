#ifndef PASSWORDCHECK_H
#define PASSWORDCHECK_H
#include <iostream>
#include <string>

using namespace std;

class passwordCheck {
private:
	string password;
	int upper_case = 0, digit = 0, special = 0;

public:
	void getStrengthCheck();
};

#endif
