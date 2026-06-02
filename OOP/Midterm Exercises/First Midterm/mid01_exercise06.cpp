#include <iostream>
#include <cstring>

using namespace std;

class Word {
    char *word;
public:
    Word(const char * c = "UNDEFINED") {
        word =  new char[strlen(c) + 1];
        strcpy(word, c);
    }
    Word(const Word &other) {
        word = new char[strlen(other.word) + 1];
        strcpy(word, other.word);
    }

    ~Word() {
        delete [] word;
    }

    const char * getWord() {
        return word;
    }

    Word& operator=(const Word &w) {
        if (this == &w) return *this;
        delete [] word;
        word = new char[strlen(w.word) + 1];
        strcpy(word, w.word);
        return *this;
    }


};

class Sentence {
    Word * words;
    int capacity;
    int size;
public:
    Sentence(int capacity = 10) {
        this -> capacity = capacity;
        this -> size = 0;
        words = new Word[capacity];
    }
    Sentence(const Sentence &other) {
        this -> size = other.size;
        this -> capacity = other.capacity;
        this -> words = new Word[capacity];
        for (int i = 0; i < capacity; i++) {
            this -> words[i] = other.words[i];
        }
    }
    ~Sentence() {
        delete [] words;
    }

    Sentence& operator=(const Sentence &other) {
        if (this == &other) return *this;
        delete [] words;
        capacity = other.capacity;
        size = other.size;
        words = new Word[capacity];
        for (int i = 0; i < capacity; i++) {
            words[i] = other.words[i];
        }
        return *this;
    }

    void add(Word w) {
        if (size == capacity) {
            capacity += 10;
            Word * tmp = new Word[capacity];
            for (int i = 0; i < size; i++) {
                tmp[i] = words[i];
            }
            delete [] words;
            words = tmp;
        }
        words[size++] = w;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << words[i].getWord() << " ";
        }
        cout << endl;
    }

    void swap(int i, int j) {
        Word tmp = words[i];
        words[i] = words[j];
        words[j] = tmp;
    }
};


int main () {

}