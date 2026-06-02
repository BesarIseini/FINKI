#include <cstring>
#include <iostream>
using namespace std;

enum position {
    employee, manager, owner
};

class Person {
private:
    char name[100];
    int salary;
    position pos;
public:
    Person() {

    }
    Person(char *name, int salary, position pos) {
        strcpy(this->name, name);
        this->salary = salary;
        this->pos = pos;
    }

    ~Person() {
    }

    void setName(const char *name) {
        strcpy(this->name, name);
    }

    void setSalary(const int salary) {
        this->salary = salary;
    }

    void setPosition(position pos) {
        this->pos = pos;
    }

    const char *getName() const {
        return name;
    }

    int getSalary() const {
        return salary;
    }

    position getPosition() const {
        return pos;
    }

};

void sort(Person a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i ; j++) {
            if (a[j].getSalary() < a[j+1].getSalary()) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main () {
    Person employees[100];
    float salary;
    int n, pos;
    char name[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> salary;
        cin >> pos;
        employees[i].setName(name);
        employees[i].setSalary(salary);
        employees[i].setPosition((position) pos);
    }
    sort(employees, n);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << employees[i].getName() << "\t";
        cout << employees[i].getSalary() << "\t";
        cout << employees[i].getPosition() << endl;
    }

    return 0;
}
