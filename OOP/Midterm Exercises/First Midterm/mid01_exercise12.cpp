#include <iostream>
#include <cstring>

using namespace std;

class Transaction {
    int day, month, year;
    int amount;
    char currency[4];
public:
    Transaction() {
        day = 0;
        month = 0;
        year = 0;
        amount = 0;
        currency[0] = '\0';
    }
    Transaction(int day, int month, int year, int amount, char currency[3]) {
        this->day = day;
        this->month = month;
        this->year = year;
        this->amount = amount;
        strcpy(this->currency, currency);
    }

    bool condition(int amount, char currency[3]) {
        if (strcmp(currency, this->currency) == 0 && this-> amount < amount && month <= 3) return true;
        return false;
    }

    int getDay() {
        return this->day;
    }
    int getMonth() {
        return this->month;
    }
    int getYear() {
        return this->year;
    }
    int getAmount() {
        return this->amount;
    }
    char * getCurrency() {
        return this->currency;
    }
};


int main() {
    int n;
    cin >> n;
    Transaction transactions[500];
    for (int i = 0; i < n; i++) {
        char slash;
        int day, month, year, amount;
        char currency[4];
        cin >> currency >> amount >> day >> slash >> month >> slash >> year;
        transactions[i] = Transaction(day, month, year, amount, currency);
    }

    int total = 0;
        char currentCurrency[4] = {"USD"};
    for (int i = 0, j = 1; i < n; i++) {
        if (transactions[i].condition(5000, currentCurrency)) {
            total += transactions[i].getAmount();
            cout << j++ << ". ";
            if (transactions[i].getDay() < 10) {
                cout << 0;
            }
                cout << transactions[i].getDay() << "/";
            if (transactions[i].getMonth() < 10) {
                cout << 0;
            }
            cout << transactions[i].getMonth() << "/" << transactions[i].getYear() << " " << transactions[i].getAmount() << " " << transactions[i].getCurrency() << endl;


        }
    }
    cout << "Total: " << total << " " << currentCurrency << endl;

    return 0;
}