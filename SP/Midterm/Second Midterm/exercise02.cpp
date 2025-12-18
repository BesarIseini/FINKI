#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int factorielSumOfDigits(int n) {
    if (n == 0) return 0;
    return factorial(n % 10) + factorielSumOfDigits(n / 10);
}

bool isStrong(int number) {
    if (number == factorielSumOfDigits(number)) return true;
    return false;
}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Strong numbers: " << endl;
    for (int i = 0; i < n; i++) {
        if (isStrong(arr[i])) {
            cout << arr[i] << endl;
        }
    }


    return 0;
}