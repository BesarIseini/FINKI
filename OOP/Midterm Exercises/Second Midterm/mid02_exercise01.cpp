// You are given a class Person that stores info for name and surname (char array) and year of birth (integer).
//
// You are given a class Song that stores info for: name of the song (char array), performers of the song
// (array of max 10 objects of class Person), number of performers, and ratings of the song
// (dynamically allocated array of integers) and count of people that gave ratings. A rating is a number from 1 to 10.
//
// You are also given a class Movie that has info for name of the movie (dynamically allocated array of characters)
// and popularity of the movie (integer from 1 to 10).
//
// Create a class MovieSong that represents a song that is a soundtrack of a movie (class that is derived from the
// classes Song and Movie) so the objects from this class contain info for the name of the song, performers of the
// song, number of performers, grades from people, number of grades, name of the movie, popularity of the movie and
// popularity of the song (integer from 1 to 10). (5 points)
//
// Each song should enable the following methods:
//
// float getTotalRating() - that returns the total rating of the song. For each song that is not a movie song, the
// rating is an average of the minimum and maximum rating given from people. The rating of a movie song is computed
// as a product of the average of minimum and maximum rating given from people and a coefficient of popularity
// (computed by dividing the popularity of the song with the popularity of the movie). In a case when a song does
// not have any ratings an exception from the class RatingMissingException should be thrown (15 points).
// print() - that prints the name of the song and the performers of the song, and if the song is a movie song,
// in new line prints the name of the movie. (10 points).

// The format of printing a movie song is:
// [Performer 1] ([Year1]), [Performer2] ([Year2]) …  : [Name]
//
// Movie: [Name of the movie]
// Implement the following global functions:
//
// double averageRating(Song** songs, int n) that returns the average rating of all movie songs
// from the list of n songs. For the songs without any ratings from people, the default rating is assumed to be 5. (15 points)
//
// void printSongs(char* performer, Song** songs, int n) - that for a given array of songs, will
// print only those performed by the performer passed as an argument. (10 points)
//
// Fully functionality of the program. (5 points)

#include<iostream>
#include<string.h>
using namespace std;

class RatingMissingException {
    char text[50];
public:
    RatingMissingException(char *text) {
        strcpy(this->text, text);
    }
    void print() {
        cout << text;
    }
};

class Person {
private:
    char name[20];
    int year;
public:
    Person (char *name, int year) {
        strcpy(this->name, name);
        this->year = year;
    }
    Person () {
        strcpy(this->name, "");
    }
    bool operator==(char *name) {
        return strcmp(this->name, name) == 0;
    }
    char const * getName() {
        return name;
    }
    void print() {cout << name << " (" << year << ")";}
};

class Song {
private:
    Person performers[10];
    int numberPerformers;
    int *ratings;
    int numberRatings;

protected:
    char title[30];

public:
    Song(char *title, Person *performers, int numberPerformers, int *ratings, int numberRatings) {
        strcpy(this->title, title);
        this->numberPerformers = numberPerformers;
        for (int i = 0; i < numberPerformers; i++) this->performers[i] = performers[i];
        this->numberRatings = numberRatings;
        this->ratings = new int[numberRatings];
        for (int i = 0; i < numberRatings; i++) this->ratings[i] = ratings[i];

    }
    Song(const Song &k) {
        strcpy(this->title, k.title);
        this->numberPerformers = k.numberPerformers;
        for (int i = 0; i < k.numberPerformers; i++) this->performers[i] = k.performers[i];
        this->numberRatings = k.numberRatings;
        this->ratings = new int[k.numberRatings];
        for (int i = 0; i < k.numberRatings; i++) this->ratings[i] = k.ratings[i];

    }
    Song operator=(const Song &k) {
        if (&k == this) return *this;
        strcpy(this->title, k.title);
        this->numberPerformers = k.numberPerformers;
        for (int i = 0; i < k.numberPerformers; i++) this->performers[i] = k.performers[i];
        this->numberRatings = k.numberRatings;
        delete [] ratings;
        this->ratings = new int[k.numberRatings];
        for (int i = 0; i < k.numberRatings; i++) this->ratings[i] = k.ratings[i];
        return *this;
    }

    int getnumberPerformers() {return numberPerformers;}
    Person operator[](int i) {if (i < numberPerformers && i >= 0) return performers[i]; else return Person();}
    Person * getPerformers() {return performers;}

    int * getRatings() {
        return ratings;
    }

    int getNumberOfRatings() {
        return numberRatings;
    }

    virtual float getTotalRating() {
        if (numberRatings == 0) {
            throw RatingMissingException("No ratings");
        }
        int min = 11, max = 0;
        for (int i = 0; i < numberRatings; i++) {
            if (ratings[i] < min) {
                min = ratings[i];
            }
            if (ratings[i] > max) {
                max = ratings[i];
            }
        }

        return (max + min) / 2.0;
    }

    virtual void print() {
        for (int i = 0; i < numberPerformers; i++) {
            performers[i].print();
            if (i + 1 < numberPerformers) {
                cout << ",";
            }
        }
        cout << ":" << Song::title << endl;
    }

};

class Movie {
private:
    char *title;
protected:
    int popularity;
public:
    Movie(char *title, int popularity) {
        this->popularity = popularity;
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }
    Movie(const Movie &v) {
        this->popularity = v.popularity;
        this->title = new char[strlen(v.title) + 1];
        strcpy(this->title, v.title);
    }
    Movie operator=(const Movie &v) {
        if (this == &v) return *this;
        this->popularity = v.popularity;
        delete [] title;
        this->title = new char[strlen(v.title) + 1];
        strcpy(this->title, v.title);
        return *this;
    }
    void print()  {cout << "Movie:" << title << endl;}
    virtual ~Movie() {delete [] title;}

};

class MovieSong: public Song, public Movie {
    int songPopularity;
public:
    MovieSong(char *songTitle, Person *performers, int numberPerformers,
        int *ratings, int numberRatings, char *movieTitle, int popularity, int songPopularity):
    Song(songTitle, performers, numberPerformers, ratings, numberRatings),
    Movie(movieTitle, popularity)
    {
        this->songPopularity = songPopularity;

    }

    virtual float getTotalRating() {
        if (getNumberOfRatings() == 0) {
            throw RatingMissingException("No ratings");
        }
        int * ratings = getRatings();
        int min = ratings[0];
        int max = ratings[0];
        for (int i = 0; i < getNumberOfRatings(); i++) {

            if (ratings[i] < min) {
                min = ratings[i];
            }
            if (ratings[i] > max) {
                max = ratings[i];
            }
        }

        return ((max + min) / 2.0) * (songPopularity * 1.0 /  popularity * 1.0);
    }

    void print() {
        Song::print();
        Movie::print();
    }
};

double averageRating(Song** songs, int n) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        MovieSong* c = dynamic_cast<MovieSong *>(songs[i]);
        if (c!=0) {
            try {
                sum += c->getTotalRating();
            } catch (RatingMissingException &e) {
                sum += 5;
            }
            count++;
        }
    }

    return sum * 1.0 / count;
}

void printSongs(char* performer, Song** songs, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < songs[i]->getnumberPerformers(); j++) {
            // cout<<songs[i]->getPerformers()[j].getName() << ", ";

            if (strstr(performer, songs[i]->getPerformers()[j].getName())) {
                songs[i]->print();
                break;
            }
        }
        // cout << endl;
        // cout << "The performer " << performer << endl;
    }
}

int main() {

    Person performers[10];
    int year, numberOfPerformers, ratings[20], rating, numberOfRatings, type, popularity, songPopularity;
    char name[40], title[30], perfomer[30], songTitle[30];

    cin >> type;

    if (type == 1) //test class MovieSong
    {
        cout << "-----TEST MovieSong-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++) {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++) {
            cin >> rating;
            ratings[i] = rating;
        }
        cin >> title >> popularity >> songPopularity;


        MovieSong ok(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
        cout << "Object of class MovieSong is created";

    } else if (type == 2) // function print in song
    {
        cout << "-----TEST print-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }

        Song k(title, performers, numberOfPerformers, ratings, numberOfRatings);
        k.print();

    } else if (type == 3) // function getTotalRating
    {
        cout << "-----TEST getTotalRating-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }

        Song k(title, performers, numberOfPerformers, ratings, numberOfRatings);
        cout << "Total rating: " << k.getTotalRating() << endl;

    } else if (type == 4) //funkcija getTotalRating vo MovieSong
    {
        cout << "-----TEST getTotalRating-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }
        cin >> title >> popularity >> songPopularity;

        MovieSong fp(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
        cout << "Total rating: " << fp.getTotalRating() << endl;

    } else if (type == 5) //funkcija print vo MovieSong
    {
        cout << "-----TEST print -----" << endl;
        cin >> songTitle >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }
        cin >> title >> popularity >> songPopularity;

        MovieSong fp(songTitle, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
        fp.print();

    } else if (type == 6) //all classes
    {
        cout << "-----TEST Song and MovieSong-----" << endl;
        cin >> title >> numberOfPerformers;
        for (int i = 0; i < numberOfPerformers; i++)
        {
            cin >> name >> year;
            performers[i] = Person(name, year);
        }
        cin >> numberOfRatings;
        for (int i = 0; i < numberOfRatings; i++)
        {
            cin >> rating;
            ratings[i] = rating;
        }
        cin >> title >> popularity >> songPopularity;

        Song *p = new MovieSong(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
        p->print();
        cout << "Total rating: " << p->getTotalRating() << endl;
        delete p;


    } else if (type == 7) // function average rating
    {
        cout << "-----TEST average rating-----" << endl;
        int k, opt;
        cin >> k;
        Song **pesni = new Song*[k];
        for (int j = 0; j < k; j++) {
            cin >> opt; //1 Song 2 MovieSong
            cin >> title >> numberOfPerformers;
            for (int i = 0; i < numberOfPerformers; i++)
            {
                cin >> name >> year;
                performers[i] = Person(name, year);
            }
            cin >> numberOfRatings;
            for (int i = 0; i < numberOfRatings; i++)
            {
                cin >> rating;
                ratings[i] = rating;
            }
            if (opt == 1) {
                pesni[j] = new Song(title, performers, numberOfPerformers, ratings, numberOfRatings);
            } else {
                cin >> title >> popularity >> songPopularity;
                pesni[j] = new MovieSong(title, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
            }
        }

        cout << "Average rating of the songs is " << averageRating(pesni, k);
        for (int j = 0; j < k; j++) delete pesni[j];
        delete [] pesni;

    } else if (type == 8) // function print songs
    {
        cout << "-----TEST print songs-----" << endl;
        int k, opt;
        cin >> k;
        Song **pesni = new Song*[k];
        for (int j = 0; j < k; j++) {
            cin >> opt; //1 Song 2 MovieSong
            cin >> songTitle >> numberOfPerformers;
            for (int i = 0; i < numberOfPerformers; i++)
            {
                cin >> name >> year;
                performers[i] = Person(name, year);
            }
            cin >> numberOfRatings;
            for (int i = 0; i < numberOfRatings; i++)
            {
                cin >> rating;
                ratings[i] = rating;
            }
            if (opt == 1) {
                pesni[j] = new Song(songTitle, performers, numberOfPerformers, ratings, numberOfRatings);
            } else {
                cin >> title >> popularity >> songPopularity;
                pesni[j] = new MovieSong(songTitle, performers, numberOfPerformers, ratings, numberOfRatings, title, popularity, songPopularity);
            }
        }
        cin >> perfomer;
        cout << "Songs of " << perfomer << " are:" << endl;
        printSongs(perfomer, pesni, k);
        for (int j = 0; j < k; j++) delete pesni[j];
        delete [] pesni;

    }


    return 0;
}

