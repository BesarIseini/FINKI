#include <complex>
#include <iostream>
#include <math.h>
using namespace std;





int mask(int number, int k, int counter) {
    if (counter == 0) return 0;

    int lD = number / (int)pow(10, counter - 1);
    int rest = number % (int)pow(10, counter - 1);

    if (lD <= k) {
        return 0 * pow(10, counter - 1) + mask(rest, k, counter - 1);
    }
    return 1 * pow(10, counter - 1) + mask(rest, k, counter - 1);
}

int main() {
    int n, k,counter = 0;
    cin >> n >> k;
    int b = n;
    while (b != 0) {
        counter++;
        b /= 10;

    }
    cout << mask(n, k,counter) << endl;

    return 0;
}