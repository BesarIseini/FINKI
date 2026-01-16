#include <iostream>
using namespace std;

int main() {
    int n, m, matrix[100][100];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % 2 == (i + j) % 2) counter++;
        }
        cout << i << ": " << counter << endl;
    }
}