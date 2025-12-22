#include <iostream>
using namespace std;

void statistics(int arr[], int n, int &min, int &max, int &sum) {
    min = arr[0];
    max = arr[0];
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }
    int difference = max - min;
    for (int i = 0; i < n; i++) {
        arr[i] += difference;
    }
}

int main() {
    int arr[100], n, min, max, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    statistics(arr, n, min, max, sum);
    cout << "MAX -> " << max << endl;
    cout << "MIN -> " << min << endl;
    cout << "SUM -> " << sum << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}