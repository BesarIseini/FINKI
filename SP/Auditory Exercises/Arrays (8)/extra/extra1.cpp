/*
 * 1. Sum of Elements at Even Indexes
   Read an integer n, then read an array of n integers.
   Print the sum of elements whose index is even (0,2,4,...).
*/

#include <iostream>
using namespace std;
int main() {
    int n, arr[100], sumEven = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i % 2 == 0) {
            sumEven += arr[i];
        }
    }
    cout << "Sum of elements whose index is even: " << sumEven << endl;

    return 0;
}