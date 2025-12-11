#include <iostream>
using namespace std;

int main() {
    int matrix[100][100], n, m;
    float average = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int max = matrix[i][0];
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        matrix[i][m - 1] = max;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            average += matrix[i][j];
        }
    }
    average /= (1.0 * n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << average << endl;

    return 0;
}