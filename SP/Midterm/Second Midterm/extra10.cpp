#include <iostream>
using namespace std;

int par(int a[], int n) {
    int maxnr = 0;
    bool first = true;
    for (int i = 0; i < n; i++) {
        int nr = a[i], encountered = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == nr) {
                encountered += 1;
            }
        }
        if (((encountered % 2 == 0 && nr < maxnr && encountered != 0)) || (first && encountered % 2 == 0)) {
            maxnr = nr;
            first = false;
        }
    }
    return maxnr;
}

int main () {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int nr = par(a, n);
    if (nr) {
        cout << "Najmaliot element koj se pojavuva paren broj pati e " << nr << endl;
    } else {
        cout << "Nitu eden element ne se pojavuva paren broj pati!" << endl;
    }

}