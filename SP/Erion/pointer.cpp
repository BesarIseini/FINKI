//
// Created by besar on 1/20/26.
//

#include <iostream>

using namespace std;

void swapNOpointer (int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void swapPointer (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRefernece (int &z, int &u) {
    int temp = z;
    z = u;
    u = temp;
}


int main() {
    int x, y;
    cin >> x >> y;
    // swapNOpointer (x, y);
    // swapPointer(&x, &y);
    swapRefernece(x, y);
    cout << x << " " << y;
    // cout << endl << &x;

    return 0;
}