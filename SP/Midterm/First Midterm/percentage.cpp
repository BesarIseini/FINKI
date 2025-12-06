//
// Created by Besar on 14/11/2025.
//

#include <iostream>

using namespace std;

int main() {
    int number, counter = 0, correctCounter = 0;
    cin >> number;
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        if (a + b == number) {
            correctCounter++;
        }
        counter++;
    }
    cout << "You entered " << correctCounter << " pairs of numbers that have a sum equal to " << number << endl <<
    "The percentage of pairs with sum " << number << " is " << (float)correctCounter / counter * 100 << "%" << endl;

}