/*
// Created by Besar on 12/10/2025.
    Exercise 11
    Write a program that reads a three-digit integer from the keyboard.
    The program should print the most significant and least significant
    digits of the number.
    Example: If you enter the number 795, the program will print:
    The most significant digit is 7, and the least significant is 5.

    Hint: Use integer division and the modulo operator.
*/

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    cout << "The most significant digit is " << number / 100;
    cout << ", and the least significant digit is " << number % 10;

    return 0;
}