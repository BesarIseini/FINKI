//
// Created by Besar on 14/11/2025.
//

#include <iostream>

using namespace std;

int main() {
    int alpha, beta, gamma;
    cin >> alpha >> beta >> gamma;
    if (alpha + beta + gamma != 180 ||
        !(alpha > 0 && beta > 0 && gamma > 0)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (alpha == 90 || beta == 90 || gamma == 90) {
        cout << "RIGHT" << endl;
    }
    else if (alpha > 90 || beta > 90 || gamma > 90) {
        cout << "OBTUSE" << endl;
    }
    else if (alpha < 90 && beta < 90 && gamma < 90) {
        cout << "ACUTE" << endl;
    }



    return 0;
}