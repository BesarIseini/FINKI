#include <cstring>
#include <iostream>
#include <cctype>

using namespace std;



int main() {
    char line[81];
    while (cin.getline(line,80)) {
        if (strlen(line) == 0) {
            continue;
        }
        char temp[81];
        int j = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (isspace(line[i]) || isalpha(line[i])) {
                if (j == 0 && isspace(line[i])) {
                    continue;
                }
                if (isspace(line[i]) && isspace(temp[j - 1])) {
                    continue;
                }
                temp[j] = line[i];
                j++;
            }
        }
        temp[j] = '\0';
        strcpy(line,temp);
        for (int i = 0; i <= strlen(line); i++) {
            if ((line[i] == ' ' && i != strlen(line) - 1) || line[i] == '\0') {
                cout << endl;
                continue;
            }
            cout << line[i];
        }

    }


    return 0;
}