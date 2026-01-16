
#include <iostream>
using namespace std;

int main() {
    int n, counter = 1;
    bool start = true;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (start) {
            for (int j = 1; j <= n; j++) {
                cout << counter % 10 << " ";
                counter++;
            }
            start = false;
        } else {
            counter += n - 1;
            for (int j = n; j >= 1; j--) {
                cout << counter % 10 << " ";
                counter--;
            }
            counter += n + 1;
            start = true;
        }
        cout << endl;
    }

    return 0;
}