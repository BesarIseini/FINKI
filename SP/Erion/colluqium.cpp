//
// Created by besar on 1/20/26.
//

#include <iostream>
using namespace std;

bool isOdd(int n) {
    if (n == 0) {
        return true;
    }
    if ((n % 10) % 2 == 0) {
        return false;
    }
    return isOdd(n / 10);
}

int main () {
    int n, a[100];
    cin >> n;
    int pos1 = -1, pos2 = -1;
    bool isFirst = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (isOdd(a[i])) {
            cout << a[i] << " ";
            if (isFirst) {
                isFirst = false;
                pos1 = i;
                pos2 = i;
            }
            if (i > pos2) {
                pos2 = i;
            }
        }
    }
    if (pos1 == -1) {
        cout << "NEMA";
        return 0;
    }
    cout << endl << pos1 + 1 << " " << pos2 + 1 << " ";
}