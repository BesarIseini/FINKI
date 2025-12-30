#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int maxIndex = -1, counter = 0;
    float maxRatio = 0.0;
    char text[100];
    while (cin.getline(text, 100)) {
        int uppercase = 0, lowercase = 0;
        float ratio;
        for (int i = 0 ; i < strlen(text); i++) {
            if (isupper(text[i])) uppercase++;
            if (islower(text[i])) lowercase++;
        }
        ratio = uppercase * 1.0 / lowercase;
        if (ratio > maxRatio) {
            maxRatio = ratio;
            maxIndex = counter;
        }
        cout << fixed << setprecision(2) << ratio << " " << text << endl;
        counter++;
    }
    cout << maxIndex << endl;
}