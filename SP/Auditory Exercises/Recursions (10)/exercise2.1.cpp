//
// Created by Besar on 06/12/2025.
//

#include <iostream>
using namespace std;

void count_up(int n) {
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    count_up(n - 1);
    cout << n << endl;
}

int main() {
    count_up(10);
}