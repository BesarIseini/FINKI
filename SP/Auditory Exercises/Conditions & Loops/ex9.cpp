//
// Created by Besar on 12/10/2025.
// 8.9. Exercise 9
// Write a program that reads the price of a product
// from the keyboard and then prints its price with
// added value-added tax (VAT).
// Hint: VAT is 18% of the initial price.
//


#include <iostream>
using namespace std;

int main() {

    float price;
    cout << "Enter price: ";
    cin >> price;
    cout << "Your price is: " << price * 1.18 << endl;

    return 0;
}