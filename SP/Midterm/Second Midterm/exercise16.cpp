//
// Created by Besar on 11/12/2025.
//

#include <iostream>
using namespace std;

int main() {
    char letter;
    while (cin >> noskipws >> letter) {
        if (letter >= 'A' && letter <= 'Z') {
            letter = letter - ('A' - 'a');
        }
        if (letter > 'z' - 3 && letter <= 'z') {
            letter -= 26;
        }
        if (letter >= 'a' - 3 && letter <= 'z' - 3) {
            letter +=3;
        }
        cout << letter;
    }

    return 0;
}