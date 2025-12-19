#include <algorithm>
#include <iostream>
using namespace std;

int parcom(int a) {
    if (a < 10) {
        if (a % 2 == 0) return (a + 1) % 10;
        return (a - 1) % 10;
    }
    if (a % 2 == 0) return parcom(a / 10) * 10 + (a % 10 + 1) % 10;
    return parcom(a / 10) * 10 + (a % 10 - 1) % 10;
}
int main() {
    int counter = 0, arr[100], complementary[100];
    while (cin >> arr[counter]) {
        complementary[counter] = parcom(arr[counter]);
        counter++;
    }
    sort(complementary, complementary + counter);
    for (int i = 0; i < 5 && i < counter; i++) {
        cout << complementary[i] << " ";
    }

}