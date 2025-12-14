#include <iostream>
using namespace std;

int largestElement(int arr[], int n, int max) {
    if (n == 0) return max;
    if (arr[n] > max) return largestElement(arr, n - 1, arr[n]);
    return largestElement(arr, n - 1, max);
}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << largestElement(arr, n - 1, arr[0]);

    return 0;
}
