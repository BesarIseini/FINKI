#include <iostream>
#include <cstring>
using namespace std;

int wordCounter(char text[]) {
    bool word = true;
    int conjugates = 0;
    int letters = 0;
    char currentLetter = text[0];
    for (int i = 0; i <= strlen(text); i++) {
        currentLetter = text[i];
        if (!word && isalpha(text[i])) {
            word = true;
            letters = 0;
        }
        if (!isalpha(text[i - 1]) && !isalpha(text[i])) continue;
        if (!isalpha(text[i])) {
            word = false;
            if (letters <= 3 && letters > 0) conjugates++;
        }
        if (isalpha(text[i])) {
            letters++;
        }
    }

    return conjugates;
}

int main() {
    char text[101];
    char longest[101];
    int mostConjugate = -1;
    int conjugates;

    while (cin.getline(text,100)) {
        conjugates = wordCounter(text);
        if (conjugates > mostConjugate) {
            mostConjugate = conjugates;
            strcpy (longest,text);
        }
    }
        cout << mostConjugate << ": " << longest << endl;

    return 0;
}