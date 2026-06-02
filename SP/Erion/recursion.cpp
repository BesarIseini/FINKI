//

#include <iostream>
using namespace std;

int findDigitsLoop(int number) {
    int digits = 0;
    while (number) {
        digits++;
        number = number / 10;
    }
    return digits;
}

int findDigitsRecursion(int number) {
    if (number == 0) {
        return 0;
    }
    return 1 + findDigitsRecursion(number / 10);
}

int factorielRecursion(int number) {
    if (number == 0) {
        return 1;
    }
    return number * factorielRecursion(number - 1);
}

int factorialLoop(int number) {
    int product = 1;
    while (number > 0) {
        product *= number;
        number--;
    }
    return product;
}

bool palindromeRecursion(int number[], int start = 0, int end = 0) {
    if (start >= end) {
        return true;
    }
    if (number[start] != number[end]) {
        return false;
    }
    return palindromeRecursion(number, start + 1, end - 1);
}

bool isPalindromeLoop(int number[], int n) {
    for (int i = 0; i < n; i++) {
        if (number[i] != number[n-i-1]) return false;
    }
    return true;
}

bool allOdd(int number) {
    if (number < 10) {
        return number % 2 == 1;
    }
    if ((number % 10) % 2 == 0) return false;
    return allOdd(number / 10);
}

int main() {
    // int digits;
    int number;
    while (cin>> number) {
        cout << allOdd(number) << endl;

    }
    // cin >> number;
    // cout << "While Loops Digits: " << findDigitsLoop(number) << endl;
    // cout << "Recursive Digits: " << findDigitsRecursion(number) << endl;
    // cout << "Factorial Recursive: " << factorielRecursion(number) << endl;
    // cout << "Factorial Loop: " << factorialLoop(number) << endl;
    //
    // int array[6];
    // array[0] = 1;
    // array[1] = 2;
    // array[2] = 3;
    // array[3] = 3;
    // array[4] = 2;
    // array[5] = 1;
    //
    // cout << palindromeRecursion(array, 0, 5) << endl;
    // cout << isPalindromeLoop(array,6) << endl;
}