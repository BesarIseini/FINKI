#include <iostream>
using namespace std;

int main() {
    int matrix[100][100], N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (i <= j) cout << matrix[i][j-i] << " ";
        }
        cout << endl;
    }

    return 0;
}