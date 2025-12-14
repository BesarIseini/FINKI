#include <iostream>
using namespace std;

int count8 (int n) {
    if (n == 0) return 0;
    if (n % 10 == 8) {
        if (n % 100 == 88) {
            return 2 + count8(n / 10);
        }
        return 1 + count8(n / 10);
    }
    return count8(n / 10);
}

int main() {
    int n;
    cin >> n;
    cout << count8(n) << endl;


    return 0;
}