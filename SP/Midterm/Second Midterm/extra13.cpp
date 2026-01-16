#include <iostream>
using namespace std;

void shiftRight(int arr[], int n) {
    int key = abs(arr[0]);

    for (int i = n - 1; i >= 0; i--) {
        if (key + i > n) {
            arr[i] = 0;
            continue;
        }

        arr[i + key] = arr[i];
        arr[i] = 0;
    }
}

void shiftLeft(int arr[], int n) {
    int key = abs(arr[0]);

    for (int i = 0; i < n; i++) {
        if (i - key < 0) {
            arr[i] = 0;
            continue;
        }

        arr[i - key] = arr[i];
        arr[i] = 0;
    }
}

int main () {
    int m;
    cin >> m;
    int counter = 0;
    for (int i = 0; i < m; i++) {
        int n, arr[100];
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        if (abs(arr[0]) >= n) {
            counter ++;
        }
        if (arr[0] > 0) {
            shiftRight(arr, n);
        } else {
            shiftLeft(arr, n);
        }
        for (int j = 0; j < n; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    cout << counter << endl;
}