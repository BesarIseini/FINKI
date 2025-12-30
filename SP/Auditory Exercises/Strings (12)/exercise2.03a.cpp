#include <iostream>
#include <cstring>
using namespace std;

int main () {
    int MAX = 100;
    char s[MAX], subS[MAX];
    int position, length;
    cin.getline(s, MAX);
    cin >> position >> length;

    if (position <= strlen(s)) {
        strncpy(subS, s + position, length);
        subS[length] = '\0';
        cout << subS << endl;
    }
    else {
        cout << "Invalid input";
    }

    return 0;
}