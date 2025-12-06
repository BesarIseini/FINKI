//
// Created by Besar on 12/10/2025.
// Exercise 6
// Write a program to calculate and print the area
// and perimeter of a circle. The radius of the circle should
// be read from the standard input (keyboard) as a decimal number.
//

#include <iostream>
using namespace std;

int main() {
    float radius;
    cin >> radius;

    float perimeter = 2 * 3.14 * radius;
    float area = 3.14 * radius * radius;

    cout << "Perimeter = " << perimeter << endl;
    cout << "Area = " << area << endl;

    return 0;
}