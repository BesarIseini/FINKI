//
// Created by besar on 11/30/25.
//

#include <iostream>
using namespace std;

void displayElements(int arr[], int elements) {
    for (int i = 0; i < elements; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main() {

    int a[100], n, k, temp[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    displayElements(a, n);
    cin >> k;
    for (int i = 0 + k, j = n - k; i < n; i++, j++) {
        temp[j] = a[i];
    }
    for (int i = n - 1; i > k - 1; i--) {
        a[i] = a[i - k];
    }
    for (int i = 0; i < k; i++) {
        a[i] = temp[i];
    }
    displayElements(a, n);


    return 0;
}