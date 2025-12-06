#include <iostream>
using namespace std;

// d<e or d>e

int main() {
    int number;
    while (cin >> number) {
        if (number < 10) continue;
        int pattern = true;
        int valid = true;
        if (number % 10 < 5) pattern = false;
        int temp = number;
        while (temp > 0) {
            if ((pattern && (temp % 10 < 5)) || (!pattern && (temp % 10 >= 5))) {
                valid = false;
                break;
            }
            pattern = !pattern;
            temp = temp / 10;
        }
        if (valid)
            cout << number << endl;
    }

    return 0;
}