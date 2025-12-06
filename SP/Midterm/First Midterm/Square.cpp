//
// Created by Besar on 02/11/2025.
//

/*
Using the characters + and - form a square image with "width" n (n > 2) that
represent square of the chars -, enclosed by a square of chars + (view examples).
For given n, print the appropriate image.

Attention: do not print additional characters as empty spaces, or unnecessary new line...
The image ends with new line char. Do not use any matrix or arrays because n is not limited.

*/

#include <iostream>
using namespace std;

int main() {
    int width;
    cin >> width;
    if (width <= 2) {
        return 0;
    }
    for (int i = 1; i <= width; i++) {
        if (i == 1) {
            int temp = width;
            while (temp > 0) {
                cout << "+";
                temp -= 1;
            }
            cout << endl;
        } else if (i != width) {
            cout << "+";
            int temp = width - 2;
            while (temp > 0) {
                cout << "-";
                temp -= 1;
            }
            cout << "+" << endl;
        } else if (i == width) {
            int temp = width;
            while (temp > 0) {
                cout << "+";
                temp -= 1;
            }
            cout << endl;
        }
    }


    return 0;
}