#include <iostream>
#include <cmath>
using namespace std;

int digits(int n) {
    if (n == 0) return 0;
    return 1 + digits(n/10);
}

int abbreviatedNumber(int number, int k) {
    int newNumber = 0;
    for (int i = 1; i <= digits(number); i++) {
        int digit = number / (int)pow(10, digits(number) - i) % 10;
        if (digit <= k) {
            continue;
        }
        newNumber = newNumber * 10 + digit;
    }
    return newNumber;
}

int abbreviatedNumberArray(int arr[], int n, int k) {
    int maxAbbreviated = 0, maxIndex = 0;
    for (int i = 0; i < n; i++) {
        int newNum = abbreviatedNumber(arr[i], k);
        if (newNum > maxAbbreviated) {
            maxIndex = i;
            maxAbbreviated = newNum;
        }
    }
    return maxAbbreviated;
}

int main() {
    int a[100], n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    cout << abbreviatedNumberArray(a, n, k) << endl;

}