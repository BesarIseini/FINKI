#include <iostream>
using namespace std;

int main () {
    int matrix[100][100], n = 0, transformed[100][100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            transformed[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int newMainDiagonal = 0, newAntiDiagonal = 0;

        for (int j = i + 1; j < n; j++) {
            newMainDiagonal += matrix[i][j];
        }
        for (int ii = i - 1; ii >= 0; ii--) {
            newMainDiagonal += matrix[ii][i];
        }
        for (int j = i - 1; j >= 0; j--) {
            newAntiDiagonal += matrix[n - i -1][j];
        }
        for (int ii = n - i; ii < n; ii++) {
            newAntiDiagonal += matrix[ii][i];
        }
        transformed[i][i] = newMainDiagonal;
        transformed[n - i - 1][i] = newAntiDiagonal;
        if (n - 1 - i == i) {
            transformed[i][i] = newMainDiagonal + newAntiDiagonal;
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << transformed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}