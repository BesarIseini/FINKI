#include <iostream>
#include <cstring>
using namespace std;

// Define a class IceCream that stores information for:
//
// name (dynamically allocated array of chars),
// ingredients (char array, max 100)
// price (decimal number),
// discount (integer in percentage) initial value 0.
// For this class implement:
//
// constructors and destructor (see the main function for calls) (5 points)
// operator << for printing the data in the following format:

class IceCream {
    char * name;
    char ingredients[100];
    float price;
    int discount = 0;
public:
    IceCream() {
        name = new char[1];
        name[0] = '\0';
        price = 0.0;
        strcpy(ingredients, "");
        discount = 0;
    }
    IceCream(char * name, char * ingredients, float price) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        strcpy(this->ingredients, ingredients);
        this -> price = price;
    }
    IceCream(const IceCream &i) {
        this->name = new char[strlen(i.name) + 1];
        strcpy(name, i.name);
        strcpy(ingredients, i.ingredients);
        this->price = i.price;
        discount = i.discount;
    }
    ~IceCream() {
        delete [] name;
    }

    friend ostream& operator<<(ostream &os, IceCream &i) {
        os << i.name << ": " << i.ingredients << " " << i.price;
        if (i.discount > 0) {
            os << " (" << i.price - i.price * (i.discount * 1.0 / 100.0) << ")";
        }

        return os;
    }

    IceCream& operator=(const IceCream &cream) {
        if (this==&cream) return *this;
        delete [] name;
        name = new char[strlen(cream.name) + 1];
        strcpy(name, cream.name);
        strcpy(ingredients, cream.ingredients);
        price = cream.price;

        return *this;
    }

    IceCream& operator++() {
        discount += 5;
        return *this;
    }

    void setDiscount(int discount) {
        if (discount < 0 || discount > 100) {
            cout << "Invalid discount value: " << discount << endl;
            return;
        }
        this->discount = discount;
    }

    void setName(char * newName) {
        char * temp = new char[strlen(newName) + 1];
        for (int i = 0; i < strlen(newName); i++) {
            temp[i] = newName[i];
        }
        temp[strlen(newName)] = '\0';
        delete [] name;
        name = temp;
    }

    IceCream operator+(char * array) {
        char * newName = new char[strlen(array) + strlen(name) + 4];
        for (int i = 0; i < strlen(name); i++) {
            newName[i] = name[i];
        }
        newName[strlen(name)] = '\0';
        strcat(newName, " + ");
        strcat(newName, array);

        IceCream p(newName, ingredients, price + 10);
        p.setDiscount(discount);
        delete [] newName;
        return p;
    }
};

class IceCreamShop {
    char name[50];
    IceCream * iceCreams;
    int numberOfIceCreams;
public:
    IceCreamShop(char * name = "") {
        strcpy(this->name, name);
        numberOfIceCreams = 0;
        iceCreams = new IceCream[0];
    }
    IceCreamShop(const IceCreamShop &ice) {
        strcpy(name, ice.name);
        numberOfIceCreams = ice.numberOfIceCreams;
        iceCreams = new IceCream[numberOfIceCreams];
        for (int i = 0; i < ice.numberOfIceCreams; i++) {
            iceCreams[i] = ice.iceCreams[i];
        }
    }
    ~IceCreamShop() {
        delete [] iceCreams;
    }

    IceCreamShop& operator+=(const IceCream &ice) {
        IceCream * temp = new IceCream[numberOfIceCreams + 1];
        for (int i = 0; i < numberOfIceCreams; i++) {
            temp[i] = iceCreams[i];
        }
        temp[numberOfIceCreams++] = ice;
        delete [] iceCreams;
        iceCreams = temp;
        return *this;
    }

    friend ostream& operator<<(ostream &os, const IceCreamShop &shop) {
        os << shop.name << endl;
        for (int i = 0; i < shop.numberOfIceCreams; i++) {
            os << shop.iceCreams[i] << endl;
        }
        return os;
    }
};

// your code here

// DO NOT CHANGE THE MAIN FUNCTION, EXCEPT THE MARKED PART FOR HANDLING WITH THE EXCEPTION

int main() {
    char name[100];
    char ingr[100];
    float price;
    int discount;

    int testCase;

    cin >> testCase;
	cin.get();
    if(testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        ic1.setDiscount(discount);
        cin.get();
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        IceCream ic2(name, ingr, price);
        ic2.setDiscount(discount);
        cout << "OPERATOR &lt;&lt;" << endl;
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR ++" << endl;
        ++ic1;
        cout << ic1 << endl;
        cout << "OPERATOR +" << endl;
        IceCream ic3 = ic2 + "chocolate";
        cout << ic3 << endl;
    } else if(testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        cout << ic1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        IceCream ic2(ic1);
        cin.get();
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR =" << endl;
        ic1 = ic2;
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "TESTING EXCEPTION" << endl;

        // your exception handling code

        cin >> discount;
      	ic1.setDiscount(discount);


    } else if(testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        cout << "CONSTRUCTOR" << endl;
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
        	cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        cout << ics;
    } else if(testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
        	cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics;
        ics+=x;
        cout << ics << endl;
        cout << icp << endl;
    }


    return 0;
}

