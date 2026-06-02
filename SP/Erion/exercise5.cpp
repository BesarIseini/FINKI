#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char word[31];
    while (cin >> word) {
        int length = strlen(word);
        bool found = true;
        for (int i = 0; i < length / 2; i++) {
            char c = tolower(word[i]);
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                continue;
            }
            if (c != tolower(word[length - i - 1])) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << word << endl;
        }
    }
}