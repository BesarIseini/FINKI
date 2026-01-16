#include <iostream>
#include <cmath>
using namespace std;

int digitCounter (int number) {
    if (number == 0) return 1;
    int counter = 0;
    while (number != 0) {
        counter++;
        number /= 10;
    }
    return counter;
}

int main () {
    int n, m, matrix[120][120];
    int b[120][120];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        int counter = 0;
        for (int i = 0; i < n; i++) {
            int connotation = i * pow(10, digitCounter(j)) + j;
            if (connotation == matrix[i][j]) {
                counter++;
            }
        }
        cout << counter << endl;
    }
}