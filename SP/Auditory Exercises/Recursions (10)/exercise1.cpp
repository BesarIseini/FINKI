//
// Created by Besar on 06/12/2025.
//

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int sum(int k) {
    if (k == 0) {
        return 0;
    }
    return k + sum(k - 1);
}

int main() {
    int n, result = 0;
    cin >> n;
    if (n <= 0) {
        cout << "WRONG INPUT";
    }
    for (int i = 1; i < n; i++) {
        int s = sum(i);
        result += factorial(s);
        cout << s << "! + ";
    }
    int s = sum(n);
    result += factorial(s);
    cout << s << "! = " << result << endl;
}