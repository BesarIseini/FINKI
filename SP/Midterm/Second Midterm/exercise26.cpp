#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char text[101];
    cin.getline(text, 100);
    bool found = false;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isdigit(text[i])) {
            found = true;
            cout << text[i];
            i++;
            for (; i < strlen(text); i++) {
                cout << text[i];
                if (isdigit(text[i])) {break;}
            }
            break;
        }
    }
    if (!found) {
        cout << "No digits";
    }


    return 0;
}