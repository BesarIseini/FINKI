//
// Created by Besar on 14/11/2025.
//

#include <iostream>
using namespace std;

int main() {
    char znak;
    int current = 0, sum = 0;
    while (cin >> noskipws >> znak) {
        if (znak == '!') break;
        if (znak >= '0' && znak <= '9') {
            current = znak - '0' + current * 10;
        } else {
            sum += current;
            current = 0;
        }
    }
    sum += current;
    cout << sum << endl;

    return 0;
}