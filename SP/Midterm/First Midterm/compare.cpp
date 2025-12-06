//
// Created by Besar on 14/11/2025.
//

#include <iostream>

using namespace std;



int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a > c) {
            int tmp = a;
            a = c;
            c = tmp;
        }
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        if (b > c) {
            int tmp = b;
            b = c;
            c = tmp;
        }

        int ab = b - a, bc = c - b, ac = c - a;
        if (ab < bc && bc < ac || a == b && b != c) {
            cout << a << " " << b << endl;
        }
        else if (bc < ab && ab < ac || b == c && c != a) {
            cout << b << " " << c << endl;
        }
        else if (ac < ab && ab < bc || a == c && c != b) {
            cout << a << " " << c << endl;
        }
        else if (ab == bc) {
            cout << a << " " << b << " " << c << endl;
        }


    }

    return 0;
}
