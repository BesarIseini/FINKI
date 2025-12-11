//
// Created by Besar on 11/12/2025.
//

#include <iostream>
using namespace std;

int main() {
    int matrix[100][100], n, m, counter = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int ct = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) ct++;
            else ct = 0;

            if (ct == 3) {
                counter++;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 1) ct++;
            else ct = 0;
            if (ct == 3) {
                counter++;
                break;
            }
        }
    }

    cout << counter << endl;

    return 0;
}