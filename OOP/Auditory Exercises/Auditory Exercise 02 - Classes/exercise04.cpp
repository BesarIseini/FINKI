#include <cstring>
#include <iostream>

using namespace std;

class Student {
  private:
  char name[20];
  int age;
  char faculty[20];
  char nasoka[20];
  public:
  Student() {
    name[0] = '\0';
    age = 0;
    faculty[0] = '\0';
    nasoka[0] = '\0';
  }
  Student(char name[], int age, char faculty[], char nasoka[]) {
    strcpy(this->name, name);
    this->age = age;
    strcpy(this->faculty, faculty);
    strcpy(this->nasoka, nasoka);
  }
  ~Student() {

  }

  char * getName() {
      return name;
  }

  void setName(char * name) {
    strcpy(this->name, name);
  }

  void print() {
    cout << name << endl;
    cout << age << endl;
    cout << faculty << endl;
    cout << nasoka << endl;
  }
};

int main() {

}