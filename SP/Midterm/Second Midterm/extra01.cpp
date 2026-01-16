#include <iostream>
using namespace std;

void printingPyramid(int n, int start = 1, bool middle = false) {
    if (n < 1) {
        return;
    }
    if (n == 1) {
        cout << n;
        return;
    }
    if (middle && start > 1) {
        cout << start;
        printingPyramid(n, start - 1, middle);
    }
    if (middle && start == 1) {
        cout << start << endl;
        printingPyramid(n - 1);
        return;
    }
    if (start == n) {
        cout << n;
        middle = true;
        printingPyramid(n, start - 1, middle);
        return;
    }
    if (!middle) {
        cout << start;
        printingPyramid(n, start + 1);

    }


}

int main() {
    int n;
    cin >> n;
    printingPyramid(n);

    return 0;
}