// Power Function
// Implement int power(int x, int y) recursively — don’t use loops or pow.

#include <iostream>
using namespace std;

long long power(int x, int y) {
    if (y == 0) return 1;
    return x * power(x, y - 1);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << power(x, y) << endl;
}
