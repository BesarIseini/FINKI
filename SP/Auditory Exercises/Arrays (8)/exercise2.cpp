#include <iostream>
using namespace std;

int main () {
    int arr[100], sumEven = 0, sumOdd = 0, nEven = 0, nOdd = 0, n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
            nEven++;
        } else {
            sumOdd += arr[i];
            nOdd++;
        }
    }

    cout << "Sum even: " << sumEven << endl;
    cout << "Sum odd: " << sumOdd << endl;
    cout << "Rel" << (float)nEven / nOdd;


    return 0;
}