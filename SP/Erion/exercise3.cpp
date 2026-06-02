//
// Created by besar on 1/23/26.
//
#include <iostream>
using namespace std;

int beginEnd(int arr[], int start = 0, int end = 0, int counter = 0) {
    if (start >= end) {
        return counter;
    }
    if (arr[start] == arr[end]) {
        return beginEnd(arr, start + 1, end - 1, counter);
    }
    arr[start] = max(arr[start], arr[end]);
    arr[end] = max(arr[start], arr[end]);
    return beginEnd(arr, start + 1, end - 1, counter + 1);
}

int beginEndIterative(int arr[], int n) {
    int counter = 0;
    for (int i = 0; i < n / 2; i++) {
        int lastElement = arr[n - i - 1];
        if (lastElement == arr[i]) {
            continue;
        }
        arr[i] = arr[n - i - 1] = max(arr[i], arr[n - i - 1]);
        counter++;
    }
    return counter;
}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << beginEndIterative(arr, n) << endl;
    // cout << beginEnd(arr, 0, n - 1) << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}