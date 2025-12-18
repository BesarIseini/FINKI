#include <iostream>
using namespace std;

int main() {
    int a[100][100], b[100][100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int neighbours = 0;
            if (j != 0 && a[i][j - 1] == 1) neighbours++;
            if (j != n - 1 && a[i][j + 1] == 1) neighbours++;
            if (i != 0 && a[i - 1][j] == 1) neighbours++;
            if (i != n - 1 && a[i + 1][j] == 1) neighbours++;

            if (neighbours >= 3) {
                b[i][j] = 1;
            } else {
                b[i][j] = a[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

