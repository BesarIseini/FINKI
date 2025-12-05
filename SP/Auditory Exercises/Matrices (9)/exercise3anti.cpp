//
// Created by besar on 12/5/25.
//
#include <iostream>
using namespace std;
int main() {
    int matrix[100][100], n;
    bool symetric = true;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1 + i; j < n; j++) {
            if (matrix[n - 1 - j][n - 1 - i] != matrix[n - 1 - i][n - 1 - j]) {
               symetric = false;
                break;
            }
        }
        if (!symetric) {
            break;  
        }
    }
    if (symetric) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}