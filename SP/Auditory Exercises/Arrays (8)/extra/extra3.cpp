// 5. How Many Even Numbers
//
// Read n, then an array of integers.
// Print how many elements are even.
#include <iostream>
using namespace std;

int main() {
    int n, arr[100], max = 0, min = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i == 0) {
            max = arr[i];
            min = arr[i];
        }
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

    return 0;
}