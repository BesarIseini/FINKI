#include <cstring>
#include <iostream>
#include <istream>
using namespace std;

bool isPalindrome (char word[]) {
    bool palindrome = true;
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - 1 - i]) {
            palindrome = false;
        }
    }
    return palindrome;
}

int main () {
    int n;
    char word[81];
    char shortest[81] = {"NEMA"};
    bool firstRun = true;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> word;
        bool palindrome = isPalindrome(word);
        if (firstRun && !palindrome) {
            strcpy (shortest, word);
            firstRun = false;
        }
        if (!firstRun && !palindrome && strlen(word) < strlen(shortest)) {
            strcpy (shortest, word);
        } else if (!firstRun && !palindrome && strlen(word) == strlen(shortest)) {
            if (strcmp(shortest, word) < 0) {
                strcpy (shortest, word);
            }
        }
    }
        cout << shortest;
    return 0;
}
