#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class Character {
    char c;
public:
    Character(char c = '\0') {
        this->c = c;
    }
    Character(const Character &a) {
        c = a.c;
    }
    ~Character() {

    }
    char getChar() {
        return c;
    }

    bool operator==(const Character &other) {
        return c == other.c;
    }

    friend ostream& operator<<(ostream &os, const Character &o) {
        os<<o.c;
        return os;
    }
};

class CharSequence {
    Character * text;
    int textLength;
public:
    CharSequence() {
        textLength = 0;
        text = new Character[0];
    }

    CharSequence(const char * word) {
        textLength = strlen(word);
        text = new Character[textLength];
        for (int i = 0; i < textLength; i++) {
            text[i] = word[i];
        }
    }

    CharSequence(const CharSequence &other) {
        textLength = other.textLength;
        text = new Character[textLength];
        for (int i = 0; i < textLength; i++)
            text[i] = other.text[i];
    }

    CharSequence& operator=(const CharSequence &other) {
        textLength = other.textLength;
        delete [] text;
        text = new Character[textLength];
        for (int i = 0; i < textLength; i++)
            text[i] = other.text[i];
        return *this;
    }

    ~CharSequence() {
        delete [] text;
    }


    Character & operator[](int i) {
        return text[i];
    }

    CharSequence& operator+=(const Character &c) {
        Character * temp = new Character[textLength + 1];
        for (int i = 0; i < textLength; i ++) {
            temp[i] = text[i];
        }
        temp[textLength] = c;
        delete [] text;
        text = temp;
        textLength++;
        return *this;
    }

    bool operator==(const CharSequence &other) {
        if (textLength != other.textLength) return false;
        for (int i = 0; i < textLength; i++) {
            if (!(text[i] == other.text[i]))
                return false;
        }
        return true;
    }

    int operator[](const char &c) {
        int total = 0;
        for (int i = 0; i < textLength; i++) {
            if (text[i] == c) total++;
        }
        return total;
    }

    CharSequence toUpperCase() {
        CharSequence result;
        for (int i = 0; i < textLength; i++) {

            Character d(toupper(text[i].getChar()));
            result += d;
        }

        return result;

    }

    friend ostream& operator<<(ostream &os, const CharSequence &other) {
        for (int i = 0; i < other.textLength; i++) {
            os << other.text[i];
        }
        return os;
    }
};

int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "Testing Character class" << endl;
        cout << "Character constructor" << endl;
        char c;
        cin >> c;
        Character cc(c);
        cout << "OK" << endl;
        cout << "Character operator <<" << endl;
        cout << cc << endl;
    } else if(n == 2) {
        cout << "Testing CharSequence constructors" << endl;
        char word[100];
        cin >> word;
        CharSequence cs1(word);
        cout << cs1 << endl;
    } else if(n == 3) {
        cout << "Testing CharSequence copy constructor and operator[int]" << endl;
        CharSequence cs("Some sequence");
        CharSequence copy(cs);
        cs[0] = 'X';
        cout << "Original: " << cs << endl;
        cout << "Copy: " << copy << endl;
    } else if(n == 4) {
        cout << "Testing CharSequence =operator and operator[int]" << endl;
        CharSequence cs("Some sequence");
        CharSequence copy;
        copy = cs;
        cs[0] = 'X';
        cout << "Original: " << cs << endl;
        cout << "Copy: " << copy << endl;
    } else if(n == 5) {
        cout << "Testing CharSequence operator+=" << endl;
        CharSequence cs;
        char word[100];
        cin >> word;
        int len = strlen(word);
        for(int i = 0; i < len; ++i) {
            cs += Character(word[i]);
        }
        cout << cs << endl;
    } else if(n == 6) {
        cout << "Testing CharSequence operator[char]" << endl;
        CharSequence cs("If you don't read the newspaper, you're uninformed. If you read the newspaper, you're mis-informed.");
        cout << cs['e'] << endl;
    } else if(n == 7) {
        cout << "Testing CharSequence toUpperCase" << endl;
        CharSequence cs("If you tell the truth, you don't have to remember anything");
        cout << cs.toUpperCase() << endl;
    } else if(n == 8) {
        cout << "Testing CharSequence operator ==" << endl;
        CharSequence cs1("abc");
        CharSequence cs2("abc");
        CharSequence cs3("abcd");
        CharSequence cs4("xyz");
        cout << (cs1 == cs2) << endl;
        cout << (cs1 == cs3) << endl;
        cout << (cs2 == cs4) << endl;
    }

    return 0;
}

