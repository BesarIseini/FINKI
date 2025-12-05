//
// Created by besar on 12/5/25.
//
#include <iostream>
using namespace std;

int main() {
    int matrix[100][100], m, n, oddColSum = 0, evenRowSum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j % 2 == 1) {
                oddColSum += matrix[i][j];
            }
            if (i % 2 == 0) {
                evenRowSum += matrix[i][j];
            }
        }
    }
    cout<< abs(oddColSum - evenRowSum) << endl;
    return 0;
}