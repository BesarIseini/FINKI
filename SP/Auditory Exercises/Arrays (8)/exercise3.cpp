//
// Created by besar on 11/28/25.
//

#include <iostream>
using namespace std;

void fillArray(int arr[], int el) {
    for (int i = 0; i < el; i++) {
        cin >> arr[i];
    }
}

int main() {
    int a[100], b[100], n, scalar = 0;
    cin >> n;
    fillArray(a, n);
    fillArray(b, n);
    for (int i = 0; i < n; i++) {
        scalar += a[i] * b[i];
    }
    cout << scalar << endl;
    return 0;
}