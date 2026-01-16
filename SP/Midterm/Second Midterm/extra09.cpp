#include <iostream>

using namespace std;
int main () {
    int n, m, x1, y1, x2, y2;
    float a[50][50], b[50][50];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            float sum = 0;
            int neighbours = 0;
            if (i != 0) {
                sum += a[i - 1][j];
                neighbours++;
            }
            if (i != 0 && j != 0) {
                sum += a[i - 1][j - 1];
                neighbours++;
            }
            if (i != 0 && j != m - 1) {
                sum += a[i - 1][j + 1];
                neighbours++;
            }
            if (j != 0) {
                sum += a[i][j - 1];
                neighbours++;
            }
            if (j != m - 1) {
                sum += a[i][j + 1];
                neighbours++;
            }
            if (i != n - 1) {
                sum += a[i + 1][j];
                neighbours++;
            }
            if (i != n - 1 && j != 0) {
                sum += a[i + 1][j - 1];
                neighbours++;
            }
            if (i != n - 1 && j != m - 1) {
                sum += a[i + 1][j + 1];
                neighbours++;
            }
            sum += a[i][j];
            neighbours++;
            b[i][j] = sum * 1.0 / neighbours;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}