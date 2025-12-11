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
    cout << n << endl;
    count_up(n - 1);
}

int main() {
    count_up(10);
}