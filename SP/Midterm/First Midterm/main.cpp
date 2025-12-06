#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a <= 0 || b <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (a > 0 && b > 0) {
        int evenDigitFromA = a / 10 % 10;
        int digitFromB = b % 10;
        if (evenDigitFromA != digitFromB) {
            cout << "NE" << endl;
            return 0;
        }
        a /= 100;
        b /= 10;
    }
    if (a > 9) {
        cout << "NE" << endl;
        return 0;
    }

    cout << "PAREN" << endl;
    return 0;
}