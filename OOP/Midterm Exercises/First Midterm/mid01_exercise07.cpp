#include <iostream>
#include <cstring>
using namespace std;


class Pair {
    int value;
    char * key;
public:
    Pair() {
        key = new char[1];
        key[0] = '\0';
        value = 0;
    }
    Pair(char * key, int value) {
        this-> value = value;
        this-> key = new char[strlen(key) + 1];
        strcpy(this->key, key);
    }
    Pair(const Pair &other) {
        value = other.value;
        key = new char[strlen(other.key) + 1];
        strcpy(key, other.key);
    }

    Pair& operator=(const Pair &other) {
        if (this == &other) return *this;
        value = other.value;
        delete [] key;
        key = new char[strlen(other.key) + 1];
        strcpy(key, other.key);

        return *this;
    }

    ~Pair() {
        delete [] key;
    }

    friend ostream& operator<<(ostream &os, const Pair &other) {
        os<<"'" << other.key << "' -> " << other.value << endl;

        return os;
    }

    Pair& operator--() {
        value--;
        return *this;
    }

    Pair operator--(int) {
        Pair temp(*this);
        value--;
        return temp;
    }

    Pair operator*(const Pair &other) {
        // value *= other.value;
        // if (strlen(key) < strlen(other.key) || strlen(key) == strlen(other.key)) {
        //     key = other.key;
        // }
        // return *this;
        char * newKey;
        if (strlen(key) < strlen(other.key)) {
            newKey = key;
        } else {
            newKey = other.key;
        }

        return Pair(newKey, value * other.value);
    }

    int getValue() const {
        return value;
    }
};

class Collection {
    int length;
    Pair *pairs;
public:
    Collection() {
        length = 0;
        pairs = new Pair[0];
    }
    Collection(const Collection &other) {
        length = other.length;
        pairs = new Pair[length];
        for (int i = 0; i < length; i++) {
            pairs[i] = other.pairs[i];
        }
    }
    ~Collection() {
        delete [] pairs;
    }
    Collection& operator=(const Collection &c) {
        length = c.length;
        delete [] pairs;
        pairs = new Pair[length];
        for (int i = 0; i < length; i++) {
            pairs[i] = c.pairs[i];
        }

        return *this;
    }

    Collection& operator+=(const Pair &p) {
        Pair *temp = new Pair[length + 1];
        for (int i = 0; i < length; i++) {
            temp[i] = pairs[i];
        }
        delete [] pairs;
        temp[length] = p;
        pairs = temp;
        length++;
        return *this;
    }

    friend ostream& operator<<(ostream &os, const Collection &c) {
        os<<"Size: " << c.length << endl;
        for (int i = 0; i < c.length; i++) {
            os << c.pairs[i];
        }
        return os;
    }

    int getTotalProduct() const {
        int product = 1;
        for (int i = 0; i < length; i++) {
            product *= pairs[i].getValue();
        }
        return product;
    }

    bool operator<(const Collection &other) const {
        return getTotalProduct() < other.getTotalProduct();
    }

    int greater(int value) const {
        int counter = 0;
        for (int i = 0; i < length; i++) {
            if (pairs[i].getValue() > value) counter++;
        }
        return counter;
    }
};



void read(char *k, float *v) {
    cin >> k;
    cin >> *v;
}
int main() {
    char key[50];
    float value;
    cout << "----- class Pair -----" << endl;
    read(key, &value);
    cout << "----- constructor -----" << endl;
    Pair p1(key, value);
    read(key, &value);
    Pair p2(key, value);
    Pair p3(p1);
    cout << "----- operator << -----" << endl;
    cout << p1;
    cout << p2;
    cout << "----- operator --(int) -----" << endl;
    cout << p1--;
    cout << p1;
    cout << "----- operator -- -----" << endl;
    cout << --p2;
    cout << "----- operator * -----" << endl;
    Pair p = p1 * p2;
    cout << "----- operator = -----" << endl;
    p3 = p;
    cout << p3;

    cout << "----- class Collection -----" << endl;
    cout << "----- constructor -----" << endl;
    Collection k;
    cout << "----- operator += -----" << endl;
    k += p1;
    k += p2;
    k += p3;
    cout << "----- operator << -----" << endl;
    cout << k;
    cout << "----- copy constructor -----" << endl;
    Collection k2(k);
    cout << "----- operator < -----" << endl;
    if(k < k2) {
        cout << "k < k2" << endl;
    } else {
        cout << "k >= k2" << endl;
    }
    k2 += p1;
    if(k < k2) {
        cout << "k < k2" << endl;
    } else {
        cout << "k >= k2" << endl;
    }
    cout << "----- greater -----" << endl;
    int x;
    cin >> x;
    int pp = k.greater(x);
    cout << pp;
    return 0;
}
