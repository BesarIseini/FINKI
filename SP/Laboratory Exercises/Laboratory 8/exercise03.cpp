#include <iostream>
#include <iomanip>
using namespace std;

void scale(float arr[], int n) {
    float max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    float quotient = 100 / max;
    for (int i = 0; i < n; i++) {
        arr[i] *= quotient;
    }

}
int main() {
    float points[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    scale(points, n);
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << points[i] << " ";
    }

}