#include <iostream>
#include <cstring>
using namespace std;
int main () {
    char word[21], uniqueWord[21];
    int mostLetters = 0;
    while (cin >> word) {
        bool usedLetters[26] = {false};
        int counter = 0;
        if (strlen(word) < 4) continue;
        for (int i = 0; i < strlen(word); i++) {
            int index = tolower(word[i]) - 'a';
            usedLetters[index] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (usedLetters[i]) {
                counter++;
            }
        }
        if (counter >= mostLetters) {
            mostLetters = counter;
            strcpy(uniqueWord, word);
        }
    }
    cout << uniqueWord << endl;



    return 0;
}