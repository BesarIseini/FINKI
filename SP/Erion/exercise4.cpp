#include <iostream>
using namespace std;

int reverse(int number) {
    int reversed = 0;
    while (number > 0) {
        reversed = number % 10 + reversed * 10;
        number /= 10;
    }
    return reversed;
}

void abbr(int arr[], int n, int k) {
    int max = 0;
    bool first = true;
    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        int newNumber = 0;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            if (digit <= k) continue;
            newNumber = newNumber * 10 + digit;
        }
        newNumber = reverse(newNumber);
        if (first) {
            first = false;
            max = newNumber;
        }
        if (newNumber > max) {
            max = newNumber;
        }
    }
    cout << max << endl;
}

int main() {
    int arr[100], n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    abbr(arr, n, k);

    return 0;
}