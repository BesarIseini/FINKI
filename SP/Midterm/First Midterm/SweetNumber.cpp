//
// Created by Besar on 14/11/2025.
//

#include <iostream>
using namespace std;

bool isSweetNumber(int number) {
    while (number) {
        if ((number % 10) % 2 != 0) {
            return false;
        }
        number /= 10;
    }

    return true;
}

int main() {
    int m, n;
    cin >> m >> n;
    for ( int i = m; i <= n; i++) {
        if (isSweetNumber(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "NSN" << endl;
    return 0;
}