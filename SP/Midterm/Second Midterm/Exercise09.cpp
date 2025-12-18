#include <iostream>
using namespace std;

int main () {
    int n, m, matrix[100][100], counter = 0;
    cin >> n >> m;
    int arr[n * m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool duplicated = false;
            for (int k = 0; k < m; k++) {
                if (j == k) continue;
                if (matrix[i][j] == matrix[i][k]) {
                    duplicated = true;
                    break;
                }
            }
            if (duplicated) continue;
            arr[counter] = matrix[i][j];
            counter++;
        }
    }
    if (counter == 0) {
        cout << "N";
        return 0;
    }
    for (int i = 0; i < counter; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}