#include <iostream>
using namespace std;

string getPrefix(int number) {
    if (number % 100 >= 11 && number % 100 <= 13) {
        return "th";
    }
    switch (number % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
    }
    return "th";
}

void fillArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        string prefix = getPrefix(i + 1);
        cout << "The " << i + 1 << prefix << " element in the array is:";
        cin >> arr[i];
    }
}

int main() {
    int arr1length, arr2length;
    cout << "Enter the first array: ";
    cin >> arr1length;
    cout << "Enter the second array: ";
    cin >> arr2length;
    if (arr1length != arr2length) {
        cout << "The arrays are not the same!";
        return 0;
    }
    if (arr1length > 100 || arr2length > 100) {
        cout << "Maximum array length is 100!";
        return 0;
    }
    if (arr1length < 0 || arr2length < 0) {
        cout << "Array length cannot be less than zero!";
        return 0;
    }
    int arr1[100], arr2[100];
    cout << "Enter the elements of the first array. " << endl;
    fillArray(arr1, arr1length);
    cout << "Enter the elements of the second array. " << endl;
    fillArray(arr2, arr2length);
    for (int i = 0; i < arr1length; i++) {
        if (arr1[i] != arr2[i]) {
            cout << "The arrays are not the same!";
            return 0;
        }
    }
    cout << "The arrays are the same!";
    return 0;
}