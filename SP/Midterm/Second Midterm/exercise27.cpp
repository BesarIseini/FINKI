#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] == 0) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void transform(int arr[], int n, int &currentIndex) {
    int currentDigit = arr[currentIndex];
    int multiplier = 1;
    for (int i = currentIndex + 1; i < n; i++) {
        if (arr[i] != currentDigit) break;
        multiplier++;
        break;
    }
    arr[currentIndex] = currentDigit * multiplier;
    for (int i = 1; i <= multiplier - 1; i++) {
        arr[i + currentIndex] = 0;
    }
    currentIndex += multiplier - 1;
}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        transform(arr, n, i);
    }
    sortArray(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}