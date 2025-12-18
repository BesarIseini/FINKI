#include <iostream>
using namespace std;

int main() {
    int a[100], freq[10], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int maxFreq = 0;
    for (int i = 0; i < 10; i++) {
        if (maxFreq < freq[i]) {
            maxFreq = freq[i];
        }
    }
    int number1 = -1, number2 = -1;
    for (int i = 0; i < 10; i++) {
        if (freq[i] == maxFreq) {
            if (number1 == -1) number1 = i;
            else number2 = i;
        }
    }
    for (int i = 0; i < number1; i++) {
        for (int j = 0; j < number2; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}