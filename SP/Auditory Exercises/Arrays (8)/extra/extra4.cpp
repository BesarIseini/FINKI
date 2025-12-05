// 5. How Many Even Numbers
//
// Read n, then an array of integers.
// Print how many elements are even.

#include <iostream>
using namespace std;

int main() {
    int n, arr[100], even = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            even++;
        }
    }
    cout << "Even elements: " << even << endl;

    return 0;
}