#include <iostream>
#include <string.h>
using namespace std;

class PlDrustvo {
    char * name;
    int tours;
    int numberOfMembers;
public:
    PlDrustvo() {
        this->name = new char [1];
        name[0] = '\0';
        tours = 0;
        numberOfMembers = 0;
    }
    PlDrustvo(char * name, int tours, int numberOfMembers) {
        this-> name = new char [strlen(name) + 1];
        strcpy(this->name, name);
        this->tours = tours;
        this->numberOfMembers = numberOfMembers;
    }
    PlDrustvo(const PlDrustvo &PL) {
        this-> name = new char [strlen(PL.name) + 1];
        strcpy(this->name, PL.name);
        this->tours = PL.tours;
        this->numberOfMembers = PL.numberOfMembers;
    }

    PlDrustvo& operator=(const PlDrustvo &pl) {
        if (this==&pl) return *this;
        delete [] name;
        this-> name = new char [strlen(pl.name) + 1];
        strcpy(this->name, pl.name);
        this->tours = pl.tours;
        this->numberOfMembers = pl.numberOfMembers;
        return *this;
    }

    ~PlDrustvo() {
        delete [] name;
    }
    PlDrustvo operator+(const PlDrustvo &pl) {
        int newMembers = numberOfMembers + pl.numberOfMembers;
        if (numberOfMembers > pl.numberOfMembers) {
            return PlDrustvo(name, tours, newMembers);
        } else {
            return PlDrustvo(pl.name, pl.tours, newMembers);
        }
    }
    bool operator>(const PlDrustvo &pl) {
        return numberOfMembers > pl.numberOfMembers;
    }
    bool operator<(const PlDrustvo &pl) {
        return numberOfMembers < pl.numberOfMembers;
    }

    friend ostream& operator<<(ostream &os, PlDrustvo &pl) {
        os << "Ime: " << pl.name << " Turi: " << pl.tours << " Clenovi: " << pl.numberOfMembers << endl;
        return os;
    }
};

void najmnoguClenovi(PlDrustvo * pls, int n) {
    int najdobarIndex = 0;
    for (int i = 0; i < n; i++) {
        if (pls[najdobarIndex] < pls[i]) {
            najdobarIndex = i;
        }
    }
    cout << "Najmnogu clenovi ima planinarskoto drustvo: " << pls[najdobarIndex];
}

int main()
{
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i=0;i<3;i++)
    {
        char ime[100];
        int brTuri;
        int brClenovi;
        cin>>ime;
        cin>>brTuri;
        cin>>brClenovi;
        PlDrustvo p(ime,brTuri,brClenovi);
        drustva[i] = p;

    }

    pl = drustva[0] + drustva[1];
    cout<<pl;

    najmnoguClenovi(drustva, 3);

    return 0;
}
