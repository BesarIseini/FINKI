// Fibonacci sequence (start)

#include <iostream>
using namespace std;

void fibonacci(int numbers = 10, int a = 0, int b = 1) {
    if (numbers == 0) return;
    cout << a << " ";
    fibonacci(numbers - 1, b, a + b);
}

int fibSum(int numbers = 10, int a = 0, int b = 1) {
    if (numbers == 0) return 0;
    return a + fibSum(numbers - 1, b, a + b);
}

int fib(int nTh, int a = 0, int b = 1) {
    if (nTh == 0) return a;
    return fib(nTh - 1, b, a + b);
}

int main() {
    fibonacci();
    cout << endl << fibSum();
    cout << endl << fib(10);
    return 0;
}

