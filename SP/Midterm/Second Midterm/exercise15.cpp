#include <iostream>
using namespace std;

int main() {
    int n;
    float matrix[100][100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    float zElements[100];
    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        zElements[counter] = matrix[0][i];
        counter++;
    }
    for (int i = 0; i < n; i++) {
        zElements[counter] = matrix[i][n-1-i];
        counter++;
    }
    for (int i = 1; i < n; i++) {
        zElements[counter] = matrix[n - 1][i];
        counter++;
    }


    int totalCounter = counter;

    for (int i = 0; i < n - 1; i++) {
        matrix[0][i] = zElements[--counter];
    }
    for (int i = 0; i < n; i++) {
        matrix[i][n-i-1] = zElements[--counter];
    }
    for (int i = 1; i < n; i++) {
        matrix[n - 1][i] = zElements[--counter];
    }

    for (int i = 0; i < totalCounter; i++) {
        cout << zElements[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}