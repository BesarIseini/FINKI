#include <iostream>
using namespace std;

int main() {
    int a[100], n, nr1, nr1a, nr2, nr2a;
    bool firstRun = true;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        int tmpCt = 0;
        for (int j = 0; j < n; j++) {
            if (temp == a[j]) {
                tmpCt++;
            }

        }
        if (firstRun) {
            nr1 = temp;
            nr1a = tmpCt;
            firstRun = false;
        }

        if (tmpCt >= nr1a && temp == nr1) {
            nr2 = nr1;
            nr2a = nr1a;
            nr1a = tmpCt;
            nr1 = temp;
        } else if (tmpCt >= nr1a) {
            nr2 = nr1;
            nr2a = nr1a;
            nr1a = tmpCt;
            nr1 = temp;
        }
    }
    if (nr2 > nr1) {
        int temp = nr1;
        nr1 = nr2;
        nr2 = temp;
    }

    for (int i = 0; i < nr2; i++) {
        for (int j = 0; j < nr1; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}