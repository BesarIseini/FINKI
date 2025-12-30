#include <iostream>
#include <cctype>
using namespace std;


int main () {

    char text[81];
    while (cin.getline(text, 80)) {
        int sum = 0;
        for (int i = 0; text[i] != '\0'; i++) {
            if (isdigit(text[i])) {
                int number = text[i] - '0';
                i++;
                for ( ; isdigit(text[i]); i++) {
                    number = number * 10 + text[i] - '0';
                }
                i--;
                sum += number;
            } else if (isalpha(text[i])) {
                cout << text[i];
            }
        }
        cout << sum << endl;
    }


    return 0;
}