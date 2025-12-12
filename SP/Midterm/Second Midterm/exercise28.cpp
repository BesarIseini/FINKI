#include <iostream>
using namespace std;

int main() {
    int matrix[100][100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int max = matrix[0][1];
    int min = matrix[1][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && matrix[i][j] < min) {
                min = matrix[i][j];
            }
            if (i < j && matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                matrix[i][j] = min;
            }
            if (i < j) {
                matrix[i][j] = max;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}