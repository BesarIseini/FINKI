//
// Created by Besar on 14/11/2025.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << "%";
    for (int i = 1; i <= n - 2; i++) {
        cout << "@";
    }
    cout << "%" << endl;
    for (int i = 1; i <= n - 2; i++) {
        cout << "%";
        for (int j = 1; j <= n - 2; j++) {
            cout << ".";
        }
        cout << "%" << endl;
    }
    cout << "%";
    for (int i = 1; i <= n - 2; i++) {
        cout << "@";
    }
    cout << "%" << endl;
    return 0;
}