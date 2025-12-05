// 2. Count Positive, Negative, Zero
// Read n, then an array of n integers.
// Print three values:
// the number of positive elements,
// negative elements,
// and zeros.

#include <iostream>
using namespace std;

int main() {
    int n, arr[100], pos = 0, neg = 0, zero = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 0) pos++;
        else if (arr[i] < 0) neg++;
        else if (arr[i] == 0) zero++;
    }
    cout << "Number of positive elements: " << pos << endl;
    cout << "Number of negative elements: " << neg << endl;
    cout << "Number of zero elements: " << zero << endl;

    return 0;
}