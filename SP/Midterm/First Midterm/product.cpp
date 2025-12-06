//
// Created by Besar on 02/11/2025.
//

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int numbersFound = 0;
    for (int i = a; i <= b; i++) {
        int temp = i;
        int digits = 0;
        while (temp > 0) {
            temp /= 10;
            digits++;
        }
        int divider = 1, counterDiv = digits;
        while (counterDiv - 1 > 0) {
            divider *= 10;
            --counterDiv;
        }
        int firstDigit = i / divider;
        int lastDigit = i % 10;
        int secondDigit = (i / (divider / 10)) % 10;
        // cout << i << " " << secondDigit << endl;
        int middleDigits = i % divider / 10;

        int productOfMiddleDigits = 0;
        int j = middleDigits;
        bool isZero = false;
        while (j > 0) {
            int middleDigitsLast = j % 10;
            if (middleDigitsLast == 0 || secondDigit == 0) {
                isZero = true;
                break;
            }

            if (j == middleDigits) {
                productOfMiddleDigits = middleDigitsLast;
            } else {
                productOfMiddleDigits *= middleDigitsLast;
            }
            j /= 10;
        }

        if (isZero) continue;

        int numberFirstLast = firstDigit * 10 + lastDigit;

        if (!productOfMiddleDigits) continue;


        if (productOfMiddleDigits % numberFirstLast != 0) continue;

        int otherArgument = productOfMiddleDigits / numberFirstLast;

        numbersFound++;
        cout << i << " -> (" << productOfMiddleDigits << " == " << numberFirstLast << " * " << otherArgument << ")" << endl;
        // cout << "fd " << firstDigit  << " middle product " << middleDigits << " ld " << lastDigit <<
        //     " Product " << productOfMiddleDigits << "FL" << numberFirstLast << endl;



    }

    cout << numbersFound;
    return 0;
}

