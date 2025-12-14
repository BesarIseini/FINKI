#include <iostream>
using namespace std;

bool isPrime(int n, int i = 3) {
    if (n <= 1) return false;
    if (n < 4) return true;
    if (n % 2 == 0) return false;
    if (i * i > n) return true;
    if (n % i == 0) return false;
    return isPrime(n, i + 2);
}

int firstLargerPrime(int n) {
    if (isPrime(n + 1)) return n + 1;
    return firstLargerPrime(n + 1);
}

int main() {
    int n, difference;
    cin >> n;
    difference = firstLargerPrime(n) - n;
    cout << firstLargerPrime(n) << " - " << n << " = " << difference << endl;
    return 0;
}