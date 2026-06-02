#include <iostream>
#include <cstring>

using namespace std;

class Goal {
    char * goalScorer;
    int timeScored;
    char teamName[50];

public:
    Goal() {
        goalScorer = new char[1];
        goalScorer[0] = '\0';
        timeScored = 0;
        strcpy(teamName, "");
    }
    Goal(char * goalScorer, int timeScored, char * teamName) {
        this->goalScorer = new char[strlen(goalScorer) + 1];
        strcpy(this->goalScorer, goalScorer);
        this->timeScored = timeScored;
        strcpy(this->teamName, teamName);
    }
    Goal(const Goal &o) {
        this->goalScorer = new char[strlen(o.goalScorer) + 1];
        strcpy(this->goalScorer, o.goalScorer);
        this->timeScored = o.timeScored;
        strcpy(this->teamName, o.teamName);
    }
    ~Goal() {
        delete [] goalScorer;
    }

    Goal& operator=(const Goal & o) {
        if (this == &o) return *this;
        delete [] goalScorer;
        this->goalScorer = new char[strlen(o.goalScorer) + 1];
        strcpy(this->goalScorer, o.goalScorer);
        this->timeScored = o.timeScored;
        strcpy(this->teamName, o.teamName);
        return *this;
    }

    friend ostream & operator << (ostream& os, const Goal & goal) {
        os << goal.timeScored << " " << goal.goalScorer << endl;
        return os;
    }

    Goal operator++(int) {
        Goal temp = *this;
        this->timeScored++;
        return temp;
    }
    Goal operator--() {
        Goal temp = *this;
        this->timeScored--;
        return temp;
    }

    const char * getTeamName() const {
        return teamName;
    }
};

class Game {
    Goal * goals;
    char team1[50];
    char team2[50];
    int numGoals;
public:
    Game(char * team1, char * team2) {
        strcpy(this->team1, team1);
        strcpy(this->team2, team2);
        numGoals = 0;
        this -> goals = new Goal[0];
    }

    Game& operator +=(const Goal &g) {
        if (strcmp(g.getTeamName(), team1) != 0 && strcmp(g.getTeamName(), team2) != 0) {
            cout << "Invalid team name: " << g.getTeamName() << endl;
            return *this;
        }
        Goal * temp = new Goal[numGoals + 1];
        for (int i = 0; i < numGoals; i++) {
            temp[i] = goals[i];
        }
        temp[numGoals++] = g;
        delete [] goals;
        goals = temp;
        return *this;
    }

    friend ostream& operator<<(ostream &os, const Game &g) {
        os << g.team1 << " - " << g.team2 << endl;
        for (int i = 0; i < g.numGoals ; i++) {
            os << g.goals[i];
        }
        return os;
    }
};

using namespace std;
int main() {
    char team1[50];
    char team2[50];
    cin >> team1;
    cin >> team2;
    Game n(team1, team2);
    int x;
    cin >> x;
    char player[100];
    int m;
    for(int i = 0; i < x; ++i) {
        cin >> player;
        cin >> m;
        cin >> team1;
        Goal g(player, m, team1);
        // try {
        //     n += g;
        // } catch(InvalidTeamName &e) {
        //     cout << "Invalid team name: " << e.what() << endl;
        // }
        n += g;
    }
    cout << n << endl;
    return 0;
}
