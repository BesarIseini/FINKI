//
// Created by besar on 12/1/25.
//

#include <iostream>
using namespace std;

int main() {
    int a[100], b[100], k, n;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int c = (i + k) % n;
        b[c] = a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }


    return 0;
}