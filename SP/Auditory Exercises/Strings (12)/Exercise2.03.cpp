#include <iostream>
using namespace std;

int main() {
    int MAX = 100, subPos, subLength;
    char s[MAX];
    cin.getline(s, MAX);
    cin >> subPos >> subLength;
    for (int i = subPos; i < subLength + subPos; i++) {
        if (s[i] == '\0') break;
        cout << s[i];
    }

    return 0;
}