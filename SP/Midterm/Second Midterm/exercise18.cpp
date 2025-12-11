//
// Created by Besar on 11/12/2025.
//
#include <iostream>
using namespace std;

int digitCounterEvenPositions(int number, int digit) {
    int counter = 0;
    number /= 10;
    while (number != 0) {
        if (number % 10 == digit) counter++;
        number /= 100;
    }

    return counter;
}

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        int aD = digitCounterEvenPositions(a, c);
        int bD = digitCounterEvenPositions(b, c);
        if (aD >= bD) {
            cout << a << endl;
        } else {
            cout << b << endl;
        }
    }

    return 0;
}