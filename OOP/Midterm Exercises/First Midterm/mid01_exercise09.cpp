#include <iostream>
#include <cstring>
using namespace std;

class SkiLift {
    char name[15];
    int maxUsers;
    bool isLiftFunctional;
    public:
    SkiLift() {
        strcpy (this->name, "");
        maxUsers = 0;
        isLiftFunctional = false;
    }
    SkiLift(const char * name, int maxUsers, int isLiftFunctional) {
        strcpy (this->name, name);
        this->maxUsers = maxUsers;
        this->isLiftFunctional = isLiftFunctional;
    }
    SkiLift(const SkiLift &o) {
        strcpy(name, o.name);
        maxUsers = o.maxUsers;
        isLiftFunctional = o.isLiftFunctional;
    }
    ~SkiLift() {

    }
    char * getName() {
        return name;
    }
    int getMaxUsers() const {
        return maxUsers;
    }
    bool getLiftFunctional() const {
        return isLiftFunctional;
    }

    void setName (const char * name) {
        strcpy (this->name, name);
    }
    void setMaxUsers (const int maxUsers) {
        this->maxUsers = maxUsers;
    }

    void setLiftFunctional (const bool liftFunctional) {
        this->isLiftFunctional = liftFunctional;
    }

};

class SkiCenter {
    char name[20];
    char country[20];
    SkiLift lifts[20];
    int numberOfLifts;
public:
    SkiCenter() {
        strcpy (this->name, "");
        strcpy (country, "");
        numberOfLifts = 0;
    }
    SkiCenter(const char * name, const char * country, const SkiLift * lifts ,const int numberOfLifts) {
        strcpy (this->name, name);
        strcpy (this->country, country);
        this->numberOfLifts = numberOfLifts;
        for (int i = 0; i < numberOfLifts; i++) {
            this->lifts[i] = lifts[i];
        }
    }
    SkiCenter(const SkiCenter &o) {
        strcpy (this->name, o.name);
        strcpy (country, o.country);
        numberOfLifts = o.numberOfLifts;
        for (int i = 0; i < numberOfLifts; i++) {
            this->lifts[i] = o.lifts[i];
        }
    }
    ~SkiCenter() {

    }

    int getCapacity () {
        int capacity = 0;
        for (int i = 0; i < numberOfLifts; i++) {
            if (lifts[i].getLiftFunctional()) {
                capacity += lifts[i].getMaxUsers();
            }
        }
        return capacity;
    }

    int getNumberOfLifts() {
        return numberOfLifts;
    }

    char * getName() {
        return name;
    }

    char * getCountry() {
        return country;
    }
};

void biggestCapacity(SkiCenter * sc, int n) {
    SkiCenter biggestCapacity = sc[0];
    for (int i = 0; i < n; i++) {
        if (sc[i].getCapacity() > biggestCapacity.getCapacity()) {
            biggestCapacity = sc[i];
        }
        else if (sc[i].getCapacity() == biggestCapacity.getCapacity() && sc[i].getNumberOfLifts() > biggestCapacity.getNumberOfLifts()) {
            biggestCapacity = sc[i];
        }
    }

    cout << biggestCapacity.getName() << endl;
    cout << biggestCapacity.getCountry() << endl;
    cout << biggestCapacity.getCapacity() << endl;
}

int main() {
    int n;
    cin >> n;
    SkiCenter skiCenters[n];
    for (int i = 0; i < n; i++) {
        char skiCenterName[20];
        cin >> skiCenterName;
        char skiCenterCountry[20];
        cin >> skiCenterCountry;
        int m;
        cin >> m;
        SkiLift lifts[m];
        for (int j = 0; j < m; j++) {
            char liftName[20];
            cin >> liftName;
            int capacity;
            cin >> capacity;
            bool liftFunctional;
            cin >> liftFunctional;
            SkiLift s(liftName, capacity, liftFunctional);
            lifts[j] = s;
        }
        SkiCenter c(skiCenterName, skiCenterCountry, lifts, m);
        skiCenters[i] = c;
    }

    biggestCapacity(skiCenters, n);
    return 0;
}