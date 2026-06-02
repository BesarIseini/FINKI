#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Film {
    char title[100];
    int duration;
    float price;
    bool studentDiscount;

public:
    Film() {
        strcpy(title, "");
        duration = 0;
        price = 0;
        studentDiscount = false;
    }
    Film(const char * title, const int duration, const float price, const bool student_discount)
        : duration(duration),
          price(price),
          studentDiscount(student_discount) {
        strcpy(this->title, title);
    }

    Film(const Film &other)
        : duration(other.duration),
          price(other.price),
          studentDiscount(other.studentDiscount) {
        strcpy(this->title, title);
    }

    ~Film() {

    }

    int getDuration() const {
        return duration;
    }

    void setDuration(const int duration) {
        this->duration = duration;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(const float price) {
        this->price = price;
    }

    bool getStudentDiscount() const {
        return studentDiscount;
    }

    void setStudentDiscount(const bool student_discount) {
        studentDiscount = student_discount;
    }

    void setFilm(const char * title, const int duration, const float price, const bool student_discount) {
        strcpy(this->title, title);
        this->duration = duration;
        this->price = price;
        this->studentDiscount = student_discount;
    }

    char * getTitle() {
        return this->title;
    }
};

class FilmFestival {

    char name[100];
    char place[100];
    Film films[100];
    int no;
    friend int main();

public:
    FilmFestival() {}
    FilmFestival(const char * name, const char * location, const Film * films, const int numberOfFilms)
        : no(numberOfFilms) {
        strcpy(this->name, name);
        strcpy(this->place, location);
        for (int i = 0; i < numberOfFilms; i++) {
            this->films[i] = films[i];
        }
    }
     FilmFestival(const FilmFestival &other)
            : no(other.no) {
        strcpy(this->name, other.name);
        strcpy(this->place, other.place);
        for (int i = 0; i < other.no; i++) {
            this->films[i] = other.films[i];
        }
    }
    ~FilmFestival() {

    }

    char * getName() {
        return this->name;
    }

    Film * getFilms () {
        return this->films;
    }

    char * getPlace () {
        return this->place;
    }

    int getNo() {
        return this->no;
    }

    int numberOfCheapFilms() {
        int counter = 0;
        for (int i = 0; i < no; i++) {
            if (films[i].getStudentDiscount()) {
                counter++;
            }
        }
        return counter;
    }

    int getTotalDuration() {
        int counter = 0;
        for (int i = 0; i < no; i++) {
            counter += films[i].getDuration();
        }
        return counter;
    }
};

void print(FilmFestival &ff) {
    cout << ff.getName() << " " << ff.getPlace() << endl;
    for (int i = 0; i < ff.getNo(); i++) {
        cout << ff.getFilms()[i].getTitle() << " " << ff.getFilms()[i].getDuration() << " " << fixed << setprecision(2) << ff.getFilms()[i].getPrice() << endl;
    }
}

void bestFestival(FilmFestival * ff , int n) {
    int bestIndex = 0;
    int numberOfFilmsCheapFilms = ff[0].numberOfCheapFilms();
    int duration = ff[0].getTotalDuration();
    for (int i = 0; i < n; i++) {
        int tempNumber = ff[i].numberOfCheapFilms();
        if (tempNumber > numberOfFilmsCheapFilms) {
            numberOfFilmsCheapFilms = tempNumber;
            duration = ff[i].getTotalDuration();
            bestIndex = i;
        }
        else if (tempNumber == numberOfFilmsCheapFilms && ff[i].getTotalDuration() > duration) {
            duration = ff[i].getTotalDuration();
            bestIndex = i;
        }
    }

    cout << "Najdobar festival: " << ff[bestIndex].getName() << " " << ff[bestIndex].getPlace() << endl;
}

int main()
{
    int i, j, n;
    FilmFestival ff[50];

    cin >> n;

    for (i = 0; i < n; i++){
        char festivalName[100];
        char festivalPlace[100];
        int numberOfFilms;

        /* name of the festival */
        cin >> festivalName;

        /* place it is held */
        cin >> festivalPlace;

        /* number of movies */
        cin >> numberOfFilms;

        strcpy(ff[i].name, festivalName);
        strcpy(ff[i].place, festivalPlace);
        ff[i].no = numberOfFilms;

        for (j = 0; j < ff[i].no; j++){
            char filmName[100];
            int filmTime;
            float filmPrice;
            int filmDiscount;

            /* title of the movie */
            cin >> filmName;

            /* duration */
            cin >> filmTime;

            /* price */
            cin >> filmPrice;

            /* discount */
            cin >> filmDiscount;

            ff[i].films[j].setFilm(filmName, filmTime, filmPrice, filmDiscount);
        }
    }

    for(i = 0; i < n; ++i){
        print(ff[i]);
    }

    bestFestival(ff, n);

    return 0;
}