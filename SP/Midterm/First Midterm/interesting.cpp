#include <iostream>

using namespace std;

bool is_interesting(int n) {
    int reverse = 0, temp = n, counter = 0;
    while (temp > 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
        ++counter;
    }
    return reverse % counter == 0;

}


int main() {
    int n;
    cin >> n;
    if (n <= 9) {
        cout << "The number is invalid";
        return 0;
    }
    for (int i = n - 1; ; i--) {
        if (is_interesting(i)) {
            cout << i << endl;
            break;
        }
    }



    return 0;
}