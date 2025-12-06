#include <iostream>
#include<cmath>

using namespace std;

int findDigits(int number) {
    int digits = 0;
    while (number) {
        digits++;
        number /= 10;
    }
    return digits;
}

int findReverse(int number) {
    int reverse = 0;
    while (number) {
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }
    return reverse;
}

int sumOfMiddleDigits(int number, int digits) {
    int middleDigits = number % (int)pow(10, (digits - 1)) / 10;
    return middleDigits;
}



int main() {
    int x, y, counter = 0;
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        int digits = findDigits(i);
        int reverse = findReverse(i);
        int middleDigits = sumOfMiddleDigits(reverse, digits);
        int firstNumber =  i % 10;
        int lastNumber = (int)(i / pow(10, (digits - 1))) % 10;
        int sumOfFirstLastNumber = firstNumber + lastNumber;
        if (middleDigits == 0 || middleDigits % sumOfFirstLastNumber != 0) {
            continue;
        }

        cout << i << " -> (" << middleDigits << " == (" << firstNumber << " + " <<
            lastNumber << ") * " << middleDigits / sumOfFirstLastNumber << ")" << endl;

        counter++;
    }
    cout << counter << endl;
}