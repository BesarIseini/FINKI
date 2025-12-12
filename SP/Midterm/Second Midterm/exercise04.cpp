#include <iostream>
using namespace std;

void print(int n) {
    if (n == 0) return;
    print(n-1);
    cout << n;
}

void triangle(int n) {
    if (n == 0) return;
    triangle(n-1);
    print(n);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    triangle(n);
    return 0;
}