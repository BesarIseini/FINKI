//
// Created by Besar on 12/10/2025. 8.10.
// Exercise 10
// Write a program that reads the price of a product,
// the number of installments, and the interest rate
// (the interest rate is a number expressed as a percentage from 0 to 100).
// The program should print the installment amount and the
// total amount to be paid for the product.

// Hint: Calculate the total amount
// and then the installment.
//

#include <iostream>
using namespace std;

int main() {
    float price, installment,interestRate, total;
    int installments;
    cout << "Enter the price of the product: ";
    cin >> price;
    cout << "Enter number of installments: ";
    cin >> installments;
    cout << "Enter interest rate: ";
    cin >> interestRate;
    total = price * (1 + interestRate / 100);
    installment = total / installments;

    cout << "One installment will be: " << installment << endl;
    cout << "Total price will be: " << total << endl;

    return 0;
}