//
// Created by besar on 11/28/25.
//
#include <iostream>
using namespace std;
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    int a[100], n, element;
    bool increasing = true, decreasing = true;
    cin >> n;
    fillArray(a, n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            increasing = false;
            break;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= a[i + 1]) {
            decreasing = false;
            break;
        }
    }

    if (!decreasing && !increasing) {
        cout <<"NOOO";
    } else if (decreasing) {
        cout << "Decreasing" << endl;
    } else if (increasing) {
        cout << "Increasing" << endl;
    }
    return 0;
}