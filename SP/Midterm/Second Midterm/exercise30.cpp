#include <cstring>
#include <iostream>
using namespace std;

// void shiftLine(char line[], int index) {
//     for (int i = index; i < strlen(line); i++) {
//         line[i] = line[i + 1];
//         if (line[i] == '\0') {
//             line[i] = ' ';
//             line[i + 1] = '\0';
//             break;
//         }
//     }
//
// }

void stripSpace (char line[]) {
    int removedSpaces = 0;
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == ' ' && line[i + 1] == ' ') {
            removedSpaces++;
            for (int j = i; j < strlen(line); j++) {
                line[j] = line[j + 1];
            }
            i--;
        }
    }
    line[strlen(line) - removedSpaces] = '\0';
}

int main () {
    char line[81];

    while (cin.getline(line, 80)) {

        for (int i = 0; i < strlen(line); i++) {
            if (isspace(line[i])) {continue; }
            if (!isalpha(line[i])) {
                line[i] = ' ';
            }
        }
        stripSpace(line);
        for (int i = 0; i < strlen(line); i++) {
            if (isspace(line[i]) || line[i] == '\n') {
                cout<<endl;
                continue;
            }
            cout << line[i];
        }
    }


    return 0;
}