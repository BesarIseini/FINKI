//
// Created by besar on 3/26/26.
//

#include <iostream>
#include <cstring>
using namespace std;

class Player {
    char name[15];
    int currentLevel;
    int points;

    public:
    Player() {
        strcpy (name, "");
        currentLevel = 0;
        points = 0;
    }
    Player (const char * name, const int level, const int points) {
        strcpy (this->name, name);
        this->currentLevel = level;
        this->points = points;
    }
    Player (const Player & player) {
        strcpy(this->name, player.name);
        this->currentLevel = player.currentLevel;
        this->points = player.points;
    }
    ~Player() {

    }
    void setName (const char * name) {
        strcpy (this->name, name);
    }
    void setLevel (const int level) {
        currentLevel = level;
    }
    void setPoints (const int points) {
        this->points = points;
    }

    char * getName () {
        return name;
    }
    int getLevel () const {
        return currentLevel;
    }
    int getPoints () const {
        return points;
    }
};


class ComputerGame {
    char name[20];
    Player players[30];
    int numberOfPlayers;
    public:
    ComputerGame () {
        strcpy(this->name, "");
        this->numberOfPlayers = 0;
    }
    ComputerGame (const char * name, const Player * players, const int numberOfPlayers) {
        strcpy (this->name, name);
        this->numberOfPlayers = numberOfPlayers;
        for (int i = 0; i < numberOfPlayers; i++) {
            this->players[i] = players[i];
        }
    }
    ComputerGame (const ComputerGame & g) {
        strcpy (this->name, g.name);
        this->numberOfPlayers = g.numberOfPlayers;
        for (int i = 0; i < numberOfPlayers; i++) {
            this->players[i] = g.players[i];
        }
    }
    ~ComputerGame() {

    }
    Player * getPlayers() {
        return players;
    }
    Player getPlayer(const int i) {
        return players[i];
    }

    int getNumberOfPlayers() {
        return numberOfPlayers;
    }

    char * getName() {
        return name;
    }
};

void bestPlayer (ComputerGame * games, int n) {
    ComputerGame mostPopularGame = games[0];
    for (int i = 0; i < n; i++) {
        if (games[i].getNumberOfPlayers() > mostPopularGame.getNumberOfPlayers()) {
            mostPopularGame = games[i];
        }
    }

    Player bestPlayer = mostPopularGame.getPlayers()[0];
    for (int i = 0; i < mostPopularGame.getNumberOfPlayers(); i++) {
        if (mostPopularGame.getPlayers()[i].getPoints() > bestPlayer.getPoints()) {
            bestPlayer = mostPopularGame.getPlayers()[i];
        }
    }


    cout << "Najdobar igrac e igracot so korisnicko ime " << bestPlayer.getName() << " koj ja igra igrata " << mostPopularGame.getName();
}

int main () {
    int n;
    cin >> n;
    ComputerGame games[n];
    for (int i = 0; i < n; i++) {
        char gameName[20];
        int m;
        cin >> gameName;
        cin >> m;
        Player players[m];
        for (int j = 0; j < m; j++) {
            char playerName[15];
            cin >> playerName;
            int currentLevel = 0;
            int points = 0;
            cin >> currentLevel;
            cin >> points;
            Player p(playerName, currentLevel, points);
            players[j] = p;
        }
        ComputerGame g(gameName, players, m);
        games[i] = g;
    }
    bestPlayer(games, n);
    return 0;
}