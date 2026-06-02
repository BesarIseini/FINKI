//
// Created by besar on 1/26/26.
//

#include <iostream>
using namespace std;

int main () {
    int matrix[100][100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * 10 + j;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     matrix[i][i] = 67;
    //     for (int j = 0; j < n; j++) {
    //         if (j > i) {
    //             matrix[i][j] = 89;
    //         }
    //         if (i > j) {
    //             matrix[i][j] = 90;
    //         }
    //     }
    //     matrix[i][n-1-i] = 69;
    //     for (int j = 0; j < n; j++) {
    //         if (n - 1 > i + j) {
    //             matrix[i][j] = 0;
    //         }
    //         if (n-1 < i + j) {
    //             matrix[i][j] = 11;
    //         }
    //     }
    //     if (matrix[i][i] == matrix[i][n-1-i]) {
    //         matrix[i][i] = 99;
    //     }
    // }


    // main diagonal 67
    // anti diagonal 69
    // mid if odd 99
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i && n-1 > i+j) {
                matrix[i][j] = 11;
            }
            if (j > i && n-1 < i+j) {
                matrix[i][j] = 22;
            }
            if (i > j && n-1 < i+j) {
                matrix[i][j] = 33;
            }
            if (i > j && n-1 > i+j) {
                matrix[i][j] = 44;
            }
        }
        if (i != n - 1 - i) {
            matrix[i][i] = 67;
            matrix[i][n-1-i] = 69;
        } else {
            matrix[i][i] = 99;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 10) {
                cout << 0;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << matrix[n-2][n-3] << endl;

}