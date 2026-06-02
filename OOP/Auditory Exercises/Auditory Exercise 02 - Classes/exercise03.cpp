#include <cstring>
#include <iostream>
using namespace std;

class EMail {
private:
    enum {
        AddrLen = 100, SubLen = 200, BodyLen = 1000
    };
    char to[AddrLen];
    char from[SubLen];
    char subject[SubLen];
    char body[BodyLen];
    public:
    EMail(char *to, char *from, char *subject, char *body)
    {
        strncpy(this->to, to, AddrLen - 1);
        strncpy(this->from, from, AddrLen - 1);
        strncpy(this->subject, subject, SubLen - 1);
        strncpy(this->body, body, BodyLen - 1);
        to[AddrLen - 1] = subject[SubLen - 1] = 0;
        from[AddrLen - 1] = body[BodyLen - 1] = 0;
    }
    ~EMail(){}

    void setTo(char const *n) {
        strncpy(to, n, AddrLen - 1);
        to[AddrLen - 1] = 0;
    }
    void setFrom(char const *n) {
        strncpy(this->from, n, AddrLen - 1);
        from[AddrLen - 1] = 0;
    }
    void setSubject(char const *n) {
        strncpy(this->subject, n, SubLen - 1);
        subject[SubLen - 1] = 0;
    }
    void setBody(char const *n) {
        strncpy(this->body, n, BodyLen - 1);
        body[BodyLen - 1] = 0;
    }

    const char *getTo() {return to;}
    const char *getFrom() {return from;}
    const char *getSubject() {return subject;}
    const char *getBody() {return body;}

    void print() {
        cout << "To: " << to << endl;
        cout << "From: " << from << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }
};

bool checkEmail (char* address) {
    int count = 0;
    while (*address != 0) {
        if ('@' == *address) {
            count++;
        }
        address++;
    }
    return 1 == count;
}

int main() {
    char to[100], from[100], subject[200], body[1000];
    cout << "To: " << endl;
    cin >> to;
    if (checkEmail(to)) {
        cout << "From: " << endl;
        cin >> from;
        cout << "Subject: " << endl;
        cin.ignore();
        cin.getline(subject, 200);
        cout << "Body: " << endl;
        cin.get(body, 1000);
        EMail poraka(to, from, subject, body);
        cout << "Sent: " << endl;
        poraka.print();

    } else {
        cout << "Invalid Email Address!" << endl;
    }
    return 0;
}