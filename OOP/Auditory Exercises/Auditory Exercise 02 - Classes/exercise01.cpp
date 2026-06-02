#include <cmath>
#include <iostream>
using namespace std;

class Triangle {
    private:
    int a,b,c;
    public:
    Triangle(int x = 0, int y = 0, int z = 0) {
        a = x;
        b = y;
        c = z;
    }

    ~Triangle() {
    }

    int perimeter () {
        return (a + b + c);
    }

    int area() {
        float s = (a + b + c) / 2;
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }
};

int main () {
    int a,b,c;
    cin >> a >> b >> c;
    Triangle s(a, b, c);
    cout << s.perimeter() << endl;
    cout << s.area() << endl;
    return 0;
}