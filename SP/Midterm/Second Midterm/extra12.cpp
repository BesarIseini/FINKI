#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char matrix[50][50];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    char word[11];
    cin >> word;
    int len = strlen(word);

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (word[0] != matrix[i][j]) continue;

            for (int d = 0; d < 4; d++) {
                int x = i, y = j;
                int k;
                for (k = 1; k < len; k++) {
                    x += dx[d];
                    y += dy[d];
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        break;
                    }
                    if (matrix[x][y] != word[k]) {
                        break;
                    }
                }
                if (k == len) {
                    cout << i << ", " << j << " -> " << x << ", " << y << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Not Found";
    return 0;
}