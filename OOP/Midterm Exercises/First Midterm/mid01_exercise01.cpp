#include <iostream>
#include <cstring>
using namespace std;

class Driver {
    char name[100];
    int time;
    public:
    Driver() {
        strcpy(name, "");
        time = 0;
    }
    Driver(char * name, int time) {
        strcpy(this->name, name);
        this->time = time;
    }

    int getTime() {
        return time;
    }

    char * getName() {
        return name;
    }
};

class Race {
    char location[100];
    int numberOfDrivers;
    Driver drivers[100];
public:
    Race() {
        strcpy(location, "");
        numberOfDrivers = 0;
    }
    Race(char * location, int numberOfDrivers, Driver drivers[]) {
        strcpy(this->location, location);
        this->numberOfDrivers = numberOfDrivers;
        for (int i = 0; i < numberOfDrivers; i++) {
            this->drivers[i] = drivers[i];
        }
    }
    ~Race() {

    }

    char * getLocation() {
        return this->location;
    }

    Driver * getDrivers() {
        return drivers;
    }

    Driver getDriver(int number) {
        return drivers[number];
    }

    int getNumberOfDrivers() {
        return numberOfDrivers;
    }
};

void sortByDriverTime(Race race, Driver drivers[], int numberOfDrivers) {
    for (int i = 0; i < numberOfDrivers; i++) {
        for (int j = 0; j < numberOfDrivers - 1; j++) {
            if (drivers[j].getTime() > drivers[j + 1].getTime()) {
                swap(drivers[j], drivers[j + 1]);
            }
        }
    }
}


void formatTime(int seconds) {
    // printing format for time:
    // minutes = time / 60
    // seconds = time % 60
    // if seconds < 10 print a leading zero
    // example: 1:05
    cout << seconds / 60 << ":";
    if (seconds % 60 < 10) {
        cout << '0';
    }
    cout << seconds % 60 << endl;
}

int main() {
    int n;
    cin >> n;

    Race races[n];
    for(int i = 0; i < n; i++) {
        char location[100];
        int numberOfDrivers;
        cin >> location;
        cin >> numberOfDrivers;
        Driver drivers[numberOfDrivers];

        for (int j = 0; j < numberOfDrivers; j++) {
            char name[100];
            cin >> name;
            int time;
            cin >> time;


            drivers[j] = Driver(name, time);;

        }
        races[i] = Race(location, numberOfDrivers, drivers);

    }


    // printing format for time:
    // minutes = time / 60
    // seconds = time % 60
    // if seconds < 10 print a leading zero
    // example: 1:05

    for(int i = 0; i < n; i++) {
        sortByDriverTime(races[i], races[i].getDrivers(), races[i].getNumberOfDrivers());
        cout << races[i].getLocation() << " (" << races[i].getNumberOfDrivers() << " Drivers)" << endl;
        cout << "1. " << races[i].getDriver(0).getName() << " ";
        formatTime(races[i].getDriver(0).getTime());
        cout << "2. " << races[i].getDriver(1).getName() << " ";
        formatTime(races[i].getDriver(1).getTime());
        cout << "3. " << races[i].getDriver(2).getName() << " ";
        formatTime(races[i].getDriver(2).getTime());
    }


    return 0;
}