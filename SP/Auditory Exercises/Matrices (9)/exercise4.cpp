//
// Created by besar on 12/5/25.
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
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i - 1][j] == 1 && matrix[i][j - 1] == 1 && matrix[i + 1][j] == 1 && matrix[i][j + 1] == 1) {
                counter++;
                matrix[i-1][j] = 0;
                matrix[i][j-1] = 0;
                matrix[i+1][j] = 0;
                matrix[i][j+1] = 0;
            }
        }
    }
    cout << counter << endl;

    return 0;
}