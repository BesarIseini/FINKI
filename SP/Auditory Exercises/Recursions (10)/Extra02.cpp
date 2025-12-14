// Print Even Numbers from 0 to n
// Recursively print all even numbers ≤ n (assume n ≥ 0).

#include <iostream>
using namespace std;

void printEven(int to, int start = 0, bool upwards = true) {
    if (to < start) return;
    if (upwards) cout << start << endl;
    printEven(to, start + 1, upwards);
    if (!upwards) cout << start << endl;
}

int main() {
    int n;
    cin >> n;
    printEven(n, 3, false);

}