#include <iostream>
#include <istream>
using namespace std;

int main() {
    int a[100][100], b[100][100], n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int posSum = 0;
            if (i > 0 && a[i - 1][j] > 0) posSum += a[i - 1][j];
            if (j > 0 && a[i][j - 1] > 0) posSum += a[i][j - 1];
            if (i < n - 1 && a[i + 1][j] > 0) posSum += a[i + 1][j];
            if (j < m - 1 && a[i][j + 1] > 0) posSum += a[i][j + 1];
            b[i][j] = posSum;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}