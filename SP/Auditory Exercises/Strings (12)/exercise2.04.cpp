#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int MAX = 100;
    char s1[MAX], s2[MAX];
    cin.getline(s1, MAX);
    cin.getline(s2, MAX);
    if (strstr(s2, s1)) {
        cout << "Is a substring." << endl;
    } else {
        cout << "Is not a substring." << endl;
    }

    return 0;
}