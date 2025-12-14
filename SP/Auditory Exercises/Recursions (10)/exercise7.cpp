#include <iostream>
using namespace std;

int GCD(int n, int m) {
    if (!m) {
        return n;
    }
    return GCD(m, n % m);
}

int main() {
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int gcd = GCD(a[0], a[1]);
    for (int i = 0; i < n; i++) {
        gcd = GCD(gcd, a[i]);
    }
    cout << gcd << endl;

    return 0;
}