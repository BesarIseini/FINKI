#include <iostream>

using namespace std;

class Array {
private:
    int *x;
    int size;
    int capacity;
    public:
    Array(const int capacity = 5) {
        x = new int[capacity];
        size = 0;
        this-> capacity = capacity;
    }
    Array(const Array &other) {
        capacity = other.capacity;
        size = other.size;
        x = new int[capacity];
        for (int i = 0; i < size; i++) {
            x[i] = other.x[i];
        }
    }
    ~Array() {
        delete [] x;
    }

    Array& operator=(const Array &other) {
        if (this == &other) return *this;
        delete [] x;
        capacity = other.capacity;
        size = other.size;
        x = new int[capacity];
        for (int i = 0; i < size; i++) {
            x[i] = other.x[i];
        }
        return *this;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    const int *getX() {
        return x;
    }

    Array &operator+=(int n) {
        if (capacity == size) {
            int *y = new int[capacity * 2];
            for (int i = 0; i < size; i++) {
                y[i] = x[i];
            }
            delete [] x;
            x = y;
            capacity *= 2;
        }
        x[size] = n;
        size++;
        return *this;
    }

    Array &operator-=(int n) {
        int newSize = 0;
        for (int i = 0, j = 0; i < size; i++) {
            if (x[i] != n) {
                x[j++] = x[i];
                newSize++;
            }
        }
        size = newSize;
        return *this;
    }

    int& operator[](int n) {
        int pom = -1;
        if (n >= 0 && n < size) {
            return x[n];
        }
        else {
            cout << "Out of bounds" << endl;
            return pom;
        }
    }

    bool operator==(Array &a) {
        if (this->size != a.size) return false;
        for (int i = 0; i < size; i++) {
            if (x[i] != a.x[i]) return false;
        }
        return true;

    }

    // friend ostream & operator<<(ostream &o, Array &a);
};

ostream& operator<<(ostream &os, Array&a) {
    for (int i = 0; i < a.getSize(); i++) {
        os << a[i] << " ";
    }
    for (int i = a.getSize(); i < a.getCapacity(); ++i) {
        os << "- ";
    }
    os << endl;
    return os;
}

int main () {
    Array a;
    a += (6);
    a += (4);
    a += (3);
    a += (2);
    a += (1);


    Array b(a);
    b -= (2);
    b -= (3);

    a[0] = 9; //primena na operatorot []

    cout << " a: " << a;
    cout << " b: " << b;

    if (a == b) cout << "Isti se";
    else cout << "Ne se isti";


    return 0;
}