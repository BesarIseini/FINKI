//
// Created by besar on 4/1/26.
//
#include <iostream>
#include <cstring>

using namespace std;

class WorkingWeek {
    int workingHours[5];
    int numberOfWeek;
    public:
    WorkingWeek() {
        numberOfWeek = 0;
    }
    WorkingWeek(int * workingHours, int numberOfWeeks) {
        this->numberOfWeek = numberOfWeeks;
        for (int i = 0; i < 5; i++) {
            this->workingHours[i] = workingHours[i];
        }
    }
    WorkingWeek(const WorkingWeek & w) {
        numberOfWeek = w.numberOfWeek;
        for (int i = 0; i < 5; i++) {
            this->workingHours[i] = w.workingHours[i];
        }
    }
    ~WorkingWeek() {

    }
    int getNumberOfWeeks() {
        return numberOfWeek;
    }

    int * getWorkingHours() {
        return workingHours;
    }

    int getTotalHours() {
        int totalHours = 0;
        for (int i = 0; i < 5; i++) {
            totalHours += workingHours[i];
        }
        return totalHours;
    }
};

class Worker {
    char name[50];
    WorkingWeek workingWeeks[4];

    public:
    Worker() {
        strcpy(name, "");
    }
    Worker(const char * name, const WorkingWeek * workingWeeks) {
        strcpy(this->name, name);
        for (int i = 0; i < 4; i++) {
            this->workingWeeks[i] = workingWeeks[i];
        }
    }
    Worker(const Worker & w) {
        strcpy(this->name, w.name);
        for (int i = 0; i < 4; i++) {
            this->workingWeeks[i] = w.workingWeeks[i];
        }
    }
    ~Worker() {

    }

    char * getName() {
        return name;
    }

    WorkingWeek getWorkWeek(int n) {
        return workingWeeks[n];
    }

    int getMonthHours() {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += getWorkWeek(i).getTotalHours();
        }
        return total;
    }
};

int maxWeek(Worker w) {
    int MaxWeek = 0;
    for (int i = 0; i < 4; i++) {
        if (w.getWorkWeek(i).getTotalHours() > w.getWorkWeek(MaxWeek).getTotalHours()) {
            MaxWeek = i;
        }
    }

    return MaxWeek + 1;
}

void table(Worker * workers, int n) {
    cout << "Wor" << '\t' << "1" << '\t' << "2" << '\t' << "3" << '\t' << "4" << '\t' << "Total" << endl;
    for (int i = 0; i < n; i++) {
        cout << workers[i].getName() << '\t';
        for (int j = 0; j < 4; j++) {
            cout << workers[i].getWorkWeek(j).getTotalHours() << '\t';
        }
        cout << workers[i].getMonthHours() << endl;
    }
}

int main() {
    int n;
    cin >> n;

    Worker workers[n];

    for (int i = 0; i < n; i++) {
        char name[50];
        WorkingWeek workingWeeks[4];
        cin >> name;
        for (int j = 0; j < 4; j++) {
            int workWeek[5];
            for (int k = 0; k < 5; k++) {
                cin >> workWeek[k];
            }
            workingWeeks[j] = WorkingWeek(workWeek, j);
        }
        workers[i] = Worker(name, workingWeeks);
    }

    cout << "TABLE" << endl;
    table(workers, n);

    cout << "MAX WEEK FOR WORKER: " << workers[n / 2].getName() << endl;
    cout << maxWeek(workers[n / 2]) << endl;

    return 0;
}