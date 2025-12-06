#include <iostream>
using namespace std;

// d<e or d>e
// d < e
// d > e
// 8242  pattern true
// 824 pattern false
// 82 pattern

int main() {
    char a = 'a';
    switch (a) {
        case 1:
            cout<<"HELLO"<<endl;
            break;
        case 'a':
            cout<<"HELLO WORLD"<<endl;
            break;
        default:
            cout<<"HELLO WORLD !!"<<endl;
    }


    return 0;
}