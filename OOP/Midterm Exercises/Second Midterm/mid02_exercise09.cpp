#include <iostream>
#include <cstring>
using namespace std;

class Tickets {
protected:
	int ID[12];
	char event[100];
	float basePrice;
	static int discount;
public:
	Tickets(int * id, char * event, float basePrice) {
		for (int i = 0; i < 12; i++) {
			ID[i] = id[i];
		}
		strcpy(this->event, event);
		this->basePrice = basePrice;
	}
	~Tickets() {

	}

	friend ostream& operator<<(ostream &os, Tickets &p) {
		for (int i = 0; i < 12; i++) {
			os << p.ID[i];
		}
		os << "-" << p.event << "-" << p.presmetajCena();
	}

	bool falsifikat(int from, int to) {
		int value = 0;
		for (int i = 8; i < 12; i++) {
			value = value * 10 + ID[i];
		}
		if (value >= from && value <= to) {
			return true;
		}
		return false;
	}

	virtual float presmetajCena() {
		return basePrice * (1 - (discount / 100.0));
	}

	static void changeDiscount(int d) {
		discount = d;
	}
};
int Tickets::discount = 0;
class Online: public Tickets {
	bool premium;
public:
	Online(int * id, char * event, float basePrice, bool premium):
	Tickets(id, event, basePrice) {
		this->premium = premium;
	}
	~Online() {

	}

	virtual float presmetajCena() {
		float price = Tickets::presmetajCena();  // applies static discount
		if (premium) price -= basePrice * 0.15;  // subtract 15% of BASE price
		return price;
	}
};

class Offline: public Tickets {
	bool reservation;
public:
	Offline(int * id, char * event, float basePrice, bool reservation):
	Tickets(id, event, basePrice) {
		this->reservation = reservation;
	}
	~Offline() {

	}

	virtual float presmetajCena() {
		float price = Tickets::presmetajCena();  // applies static discount
		if (reservation) price += basePrice * 0.10;  // add 10% of BASE price
		return price;
	}
};

void vkupenPrihod(Tickets ** t, int n, int from, int to) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		if (t[i]->falsifikat(from,to)) {
			sum += t[i]->presmetajCena();
		}
	}
	cout << sum;
}

int main() {
	int testCase;
	cin >> testCase;
	int ID[12];
	char nastan[100];
	float price;
	bool premium;
	bool rezervacija;
	int od, doo;

	if (testCase == 1) {
		cout << "===== TESTING CONSTRUCTORS ======" << endl;
		for (int i = 0; i < 12; i++)
			cin >> ID[i];
		cin >> nastan;
		cin >> price;
		cin >> premium;
		Online o1(ID, nastan, price, premium);
		cout << o1 << endl;
		for (int i = 0; i < 12; i++)
			cin >> ID[i];
		cin >> nastan;
		cin >> price;
		cin >> rezervacija;
		Offline o2(ID, nastan, price, rezervacija);
		cout << o2 << endl;

	}
	else if (testCase == 2) {
		cout << "===== TESTING METHOD vkupenPrihod()  ======" << endl;
		int n;
		cin >> n;
		Tickets** t = new Tickets*[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 12; j++)
				cin >> ID[j];
			cin >> nastan;
			cin >> price;

			if (i % 2 == 0){
				cin >> premium;
				t[i] = new Online(ID, nastan, price, premium);
			}
			else {
				cin >> rezervacija;
				t[i] = new Offline(ID, nastan, price, rezervacija);
			}
		}
		cin >> od;
		cin >> doo;
		vkupenPrihod(t, n, od, doo);
		for (int i = 0; i < n; ++i) {
			delete t[i];
		}
		delete[] t;
	}
	else if (testCase == 3) {
		cout << "===== TESTING DISCOUNT STATIC ======" << endl;
		int n;
		cin >> n;
		//cout<<n<<endl;
		Tickets** t = new Tickets*[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 12; ++j)
				cin >> ID[j];
			cin >> nastan;
			//cout<<nastan<<endl;
			cin >> price;
			//cout<<price<<endl;
			if (i % 2 == 0){
				cin >> premium;
				t[i] = new Online(ID, nastan, price, premium);
			}
			else {
				cin >> rezervacija;
				//cout<<rezervacija<<endl;
				t[i] = new Offline(ID, nastan, price, rezervacija);
			}
		}
		int d;
		cin >> d;
		Tickets::changeDiscount(d);
		for (int i = 0; i < n; ++i)
			cout << *t[i] << endl;

	}
}
