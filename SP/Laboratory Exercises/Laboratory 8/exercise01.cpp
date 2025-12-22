#include <iostream>
using namespace std;

void sort(int &x, int &y, int &z) {
    if (y > x) {
        swap(y, z);
    }
    if (z > x) {
      swap(x, y);
    }
    if (z > y) {
        swap(z, y);
    }
}


int main() {
    int x, y, z;
    cin >> x >> y >> z;
    sort(x, y, z);
    cout << x << " " << y << " " << z << endl;
    return 0;
}