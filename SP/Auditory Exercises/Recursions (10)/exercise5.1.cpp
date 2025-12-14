#include <iostream>
using namespace std;

int sumElements(int array[], int n) {
    if (n == 0) return array[0];
    return array[n] + sumElements(array, n - 1);
}

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << sumElements(arr, n - 1) << endl;
}