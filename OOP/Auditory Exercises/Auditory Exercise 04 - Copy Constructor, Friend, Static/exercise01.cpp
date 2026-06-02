#include <iostream>
#include <cstring>

using namespace std;

class Team {
private:
    char name[100];
    int yearFounded;
    char city[100];

public:
    Team(const char *name = "", int yearFounded = 0, const char *city = "") {
        strcpy(this->name, name);
        this->yearFounded = yearFounded;
        strcpy(this->city, city);
    }
    Team(const Team &team) {
        strcpy(this->name, team.name);
        this->yearFounded = team.yearFounded;
        strcpy(this->city, team.city);
    }

    char * getName() {
        return name;
    }

    void print() const {
        cout << name << " " << yearFounded << endl;
    }
};

class Game {
    private:
    Team host;
    Team guest;
    int hostGoals;
    int guestGoals;
    public:
    Game(const Team host = Team(), const Team guest = Team(), const int hostGoals = 0, const int guestGoals = 0) {
        this->host = host;
        this->guest = guest;
        this->hostGoals = hostGoals;
        this->guestGoals = guestGoals;
    }
    Team getHost() {
        return this->host;
    }
    Team getGuest() {
        return this->guest;
    }
    int getHostGoals() {
        return this->hostGoals;
    }
    int getGuestGoals() {
        return this->guestGoals;
    }
};

Team winner(Game game1, Game game2) {
    if (strcmp(game1.getHost().getName(), game2.getGuest().getName()) == 0 &&
        strcmp(game2.getHost().getName(), game1.getGuest().getName()) == 0) {
        int goalsHost = game1.getHostGoals() + game2.getGuestGoals();
        int goalsGuest = game1.getGuestGoals() + game2.getHostGoals();
        if (goalsHost >= goalsGuest) {
            return game1.getHost();
        } else {
            return game1.getGuest();
        }

    }
    return Team();
}

int main () {
    Team t1("Barcelona", 1900, "Barcelona");
    Team t2("Real Madrid", 1890, "Madrid");
    Team t3("Elche", 1950, "Elche");
    Game g1(t1, t2, 5, 0);
    Game g2(t2, t1, 2, 2);
    Game g3(t1, t3, 6, 2);
    Team w = winner(g1, g2);
    w.print();
    return 0;


    return 0;
}