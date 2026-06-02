#include<bits/stdc++.h>
using namespace std;
class Chocolate {
private:
    char name[101];
    int price;
public:
    Chocolate() {
        strcpy(this->name,"");
        this->price = 0;
    }
    Chocolate(char* name, int price) {
        strcpy(this->name,name);
        this->price = price;
    }
    friend ostream& operator<<(ostream& os, const Chocolate& b) {
        os << b.name << ": $" << b.price;
        return os;
    }
    ~Chocolate() {

    }

    int getPrice() const {
        return price;
    }
};

class ChocolateFactory {
private:
    Chocolate* products;
    int* WeeklyProduction;
    int numProducts;
    void copy(const ChocolateFactory& other) {
        this->numProducts = other.numProducts;
        this->products = new Chocolate[other.numProducts];
        this->WeeklyProduction = new int[other.numProducts];
        for (int i = 0; i < other.numProducts; i++) {
            this->products[i] = other.products[i];
            this->WeeklyProduction[i] = other.WeeklyProduction[i];
        }
    }
public:
    ChocolateFactory(Chocolate* products, int* WeeklyProduction, int numProducts) {
        this->numProducts = numProducts;
        this->products = new Chocolate[numProducts];
        this->WeeklyProduction = new int[numProducts];
        for (int i = 0; i < numProducts; i++) {
            this->products[i] = products[i];
            this->WeeklyProduction[i] = WeeklyProduction[i];
        }
    }
    ChocolateFactory(const ChocolateFactory& other) {
        copy(other);
    }

    ChocolateFactory& operator=(const ChocolateFactory& other) {
        if (this != &other) {
            delete[] this->products;
            delete[] this->WeeklyProduction;
            copy(other);
        }
        return *this;
    }

    ~ChocolateFactory() {
        delete[] products;
        delete[] WeeklyProduction;
    }
    int weeklyIncome() const {
        int total = 0;
        for (int i = 0; i < this->numProducts;i++) {
            total += this->WeeklyProduction[i] * this->products[i].getPrice();
        }
        return total;
    }
    bool operator<(const ChocolateFactory& other) const {
        return this->weeklyIncome() < other.weeklyIncome();
    }
    bool operator>(const ChocolateFactory& other) const {
        return this->weeklyIncome() > other.weeklyIncome();
    }

    ChocolateFactory operator+(const ChocolateFactory& b) {
        int newSize = this->numProducts + b.numProducts;
        Chocolate* newProducts = new Chocolate[newSize];
        int* newWeekly = new int[newSize];

        for (int i = 0; i< this->numProducts;i++) {
            newProducts[i] = this->products[i];
            newWeekly[i] = this->WeeklyProduction[i];
        }

        for (int i = 0; i< b.numProducts;i++) {
            newProducts[this->numProducts + i] = b.products[i];
            newWeekly[this->numProducts + i] = b.WeeklyProduction[i];
        }
        ChocolateFactory result(newProducts,newWeekly,newSize);
        delete[] newProducts;
        delete[]newWeekly;

        return result;
    }

    friend ostream& operator<<(ostream& os, const ChocolateFactory& b) {
        for (int i = 0; i < b.numProducts;i++) {
            os << b.products[i] << " x " << b.WeeklyProduction[i] << endl;
        }
        os << "$" <<b.weeklyIncome() << "/wk" << endl;
        return os;
    }


};


int main() {
    int testCase;
    char name[100];
    int price;

    Chocolate products[100];
    int weeklyProduction[100];

    cin >> testCase;
    if (testCase == 0) {
        cout<<"Testing Chocolate print operator:"<<endl;
        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            cout<<Chocolate(name,price)<<endl;
        }
    }
    else if (testCase == 1) {
        cout<<"Testing ChocolateFactory print operator:"<<endl;

        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            products[i] = Chocolate(name, price);
            cin>>weeklyProduction[i];
        }

        ChocolateFactory cf(products,weeklyProduction,10);
        cout<<cf<<endl;
    }
    else if (testCase == 2) {
        cout<<"Testing ChocolateFactory comparison operators:"<<endl;

        for (int i = 0; i < 3; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,weeklyProduction,3);

        for (int i = 0; i < 4; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,weeklyProduction,4);

        cout<<cf1<<cf2;

        cout<<"< operator: "<< (cf1<cf2 ? "PASS" : "FAIL") <<endl;
        cout<<"> operator: "<< (cf2>cf1 ? "PASS" : "FAIL") <<endl;
    }
    else if (testCase == 3) {
        cout<<"Testing ChocolateFactory sum operator:"<<endl;

        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,weeklyProduction,5);
        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,weeklyProduction,5);

        cout<<cf1+cf2;
    }
}