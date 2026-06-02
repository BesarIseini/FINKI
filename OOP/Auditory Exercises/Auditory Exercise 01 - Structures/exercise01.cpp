#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct Person {
    char fname[50];
    char lname[50];
    int age;


    void eat() {
        cout << fname << " has eaten!" << endl;
    }

    void sleep() {
        cout << fname << " has sleepen!" << endl;
    }

    void ageCompare(Person otherPerson) {
        if (age < otherPerson.age) {
            cout << otherPerson.fname << " is older!" << endl;
        } else if (age > otherPerson.age) {
            cout << fname << " is older!" << endl;
        } else {
            cout << fname << " and " << otherPerson.fname << " are both the same age!" << endl;
        }
    }
};

void read(Person &person) {
    cin.getline(person.fname, 50);
    cin.getline(person.lname, 50);
    cin >> person.age;
    cin.ignore();
}

void print(Person &person) {
    cout << person.fname << " is " << person.lname << endl;
    cout << person.age << endl;
}

int main () {
    Person anid;
    Person besar;
    read(anid);
    read(besar);
    print(anid);
    print(besar);
    anid.eat();
    anid.sleep();
    besar.sleep();

    besar.ageCompare(anid);

    return 0;
}