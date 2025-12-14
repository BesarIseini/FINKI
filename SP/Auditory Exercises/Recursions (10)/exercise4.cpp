#include <iostream>
using namespace std;

int xnn(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return (n - 1) * xnn(n - 1) / n + xnn(n - 2) / n;
}

int main() {
    int n;
    cin >> n;
    cout << xnn(n) << endl;

    return 0;
}