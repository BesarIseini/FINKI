// Palindrome Check
// Recursively check whether a string is a palindrome (reads same forward/backward).

#include <iostream>
#include <math.h>
using namespace std;

int digitCounter(int n) {
    if (n < 0) return digitCounter(-n);
    if (n < 10) return 1;
    return 1 + digitCounter(n / 10);
}

bool isPalindrome(int n, int d) {
    if (n < 10) return true;
    int dS = n % 10;
    int dE = n / (int)pow(10, d - 1);
    if (dS != dE) return false;
    return isPalindrome((n / 10) % (int)pow(10, d - 2), d - 2);
}

int main() {
    int n;
    cin >> n;
    string reply = isPalindrome(n, digitCounter(n)) ? "Yes it is" : "No it isn't";
    cout << reply;
}
