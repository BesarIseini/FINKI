#include <iostream>
using namespace std;

int digitRepeater(int n, int d) {
    if (n == 0) {
        return 0;
    }
    if (n % 10 == d) {
        return 1 + digitRepeater(n / 10, d);
    } else {
        return digitRepeater(n / 10, d);
    }

}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = digitRepeater(arr[i], arr[i] % 10);
        cout << arr[i] << " ";
    }

    return 0;
}