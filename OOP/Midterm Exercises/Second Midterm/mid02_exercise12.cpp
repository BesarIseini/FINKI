#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

class Student {
	string index;
	string fname;
	string lname;
	int points;
public:
	Student(string index = "", string fname = "", string lname = "", int points = 0) {
		this->index = index;
		this-> fname = fname;
		this->lname = lname;
		this->points = points;
	}
	Student(const Student &s) {
		this->index = s.index;
		this-> fname = s.fname;
		this->lname = s.lname;
		this->points = s.points;
	}
	Student& operator=(const Student &s) {
		this->index = s.index;
		this-> fname = s.fname;
		this->lname = s.lname;
		this->points = s.points;

		return *this;
	}
	~Student() {

	}

	int grade() {
		if (points < 50) return 5;
		if (points < 60) return 6;
		if (points < 70) return 7;
		if (points < 80) return 8;
		if (points < 90) return 9;
		return 10;
	}

	friend ostream& operator<<(ostream &os, Student &s) {
		os << s.index << " " << s.fname << " " << s.lname << " " << s.points << " Grade: " << s.grade() << endl;
		return os;
	}

	string getIndex() {
		return index;
	}
};

class StudentFailedException : exception {
	string index;
public:
	StudentFailedException(string index = "") {
		this->index = index;
	}
	void print () {
		cout << "Student with id " << index << " failed the course" << endl;
	}
};

class Results {
	Student * students;
	int n;
public:
	Results(Student * students = nullptr, int n = 0) {
		this->n = n;
		this -> students = new Student[this->n];
		for (int i = 0; i < n; i++) {
			this->students[i] = students[i];
		}
	}
	Results(const Results &r) {
		this->n = r.n;
		this -> students = new Student[n];
		for (int i = 0; i < n; i++) {
			this->students[i] = r.students[i];
		}
	}
	Results& operator=(const Results &r) {
		if (this == &r) return *this;
		this->n = r.n;
		delete [] students;
		this -> students = new Student[n];
		for (int i = 0; i < n; i++) {
			this->students[i] = r.students[i];
		}

		return *this;
	}

	~Results() {
		delete [] students;
	}

	Results& operator+=(Student &s) {
		if (s.grade() == 5) throw StudentFailedException(s.getIndex());
		Student * temp = new Student[n + 1];
		for (int i = 0; i < n; i++) {
			temp[i] = students[i];
		}
		temp[n++] = s;
		delete [] students;
		students = temp;
		return *this;
	}

	friend ostream& operator<<(ostream &os, Results &r) {
		for (int i = 0; i < r.n; i++) {
			os << r.students[i];
		}
		return os;
	}

	Results withGrade(int grade) {
		Results result;
		for (int i = 0; i < n; i++) {
			if (students[i].grade() == grade) {
				result += students[i];
			}
		}
		return result;
	}

	int getN() {
		return n;
	}
};

void wtf() {
	ofstream fout("input.txt");
	string line;
	while (getline(std::cin, line)) {
		if (line == "----"){
			break;
		}
		fout << line << endl;
	}
}

void rff(string path) {
	ifstream fin(path);
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
}


int main() {

	wtf();

	Results results;
	//TODO your code here
	//TODO Read the students from the file and add them in `results`
	ifstream fin("input.txt");
	string index, fname, lname;
	int points;
	while (fin>>index) {
		fin>>fname>>lname;
		fin>>points;
		fin.ignore();
		Student s(index, fname, lname, points);
		try {
			results += s;
		} catch (StudentFailedException &e) {
			e.print();  // print and continue reading
		}
	}
	fin.close();

	//DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
	int grade;
	cin >> grade;
	//DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

	//TODO Save the results in the files output1.txt and output2.txt after this line
	ofstream fout1("output1.txt");
	try {
		fout1 << results;
	} catch (StudentFailedException &e) {
		e.print();
	}

	fout1.close();


	ofstream fout2("output2.txt");

	try {
		Results gradeStudents = results.withGrade(grade);
		fout2 << gradeStudents;
		if (gradeStudents.getN() == 0) {
			fout2 << "None";
		}
	} catch (StudentFailedException &e) {
		e.print();
	}
	fout2.close();


	//DO NOT MODIFY THE CODE BELLOW

	cout << "All students:" << endl;
	rff("output1.txt");
	cout << "Grade report for grade " << grade << ": " << endl;
	rff("output2.txt");


	return 0;
}