#include <iostream>
using namespace std;

int lengthI(char string[]) {
    int c = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        c++;
    }
    return c;
}

int lengthR(char string[], int i = 0) {
    if (string[i] == '\0') return 0;
    return 1 + lengthR(string, i + 1);
}

int lengthPR(char * string) {
    if (* string == '\0') return 0;
    return 1 + lengthPR(string + 1);
}

int main() {
    int max = 100;
    char s[max];
    cin.getline(s, max);

    cout << lengthI(s) << endl;
    cout << lengthR(s) << endl;
    cout << lengthPR(s) << endl;

    return 0;
}