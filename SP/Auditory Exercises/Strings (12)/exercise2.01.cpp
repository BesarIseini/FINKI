#include <iostream>
using namespace std;

int count_char(char str[], char c) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) count ++;
    }
    return count;
}

int main() {
    int MAX = 100;
    char s[MAX], c;
    cin.getline(s, MAX);
    cin >> c;
    cout << count_char(s, c);

    return 0;
}