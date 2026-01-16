#include <cstring>
#include <iostream>
using namespace std;

bool isPalindrome(char word[]) {
    int length = strlen(word);
    bool isPalindrome = true;
    for (int i = 0; i < length / 2; i++) {
        if (tolower(word[i]) != tolower(word[length - 1 - i])) {
            isPalindrome = false;
        }
    }
    return isPalindrome;
}

int main() {
    int n;
    char word[81];
    char longest[81] = "NEMA";
    bool first = true;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        bool palindrome = isPalindrome(word);
        if (palindrome && first) {
            first = false;
            strcpy (longest, word);
        }
        if (!first && palindrome && strlen(word) > strlen(longest)) {
            strcpy (longest, word);
        }
        if (!first && palindrome && strlen(word) == strlen(longest)) {
            if (strcmp(longest, word) > 0) {
                strcpy (longest, word);
            }
        }

    }
    cout << longest << endl;

}