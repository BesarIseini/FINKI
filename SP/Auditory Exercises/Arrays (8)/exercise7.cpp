//
// Created by besar on 12/1/25.
//

#include <iostream>
using namespace std;

int main() {
    int a[100], n, deleted = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - deleted; i++) {
        for (int j = i + 1; j < n - deleted; j++) {
            if (a[i]==a[j]) {
                for (int k = j; k < n - deleted - 1; k++) {
                    a[k] = a[k + 1];
                }
                deleted++;
                j--;
            }
        }
    }
    n-=deleted;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}