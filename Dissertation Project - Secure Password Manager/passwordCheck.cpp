#include "passwordCheck.h"
//REFERENCE: Ranjeet V.(2023) Code to check the password strength. Avaliable at https://www.codespeedy.com/password-strength-checker-in-cpp/

//Checking Password Strength Function
void passwordCheck::getStrengthCheck() {
    //Storing password to check for strength
    cout << "Enter Password:" << endl;
    getline(cin, password);
    //Creating a veriable to split the password into letters one by one
    int length = password.size(), i;
    //Loop to identify how many digits, uppercases and special characters are in the string
    for (i = 0; i < length; i++) {

        if (isupper(password[i]))
            upper_case = 128;
        if (isdigit(password[i]))
            digit = 128;
        if (isalpha(password[i]))
            special = 128;
    }
    //If statement to identify password strength
    if (upper_case > 4 && digit && special > 3 && length > 10) {
        cout << "The Password is Strong." << endl;
    }
    else if (upper_case && digit && special > 2 && length > 8) {
        cout << "The Password is Moderate." << endl;
    }
    else if (upper_case && digit && special > 1 && length > 4) {
        cout << "The Password is Weak, make sure to generate a strong password." << endl;
    }
    else {
        cout << "The Password is Very Weak, make sure to generate a strong password." << endl;
    }
}