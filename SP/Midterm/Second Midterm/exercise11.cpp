#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main () {
    char text[31];
    while (cin >> text) {
        bool palindrome = true;
        for (int i = 0; i < strlen(text) / 2; i++) {
            char vowel = tolower(text[i]);
            if (vowel == 'a' || vowel == 'i' || vowel == 'e' || vowel == 'o' || vowel == 'u' || vowel == 'y') {
                if (vowel != tolower(text[strlen(text) - 1 - i])) {
                    palindrome = false;
                    break;
                }
            }
        }
        if (palindrome) {
            cout << text << endl;
        }
    }

    return 0;
}