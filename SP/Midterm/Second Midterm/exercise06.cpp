#include <iostream>
#include <cmath>
using namespace std;

int digitsCounter(int number) {
    if (number == 0) return 0;
    return 1 + digitsCounter(number / 10);
}

bool meetsCriteria(int n, bool firstCall = true) {

    if (firstCall && n % 2 != 0)
        return false;

    if (n < 10)
        return n % 2 == 1;

    return meetsCriteria(n / 10, false);
}

int main() {
    int arr[100], n, counter = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int digits = digitsCounter(arr[i]);
        if (meetsCriteria(arr[i])) {
            cout << arr[i] << endl;
            counter++;
        }
    }
    if (counter == 0) {
        cout << "No such elements!";
    }

}