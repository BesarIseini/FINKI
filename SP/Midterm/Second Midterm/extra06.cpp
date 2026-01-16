#include <iostream>

using namespace std;

void pyramid(int n, int m = 1, int counter = 0, bool reverse = false) {
    if (m > n) {
        return;
    }
    if (m == 1) {
        cout << 1;
        cout << endl;
        pyramid(n, m + 1);
        return;
    }
    if (counter == 0 && reverse) {
        cout << endl;
        pyramid(n, m + 1);
        return;
    }
    if (counter == m - 1 && !reverse) {
        cout << m;
        pyramid(n, m, counter, true);

        return;
    }

    if (!reverse) {
        cout << 1;
        pyramid(n, m, counter + 1);
    }
    if (reverse) {
        cout << 1;
        pyramid(n, m, counter - 1, true);
    }
}

int main () {
    int n;
    cin >> n;
    pyramid(n);
    return 0;
}