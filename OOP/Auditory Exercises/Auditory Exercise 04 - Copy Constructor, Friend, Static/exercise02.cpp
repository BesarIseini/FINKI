//
// Created by besar on 3/23/26.
//

#include <iostream>
#include <cstring>
using namespace std;

class LibraryMember;
class Library;

class Book {
private:
    char title[30];
    char author[30];
    bool availability;
    friend class Library;
    friend void checkOutBook(LibraryMember &member, Library &lib, int &index);

    public:
    Book(char *title = "", char *author = "", bool availability = false) {
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->availability = availability;
    }

    Book(const Book &other) {
        strcpy(this->title, other.title);
        strcpy(this->author, other.author);
        this->availability = other.availability;
    }
    ~Book() {}
};

class Library {
    private:
    char nameLibrary[30];
    Book books[30];
    int numberOfBooks;

    friend void checkOutBook(LibraryMember &member, Library &lib, int &index);
    public:
    Library() {
        strcpy(nameLibrary, "City_Library");
        numberOfBooks = 0;
    }
    ~Library() {}

    void addBook(Book &b) {
        if (numberOfBooks < 30) {
            books[numberOfBooks++] = b;
        } else {
            cout << "Full" << endl;
        }
    }

    void print() {
        cout << "Library: " << nameLibrary << endl;
        for (int i = 0; i < numberOfBooks; i++) {
            cout << books[i].title << " " << books[i].author << " " << books[i].availability << endl;
        }
    }
};

class LibraryMember {
    private:
    char nameMember[30];
    int id;
    friend void checkOutBook(LibraryMember &member, Library &lib, int &index);
    public:
    LibraryMember(char *nameMember = "", int id = 0) {
        strcpy(this->nameMember, nameMember);
        this->id = id;
    }

    ~LibraryMember() {}
};

void checkOutBook(LibraryMember &member, Library &lib, int &index) {
    if (lib.books[index].availability) {
        cout << member.nameMember << " ID: " << member.id << " checks out " << lib.books[index].title << endl;
        lib.books[index].availability = false;
    } else {
        cout << "Sorry " << lib.books[index].title << " is not available" << endl;
    }
}

int main() {
    Library l1;
    int n;
    cout << "Enter the number of books" << endl;
    cin >> n;
    char name[30], author[30];
    bool availability;
    for (int i = 0; i < n; i++) {
        cin >> name >> author >> availability;
        Book b = Book(name, author, availability);
        l1.addBook(b);
    }
    l1.print();
    LibraryMember m1("Marko", 9541);
    int index;
    cin >> index;
    checkOutBook(m1, l1, index);


    return 0;


}