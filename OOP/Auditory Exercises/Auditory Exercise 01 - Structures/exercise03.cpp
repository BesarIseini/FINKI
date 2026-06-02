#include <iostream>
using namespace std;

struct ComplexNumber {
    float real, imag;
    ComplexNumber add(ComplexNumber other) {
        return {real + other.real, imag + other.imag};
    }

    ComplexNumber subtract(ComplexNumber other) {
        return {real - other.real, imag - other.imag};
    }

    ComplexNumber multiply(ComplexNumber other) {
        return {
        real * other.real - imag * other.imag,
        real * other.imag + imag * other.real
        };
    }

    void print() {
        cout << real;
        if (imag >= 0) {
            cout << " + ";
        }
        cout << imag << "i" << endl;
    }
};

void read(ComplexNumber &cnnumber) {
    cin >> cnnumber.real >> cnnumber.imag;
}

int main() {
    ComplexNumber a, b, c;
    read(a);
    read(b);
    a.print();
    b.print();
    cout << "a + b" << endl;
    c = a.add(b);
    c.print();
    cout << "a - b" << endl;
    c = a.subtract(b);
    c.print();
    cout << "a * b" << endl;
    c = a.multiply(b);
    c.print();

    return 0;

}