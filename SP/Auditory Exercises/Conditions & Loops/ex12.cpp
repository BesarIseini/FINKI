/*
    Created by Besar on 12/10/2025.
    Exercise 12
    Write a program that reads a date in the
    format (ddmmyyyy) from the keyboard. The
    program should print the day and the month
    of the birthdate.

    Example: If you enter the number 18091992,
    the program will print: 18.9

    Hint: Use integer division and the modulo operator.
*/

#include <iostream>
using namespace std;
/* int main() {
    long int date;
    int day, month;
    cout << "Enter your birthdate: ";
    cin >> date;
    day = date / 1000000;
    month = (date / 10000) % 100;
    cout << "Your birthday is " << day << "." << month << endl;

    return 0;
} */

/*
nota 5 - 0-50
nota 6 - 51-60
nota 7 - 61-70
nota 8 - 71-80
nota 9 - 81-90
nota 10 - 91-100

*/

int main() {
    /*int lineNumber;
    cin >> lineNumber;
    int waitTime = (lineNumber - 1) * 5;

    if (lineNumber > 60) {
        cout << "Nuk kryen pun" << endl;
    }
    if (lineNumber > 24) {
        waitTime += 30;
    }
    if (lineNumber > 36) {
        waitTime += 30;
    }

    if (lineNumber <= 60)
    cout << "Hours: " << waitTime / 60 << " minutes: " << waitTime % 60 << endl;
*/

    int age;
    cin >> age;

    // if (age >= 18) {
    //     if (age >= 18 && age <= 21) {
    //         cout << "true" << age << endl;
    //     } else {
    //         cout << "false" << age << endl;
    //     }
    //
    // } else {
    //     cout << "underage" << age << endl;
    // }

    // if (age >= 18 && age <= 21) {
    //     cout << 1;
    // } else if (age >= 22) {
    //     cout << 2;
    // } else {
    //     cout << 3;
    // }

    if (age >= 18) {
        cout << 1;
    } else if (age >= 21) {
        cout << 2;
    } else {
        cout << 3;
    }

    return 0;
}
