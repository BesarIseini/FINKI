#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Product {
	string name;
	string category;
	int price;
	int quantity;
public:
	Product(string name = "", string category = "", int price = 0, int quantity = 0) {
		this->name = name;
		this->category = category;
		this->price = price;
		this->quantity = quantity;
	}
	Product(const Product &p) {
		this->name = p.name;
		this->category = p.category;
		this->price = p.price;
		this->quantity = p.quantity;
	}
	~Product() {

	}

	int totalPrice() {
		return price * quantity;
	}

	friend ostream& operator<<(ostream &os, Product &p) {
		os << p.name << " (" << p.category << ") " << p.quantity << " x " << p.price << " = " << p.totalPrice() << endl;
		return os;
	}

	string getCategory() {
		return category;
	}
};

class NoProductFoundException:exception {
	string msg;
public:
	NoProductFoundException(string msg = "") {
		this->msg = msg;
	}
	void print() {
		cout << msg << endl;
	}
};

class Store {
	Product * products;
	int size;
public:
	Store(Product * products = nullptr, int size = 0) {
		this->size = size;
		this->products = new Product[this->size];
		for (int i = 0; i < this->size; i++) {
			this->products[i]=products[i];
		}
	}
	Store(const Store &c) {
		this->size = c.size;
		products = new Product[this->size];
		for (int i = 0; i < this->size; i++) {
			this->products[i]=c.products[i];
		}
	}
	~Store() {
		delete [] products;
	}

	Store& operator=(const Store &p) {
		if (this == &p) return *this;
		size = p.size;
		delete [] products;
		this->products = new Product[size];
		for (int i = 0; i < size; i++) {
			products[i] = p.products[i];
		}
		return *this;
	}

	Store& operator+=(const Product &p) {
		Product * temp = new Product[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i]=products[i];
		}
		temp[size++] = p;
		delete [] products;
		products = temp;
		return *this;
	}

	friend ostream& operator<<(ostream &os, Store &s) {
		// os << "All products:" << endl;
		for (int i = 0; i < s.size; i++) {
			os << s.products[i];
		}
		return os;
	}

	Store fromCategory(string &category) {
		int categorySize = 0;
		Product * categoryProducts = new Product[size];
		for (int i = 0; i < size; i++) {
			if (products[i].getCategory() == category) {
				categoryProducts[categorySize++] = products[i];
			}
		}
		if (categorySize==0) {
			string errorMsg = "No products from category " + category + " were found in the store";
			throw NoProductFoundException(errorMsg);
		}
		Store result(categoryProducts, categorySize);
		delete [] categoryProducts;
		return result;
	}
};

void wtf() {
	ofstream fout("input.txt");
	string line;
	while (getline(std::cin, line)) {
		if (line == "----") {
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


	Store s;

	//TODO your code starts here
	//TODO Read the products from the file and add them in the store `s`

	ifstream fin("input.txt");
	string name, category1;
	int price, quantity;
	while (getline(fin, name)) {
		fin >> category1;
		fin >> price >> quantity;
		fin.ignore();
		Product p(name, category1, price, quantity);
		s += p;
	}
	fin.close();

	//DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT

	string category;
	cin >> category;

	//DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

	//TODO Save the results in the files output1.txt and output2.txt after this line
	ofstream fout1("output1.txt");
	fout1 << s;
	fout1.close();

	ofstream fout2("output2.txt");

	try {
		Store storeCategory = s.fromCategory(category);
		fout2<< storeCategory;
	} catch (NoProductFoundException &e) {
		e.print();
	}
	fout2.close();
	//DO NOT MODIFY THE CODE BELLOW

	cout << "All products:" << endl;
	rff("output1.txt");
	cout << "Products from category " << category << ": " << endl;
	rff("output2.txt");


	return 0;
}