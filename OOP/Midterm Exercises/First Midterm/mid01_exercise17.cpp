#include <iostream>
#include <cstring>
using namespace std;

class String {
    char * text;
    int length;
public:
    String() {
        text = new char[1];
        text[0] = '\0';
        length = 0;
    }
    String(const char * text) {
        this->length = strlen(text);
        this->text = new char[length + 1];
        strcpy(this->text, text);
    }
    String(const String &other) {
        length = other.length;
        text = new char[length + 1];
        strcpy(text, other.text);
    }
    ~String() {
        delete [] text;
    }

    String &operator=(const String &other) {
        if (this == &other) return *this;
        length = other.length;
        delete [] text;
        text = new char[length + 1];
        strcpy(text, other.text);
        return *this;
    }

    char operator[](int index) {
        // if (index < 0 || index > length - 1) {
        //     cout << "Index '" << index << "' is out of bounds";
        //     return '\0';
        // }
        return text[index];
    }

    int getLength() const {
        return length;
    }

    int getChar(int index) const {
        return text[index];
    }
};

class StringBuilder {
    int capacity;
    int size;
    char * array;
public:
    StringBuilder(const int capacity = 0) {
        this->capacity = capacity;
        size = 0;
        array = new char[capacity];
    }

    StringBuilder& operator+=(const String &other) {
        if (size + other.getLength() + 2> capacity) {
            capacity *= 2;
            if (size + other.getLength() + 2> capacity) {
                capacity = size + other.getLength() + 2;
            }
        }
        char * temp = new char[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }
        for (int i = size; i < size + other.getLength(); i++) {
            temp[i] = other.getChar(i - size);
        }
        temp[size + other.getLength()] = '\0';

        delete [] array;
        size = size + other.getLength();
        array = temp;
        return *this;
    }

    friend ostream& operator<<(ostream &os, const StringBuilder &other) {
        os<< "Capacity: " << other.capacity << endl;
        os << "Size: " << other.size << endl;
        os << "Contents: " << other.array << endl;
        return os;
    }
};

int main() {
    int n;
    cin >> n;
    StringBuilder sb(n);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        char input[100];
        cin >> input;
        String s(input);
        int x;
        cin >> x;

        if (x < 0 || x >= s.getLength()) {
            cout << "s[" << x << "] = " << "Index '" << x << "' is out of bounds" << endl;
        } else {
            cout << "s[" << x << "] = " << s[x] << endl;
        }


        sb += s;
    }
    cout << sb;
    return 0;
}