//
// Created by besar on 12/5/25.
//
#include <iostream>
using namespace std;

int main() {
    int matrix[100][100], n, min, max, diff;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    max = min = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    diff = max - min;
    for (int i = 0; i < n; i++) {
        matrix[i][i] = diff;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}