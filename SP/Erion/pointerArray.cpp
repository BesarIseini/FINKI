//
// Created by besar on 1/20/26.
//

#include <iostream>
using namespace std;

void findMinMax (int a[], int n, int &min, int &max) {
    min = a[0];
    max = a[n - 1];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
        if (max < a[i]) {
            max = a[i]; // *(a + i)
        }
    }
}

void findMinMaxAllPointer (int a[], int n, int &min, int &max) {
    min = *a;
    max = *(a + n - 1);
    for (int i = 0; i < n; i++) {
        if (min > *(a + i)) {
            min = *(a + i);
        }
        if (max < *(a + i)) {
            max = *(a + i);
        }
    }
}


int main () {
    int a[100], n;
    int min, max;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    findMinMax(a, n, min, max);
    cout << min << " " << max << endl;


}