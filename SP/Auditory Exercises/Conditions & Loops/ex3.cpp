//
// Created by Besar on 12/10/2025.
// Write a program that, for given sides of an
// equilateral triangle, prints its perimeter and
// the square of its area
// (let’s use a = 5, b = 7.5, c = 10.2).
//

#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float a = 5, b = 7.5, c = 10.2;
    float perimeter = a + b + c;
    float s = perimeter / 2;
    float area = s * (s - a) * (s - b) * (s - c);
    cout << "The perimeter is: " << perimeter << endl;
    cout << "The area is: " << area << endl;


    return 0;
}