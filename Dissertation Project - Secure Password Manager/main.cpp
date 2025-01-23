#include <iostream>
#include "login.h"
#include "passwordCheck.h"
#include "createFile.h"
#include "deleteFile.h"
#include "viewFile.h"
#include "editFile.h"
#include "passwordCreate.h"
#include "sodium.h"
using namespace std;

int main()
{
	Login l1;
	passwordCheck pc1;
	createFile cf1;
	deleteFile df1;
	viewFile vf1;
	editFile ef1;
	passwordCreate pcr1;

	pcr1.getPasswordCreate();
	cout << "Hello Wordld" << endl;
	

    return 0;
}
