#include <iostream>
#include <cctype>
using namespace std;

//ignore upper or lower case characters
//with CCtype library and tolower

int count_char(char str[], char c) {
    int count = 0;
    c = tolower(c);
    for (int i = 0; str[i] != '\0'; i++) {
        if (tolower(str[i]) == c) count++;
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