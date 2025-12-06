//
// Created by Besar on 14/11/2025.
//

#include <iostream>
using namespace std;

int convertDates(int date) {
    int day, month, year, converted;
    year = date % 10000;
    month = (date / 10000) % 100;
    day = (date / 1000000) % 100;
    converted = year * 365 + month * 30 + day;
    return converted;
}

bool over18(int currentDate, int pastdate) {
    int convertedCurrent = convertDates(currentDate);
    int pastCurrent = convertDates(pastdate);
    int difference = convertedCurrent - pastCurrent;
    if (difference < 18 * 365) {
        return false;
    }
    return true;
}

int main() {
    int currentDate;
    cin >> currentDate;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int date;
        cin >> date;
        if (over18(currentDate, date)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }


    return 0;
}
