#include <iostream>
using namespace std;

int main () {
    int n, counter = 0;
    char letters[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    bool reverse = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (!reverse) {
            for (int j = 0; j < n; j++) {
                cout << letters[counter % 9] << " ";
                counter++;
            }
            reverse = true;
        }
        else {
            counter = counter + n - 1;
            for (int j = n; j > 0; j--) {
                cout << letters[counter % 9] << " ";
                counter--;
            }
            counter = counter + n + 1;
            reverse = false;
        }
        cout << endl;
    }
}