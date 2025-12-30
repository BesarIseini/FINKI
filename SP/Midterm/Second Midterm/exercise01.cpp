#include <iostream>
using namespace std;

void transformString(char *text, int shift) {
    if (*text == '\0') {
        return;
    }
    if (!isalpha(*text)) {
        transformString((text + 1), shift);
        return;
    }
    int newLetter = *text + shift;
    bool upperCase = *text <= 'Z';
    if ((newLetter > 'Z' && newLetter < 'a') || (newLetter > 'z')) {
        newLetter -= 26;
    }
    if (upperCase && newLetter > 'Z') {
        newLetter -= 26;
    }
    *text = newLetter;

    transformString((text + 1), shift);
}

int main() {
    int n, x;
    char text[81];
    cin >> n >> x;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin.getline(text, 81);
        transformString(text, x);
        cout << text << endl;
    }
}
