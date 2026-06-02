//
// Created by besar on 1/26/26.
//

#include <iostream>
using namespace std;

int differenceFunc(int row[], int n) {
    int max = row[0];
    int min = row[0];
    for (int i = 0; i < n; i++) {
        if (max < row[i]) {
            max = row[i];
        }
        if (min > row[i]) {
            min = row[i];
        }
    }
    return max - min;
}

int main () {
    int n, m, matrix[100][100];
    cin >> n >> m;
    int index;
    int biggestDifference = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int currentDifference = differenceFunc(matrix[i], n);
        if (i == 0 || currentDifference >= biggestDifference) {
            biggestDifference = currentDifference;
            index = i;
        }
    }
    cout << index << endl;

    return 0;
}
