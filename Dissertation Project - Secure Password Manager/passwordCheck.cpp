#include "passwordCheck.h"
//REFERENCE: Ranjeet V.(2023) Code to check the password strength. Avaliable at https://www.codespeedy.com/password-strength-checker-in-cpp/

void passwordCheck::getStrengthCheck() {
passwordCheck:
    //Storing password to check for strength
    //side note, re werite to function with other code.
    cout << "Enter Lecturers Password:" << endl;
    cin >> password;
    //creating a veriable to split the password into letters one by one
    int length = password.size(), i;
    //loop to identify how many digits, uppercases and special characters are in the string
    for (i = 0; i < length; i++) {

        if (isupper(password[i]))
            upper_case = 10;
        if (isdigit(password[i]))
            digit = 10;
        if (isalpha(password[i]))
            special = 10;
    }
    //if statement to identify password strenght
    if (upper_case >= 4 && digit && special >= 3 && length >= 10) {
        cout << "Password Accepted, The password is Strong." << endl;
    }
    else if (upper_case && digit && special >= 2 && length >= 8) {
        cout << "Password accepted, the password is moderate" << endl;
    }
    else if (upper_case && digit && special >= 1 && length >= 4) {
        cout << "Password is weak, Please try a stronger password." << endl;
        goto passwordCheck;
    }
    else {
        cout << "Invalid password, Please increase the strength of the password." << endl;
        goto passwordCheck;
    }
    //END OF REFRENCE

}