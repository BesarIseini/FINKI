//
// Created by Besar on 12/10/2025.
// 8.8. Exercise 8
// Write a program that reads an uppercase letter from the
// standard input and prints the same letter as lowercase.
// Note: Each character is represented by an ASCII number.
//
#include <iostream>
using namespace std;

int main() {
    char uppercase_letter;
    cin >> uppercase_letter;
    char lowercase_letter = uppercase_letter - ('a' + 'A');
    cout << lowercase_letter;

    return 0;
}