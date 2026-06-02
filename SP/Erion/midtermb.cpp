//
// Created by besar on 1/26/26.
//

#include <iostream>
using namespace std;

int differenceFunc(int matrix[100][100], int j, int n) {
    int min = matrix[0][j];
    int max = matrix[0][j];
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] < min) {
            min = matrix[i][j];
        }
        if (matrix[i][j] > max) {
            max = matrix[i][j];
        }
    }
    return max-min;
}



int main() {
    int n, m;
    cin >> n >> m;
    int matrix[100][100];
    int biggestDifference, index;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        int currentDifference = differenceFunc(matrix, j, n);
        if (j == 0 || currentDifference >= biggestDifference) {
            biggestDifference = currentDifference;
            index = j;
        }
    }
    cout << index << endl;
}