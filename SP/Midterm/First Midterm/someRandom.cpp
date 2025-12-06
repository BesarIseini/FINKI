//
// Created by Besar on 14/11/2025.
//

#include <iostream>

using namespace std;

int switchFirstLast(int number) {
    int ld = number % 10, multiplier = 1;
    number /= 10;
    int temp = number;
    while (temp > 0) {
        multiplier *= 10;
        temp /= 10;
    }

    return ld * multiplier + number;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a = switchFirstLast(a);
        if (a > b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}