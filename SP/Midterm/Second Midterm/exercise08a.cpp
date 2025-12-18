#include <iostream>
using namespace std;

int main () {
    int a[100][100], b[100][100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        if (j == 0 || j == n-1 || a[0][j] == 1) {
            b[0][j] = a[0][j];
            continue;
        }
        if (a[0][j - 1] == 1 && a[0][j + 1] == 1 && a[1][j] == 1) {
            b[0][j] = 1;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 || j == n-1 || a[i][j] == 1) {
                b[i][j] = a[i][j];
                continue;
            }
            int neighbours = 0;
            if (a[i][j - 1] == 1) neighbours++;
            if (a[i][j + 1] == 1) neighbours++;
            if (a[i + 1][j] == 1) neighbours++;
            if (a[i - 1][j] == 1) neighbours++;

            if (neighbours >= 3) b[i][j] = 1;
            else b[i][j] = a[i][j];
        }
    }
    for (int j = 0; j < n; j++) {
        if (j == 0 || j == n-1 || a[n - 1][j] == 1) {
            b[0][j] = a[n - 1][j];
            continue;
        }
        if (a[n - 1][j - 1] == 1 && a[n - 1][j + 1] == 1 && a[n - 2][j] == 1) {
            b[0][j] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
