//
// Created by besar on 12/17/25.
//

#include <iostream>
using namespace std;
int main() {
    int matrix[100][100], n, m, minColSum = 0, minCol = 0;
    bool first = true;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        if (first) {
            minColSum = colSum;
            minCol = j;
            first = false;
        }
        else {
            if (colSum < minColSum) {
                minColSum = colSum;
                minCol = j;
            }
        }

    }
    cout << minCol << endl;

}