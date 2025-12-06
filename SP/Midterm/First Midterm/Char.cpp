//
// Created by Besar on 02/11/2025.
//

#include <iostream>
using namespace std;

int main() {
    char a;
    int b = 0, c = 0;
    int sum = 0;
    while (cin >> noskipws >> a && a != '!') {
        if (a >= '0' && a <= '9') {
            b = a - '0' + c * 10;
            if (b < 10) {
                c = b;
            } else {
                sum += b;
                c = 0;
                b = 0;
            }


        } else {
            sum += b;
            b = 0;
            c = 0;
        }
    }
    sum += b;
    cout << sum;
}