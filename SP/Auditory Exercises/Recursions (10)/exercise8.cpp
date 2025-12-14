#include <iostream>
using namespace std;

int LCM(int a, int b, int multiple) {
    if (multiple % a == 0 && multiple % b == 0) {
        return multiple;
    }
    return LCM(a, b, multiple + b);
}

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int lcm = LCM(arr[0], arr[1], arr[1]);
    for (int i = 0; i < n; i++) {
        lcm = LCM(lcm, arr[i], arr[i]);
    }
    cout << lcm << endl;

    return 0;
}