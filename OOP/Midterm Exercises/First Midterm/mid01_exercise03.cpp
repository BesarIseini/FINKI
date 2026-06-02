#include <iostream>
#include <cstring>
using namespace std;

class Bill {
    char * billNumber;
    int expense;
    char date[8];
    bool status;

public:
    Bill() {
        this->billNumber = new char[1];
        billNumber[0] = '\0';
        expense = 0;
        strcpy(date, "00.0000");
        status = false;
    }
    Bill(const char * billNumber, int expense, char * date, bool status) {
        this->billNumber = new char[strlen(billNumber) + 1];
        strcpy(this->billNumber, billNumber);
        this->expense = expense;
        strcpy(this->date, date);
        this->status = status;
    }
    Bill(const Bill & other) {
        this->billNumber = new char[strlen(other.billNumber) + 1];
        strcpy(this->billNumber, other.billNumber);
        this->expense = other.expense;
        strcpy(this->date, other.date);
        this->status = other.status;
    }
    ~Bill() {
        delete [] billNumber;
    }

    Bill& operator=(const Bill & other) {
        if (this == &other) return *this;
        delete [] billNumber;
        billNumber = new char[strlen(other.billNumber) + 1];
        expense = other.expense;
        strcpy(billNumber, other.billNumber);
        strcpy(date, other.date);
        status = other.status;
        return *this;
    }

    bool operator==(const Bill& other) {
        return strcmp(billNumber, other.billNumber) == 0;
    }

    friend ostream & operator<<(ostream &os, const Bill &other) {
        os << other.billNumber << "(" << other.date << ") - " << other.expense << endl;
        return os;
    }

    int getMonth() {
        return (date[0] - '0') * 10 + (date[1] - '0');
    }
    int getYear() {
        return (date[3] - '0') * 1000 + (date[4] - '0') * 100 + (date[5] - '0') * 10 + (date[6] - '0');
    }

    bool getStatus() const {
        return status;
    }

    int getExpense() const {
        return expense;
    }
};

class UserProfile {
    char username[30];
    Bill billsArray[30];
    int numberOfBills = 0;
public:
    UserProfile() {
        strcpy(username, "");
        numberOfBills = 0;
    }
    UserProfile(const char * username) {
        strcpy(this->username, username);
        numberOfBills = 0;
    }

    UserProfile& operator+=(const Bill& bill) {
        for (int i = 0; i < numberOfBills; i++) {
            if (billsArray[i] == bill) {
                cout << "The bill already exists" << endl;
                return *this;
            }
        }
        billsArray[numberOfBills++] = bill;

        return *this;
    }

    friend ostream& operator<<(ostream &os, const UserProfile &other) {
        os << "Unpaid bills of user " << other.username << " are:" << endl;
        for (int i = 0; i < other.numberOfBills; i++) {
            if (!other.billsArray[i].getStatus()) {
                os << other.billsArray[i];

            }
        }

        return os;
    }

    int totalDue(int month, int year) {
        int totalDue = 0;
        for (int i = 0; i < numberOfBills; i++) {
            if (billsArray[i].getMonth() == month && billsArray[i].getYear() == year) {
                totalDue += billsArray[i].getExpense();
            }
        }

        return totalDue;
    }



};

int main() {
    char number[50], month[8], name[50];
    int price, n;
    bool status;


    int type;
    cin >> type;

    if (type == 1) {
        cout << "-----Test Bill & operator &lt;&lt;-----" << endl ;
        cin >> number >> price >> month >> status;
        Bill b(number, price, month, status);
        cout << b;
    } else if (type == 2) {
        cout << "-----Test Bill & operator == -----" << endl ;
        cin >> number >> price >> month >> status;
        Bill b1(number, price, month, status);
        cin >> number >> price >> month >> status;
        Bill b2(number, price, month, status);
        if (b1 == b2) cout << "Equal" << endl;
        else cout << "Not equal" << endl;

    } else if (type == 3) {
        cout << "-----Test UserProfile & operator += &&lt;&lt; -----" << endl ;
        cin >> name >> n;
        UserProfile up(name);
        for (int i = 0; i < n; i++) {
            cin >> number >> price >> month >> status;
            Bill s(number, price, month, status);
            up += s;
        }
        cout << up;
    } else if (type == 4) {
        cout << "-----Test UserProfile & operator += & totalDue -----" << endl ;
        cin >> name >> n;
        UserProfile up(name);
        for (int i = 0; i < n; i++) {
            cin >> number >> price >> month >> status;
            Bill s(number, price, month, status);
            up += s;
        }
        int m, y;
        cin >> m >> y;
        cout << "Total due for month " << m << " and year " << y << " is:";
        cout << up.totalDue(m, y) << endl;
    } else if (type == 5) {
        cout << "-----Test all -----" << endl ;
        cin >> name >> n;
        UserProfile up(name);
        for (int i = 0; i < n; i++) {
            cin >> number >> price >> month >> status;
            Bill s(number, price, month, status);
            up += s;
        }
        cout << up;
        int m, y;
        cin >> m >> y;
        cout << "Total due for month " << m << " and year " << y << " is:";
        cout << up.totalDue(m, y) << endl;
    }

    return 0;
}
