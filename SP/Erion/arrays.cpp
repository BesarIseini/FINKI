//
// Created by besar on 1/20/26.
//

#include <iostream>
using namespace std;

int main() {
    int a[100], n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    // for (int i = n - 1; i > 0; i--) {
    //     if (i < k) {
    //         a[i] = 0;
    //         continue;
    //     }
    //     if (i + k < n - 1) {
    //         continue;
    //     }
    //
    //     a[i] = a[i-k];
    //
    //
    // }
    for (int i = 0; i < k; i++) {
        int temp = a[0];
        for (int j = 0; j < n; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = temp;
    }
    for (int i = 0; i < k; i++) {
        int temp = a[n - 1];
        for (int j = n - 1; j > 0; j--) {
            a[j] = a[j - 1];
        }
        a[0] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }


    return 0;
}
