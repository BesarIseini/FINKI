#include <iostream>
using namespace std;
int main() {
    int a[100][100], n, changes = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        changes += a[i][i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            changes += (a[i][j] + a[j][i]) % 2;
        }
    }
    cout << changes << endl;

    return 0;
}