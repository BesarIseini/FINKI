//
// Created by Besar on 14/11/2025.
//

#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    char n;
    while (cin >> n) {
        if (n == '.') break;
        if (n >= '0' && n <= '9') {
            sum += n - '0';
        }
        else if (n >= 'a' && n <= 'f') {
            sum += n - 'a' + 10;
        }
        else if (n >= 'A' && n <= 'F') {
            sum += n - 'A' + 10;
        }
    }
    if (sum % 16 == 0) {
        if (sum % 100 == 16) {
            cout << "Poln pogodok"<<endl;
        } else {
            cout <<"Pogodok" << endl;
        }
    } else {
        cout << sum << endl;
    }


}