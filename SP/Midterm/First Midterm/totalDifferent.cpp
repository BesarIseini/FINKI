//
// Created by Besar on 14/11/2025.
//

#include <iostream>
using namespace std;

bool isDifferent(int number, int digit) {

    while (number > 0) {
        int temp = digit;
        while (temp > 0) {
            if (number % 10 == temp % 10) return false;
            temp /= 10;
        }
        number /= 10;
    }

    return true;
}

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = n -1; ; i--) {
        if (isDifferent(i, x)) {
            cout << i;
            break;
        }

    }

    return 0;
}