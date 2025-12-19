#include <iostream>
using namespace std;
int main() {
    int matrix[100][100], n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int array[100], counter = 0;
    for (int j = 0; j < m; j++) {
        int colSum1 = 0, colSum2 = 0;
        for (int i = 0; i < n / 2 + n % 2; i++) {
            colSum1 += matrix[i][j];
        }
        for (int i = n / 2; i < n ; i++) {
            colSum2 += matrix[i][j];
        }
        array[counter] = abs(colSum1 - colSum2);
        counter++;
    }


    for (int i = n / 2 - (n % 2 == 0); i <= n/2; i++) {
        for (int j = 0; j < counter; j++) {
            matrix[i][j] = array[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


}