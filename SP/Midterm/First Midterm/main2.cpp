#include <algorithm>
#include <iostream>
using namespace std;

//Sweet number is number that contains only even digits (0, 2, 4, 6, 8).
//In given range (m and n read from SI) find the smallest "sweet number".
//If there is no such number, print NSN.



int main() {
    /*float points, maxPoints;
    int pairs;
    cin >> pairs;
    for (int i = 0; i < pairs; i++) {
        cin >> points >> maxPoints;
        float percentage = points / maxPoints * 100;

        if (percentage >= 90) {
            cout << percentage << " 10" << endl;
        } else if (percentage >= 80) {
            cout << percentage << " 9" << endl;
        } else if (percentage >= 70) {
            cout << percentage << " 8" << endl;
        } else if (percentage >= 60) {
            cout << percentage << " 7" << endl;
        } else if (percentage >= 50) {
            cout << percentage << " 6" << endl;
        } else if (percentage < 50 && percentage > 0) {
            cout << percentage << " FAIL" << endl;
        }
    }*/

    int m, n;
    cin >> m >> n;
    int counter = n + 1;

    for (int i = m; i <= n; i++) {
        int d0 = i % 10;
        int d1 = i / 10 % 10;
        int d2 = i / 100 % 10;
        int d3 = i / 1000 % 10;

        if (d0 % 2 == 0 && d1 % 2 == 0 && d2 % 2 == 0 && d3 % 2 == 0) {
            cout << i << " ";
            break;
        }
        counter--;
    }
    cout << counter << endl;
    if (counter==m) {
        cout << "NSN" << endl;
    }

    return 0;
}
