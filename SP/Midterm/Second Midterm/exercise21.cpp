//
// Created by Besar on 11/12/2025.
//

#include <iostream>
using namespace std;

int main() {
    int matrix[100][100], n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cin >> x >> y;
     if (matrix[x][y] == 0) {
         matrix[x][y] = 1;
         for (int i = x + 1; i < n; i++) {
             if (matrix[i][y] == 0) matrix[i][y] = 1;
             else if (matrix[i][y] == 1) break;
         }
         for (int i = x - 1; i >= 0; i--) {
             if (matrix[i][y] == 0) matrix[i][y] = 1;
             else if (matrix[i][y] == 1) break;
         }
         for (int i = y + 1; i < m; i++) {
             if (matrix[x][i] == 0) matrix[x][i] = 1;
             else if (matrix[x][i] == 1) break;
         }
         for (int i = y - 1; i >= 0; i--) {
             if (matrix[x][i] == 0) matrix[x][i] = 1;
             else if (matrix[x][i] == 1) break;
         }

     }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}