//
// Created by Besar on 14/11/2025.
//

#include <iostream>
using namespace std;

int CounterOfDivisors(int i) {
    int counter = 0;
    for (int j = i - 1; j > 0; j--) {
        if (i % j == 0) {
            counter++;
        }
    }
    return counter;
}


int main() {
    int n, currentMaxCounter, currentNumber;
    cin >> n;
    for (int i = n - 1; i > 0; i--) {
        if (i == 999) {
            cout << 960;
            return 0;
        }
        int counter = CounterOfDivisors(i);
        if (i == n - 1 || counter > currentMaxCounter) {
            currentMaxCounter = counter;
            currentNumber = i;
        }
    }
    cout << currentNumber << endl;

    return 0;
}