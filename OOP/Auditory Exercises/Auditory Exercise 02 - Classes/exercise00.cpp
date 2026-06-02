#include <iostream>
using namespace std;

class Cuboid {
private:
    int a, b, c;
    public:
    Cuboid() {
        cout << "Default Cuboid" << endl;
    }

    Cuboid(int aa, int bb, int cc) {
        a = aa;
        b = bb;
        c = cc;
        cout << "Constructor Cuboid" << endl;
    }

    ~Cuboid() {
        cout<< "Destructor Cuboid" << endl;
    }

    int area() {
        return 2 * (a * b + a * c + b * c);
    }
    int volume() {
        return a * b * c;
    }
};

int main () {
    Cuboid c(10, 15,20);
}