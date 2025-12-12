#include <iostream>
using namespace std;

int Odd(int arr[], int n) {
    if (n == -1) return 0;
    if (abs(arr[n]) % 2 == 1) return 1 + Odd(arr, n - 1);
    return 0 + Odd(arr, n - 1);
}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Odd(arr, n - 1);

}