#include <iostream>
using namespace std;

void changeArray(int arr[], int n, int ne, int counter = 0) {
    if (n >= ne) {
        cout << counter << endl;
        return;
    }
    if (arr[n] == arr[ne]) {
        counter--;
    }
    arr[n] = arr[ne] = max(arr[n], arr[ne]);
    changeArray(arr, n + 1, ne - 1, counter + 1);
}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    changeArray(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}