#include <iostream>
#include <cctype>

using namespace std;

struct Student {
    char firstName[50];
    char lastName[50];
    int number;
    int totalPoints;
    void print() {
        cout << firstName << "\t";
        cout << lastName << "\t";
        cout << number << "\t";
        cout << totalPoints << endl;
    }
};

void normalize(char *name) {
    *name = toupper(*name);
    ++name;
    while (*name) {
        *name = tolower(*name);
        ++name;
    }
}

void read(Student &s) {
    cin >> s.firstName;
    cin >> s.lastName;
    normalize(s.firstName);
    normalize(s.lastName);
    cin >> s.number;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    s.totalPoints = a + b + c + d;
}

void sort(Student s[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (s[j].totalPoints < s[j + 1].totalPoints) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}



int main() {
    Student s[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        read(s[i]);
    }
    sort(s, n);
    cout << "ORDERED" << endl;
    for (int i = 0; i < n; i++) {
        s[i].print();
    }

    return 0;
}