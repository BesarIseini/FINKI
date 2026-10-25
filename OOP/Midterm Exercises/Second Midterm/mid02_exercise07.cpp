#include <iostream>
#include <cstring>
using namespace std;

class MonthlyInvoice {
protected:
	char username[100];
	int usernumber;
	float price;
	int usedInternet;
public:
	MonthlyInvoice(const char * username, int usernumber, float price, int usedInternet) {
		strcpy(this->username, username);
		this->usernumber = usernumber;
		this->price = price;
		this->usedInternet = usedInternet;
	}
	MonthlyInvoice(const MonthlyInvoice &p) {
		strcpy(this->username, p.username);
		this->usernumber = p.usernumber;
		this->price = p.price;
		this->usedInternet = p.usedInternet;
	}
	~MonthlyInvoice() {

	}

	MonthlyInvoice& operator=(const MonthlyInvoice &p) {
		if (this == &p) return *this;
		strcpy(this->username, p.username);
		this->usernumber = p.usernumber;
		this->price = p.price;
		this->usedInternet = p.usedInternet;

		return *this;
	}

	virtual float total_price() = 0;

	bool operator>(MonthlyInvoice &other) {
		return total_price() > other.total_price();
	}

	friend ostream& operator<<(ostream &os, MonthlyInvoice &mi) {
		os << mi.usernumber << " - " << mi.username << ", " << mi.price << endl;
		return os;
	}


};

class BusinessInvoice: public MonthlyInvoice {
	bool isOptic;
	int freeQuantity;
public:
	BusinessInvoice(const char * username, int usernumber, float price, int usedInternet, bool isOptic, int freeQuantity):
	MonthlyInvoice(username, usernumber, price, usedInternet) {
		this->isOptic = isOptic;
		this->freeQuantity = freeQuantity;
	}
	~BusinessInvoice() {

	}
	BusinessInvoice(const BusinessInvoice &p):
	MonthlyInvoice(p.username, p.usernumber, p.price, p.usedInternet) {
		this->isOptic = p.isOptic;
		this->freeQuantity = p.freeQuantity;
	}

	BusinessInvoice& operator=(const BusinessInvoice &p) {
		if (this == &p) return *this;
		MonthlyInvoice::operator=(p);
		this->isOptic = p.isOptic;
		this->freeQuantity = p.freeQuantity;

		return *this;
	}

	float total_price() {
		float base = price;
		if (isOptic) {
			base = base * 1.5;
		}
		float total = base;
		if (usedInternet - freeQuantity > 0) {
			total += (usedInternet - freeQuantity) * 100.0;
		}

		return total;
	}

	BusinessInvoice operator++(int) {
		BusinessInvoice temp = *this;
		usedInternet++;
		return temp;
	}

	friend ostream& operator<<(ostream &os, BusinessInvoice &mi) {
		operator<<(os, (MonthlyInvoice&)mi);
		if (mi.isOptic) {
			os << "optical link, ";
		} else {
			os << "cable link, ";
		}

		if (mi.usedInternet - mi.freeQuantity < 0) {
			os << "0" << endl;
		} else {
			os << mi.usedInternet - mi.freeQuantity << endl;
		}

		return os;
	}
};

class PrivateInvoice: public MonthlyInvoice {
	char embg[13];
	int * movies;
	int noMovies;
public:
	PrivateInvoice(const char * username, int usernumber, float price, int usedInternet):
	MonthlyInvoice(username, usernumber, price, usedInternet) {
		this->movies = nullptr;
		this->noMovies = 0;
	}
	PrivateInvoice(const PrivateInvoice& p):
	MonthlyInvoice(p.username, p.usernumber, p.price, p.usedInternet) {
		strcpy(this->embg, p.embg);
		this->noMovies = p.noMovies;
		this->movies = new int[noMovies];
		for (int i = 0; i < noMovies; i++)
			this->movies[i] = p.movies[i];
	}
	~PrivateInvoice() {
		delete [] movies;
	}

	int totalAmountOfGigabytesFromTheWatchedMovies() {
		int total = 0;
		for (int i = 0; i < noMovies; i++) {
			total += movies[i];
		}
		return total;
	}

	float total_price() {
		return price + usedInternet * 50 + totalAmountOfGigabytesFromTheWatchedMovies() * 10;
	}

	int operator[](int index) {
		if (index < 0 || index >= noMovies) {
			return -1;
		}
		return movies[index];
	}

	int getMoviesNo() {
		return noMovies;
	}


	PrivateInvoice& operator+=(const int movie) {
		int * temp = new int[noMovies+1];
		for (int i = 0; i < noMovies; i++) {
			temp[i] = movies[i];
		}
		temp[noMovies++] = movie;
		delete [] movies;
		movies = temp;
		return *this;
	}

	PrivateInvoice& operator++() {
		usedInternet++;
		return *this;
	}

	PrivateInvoice operator++(int) {
		PrivateInvoice temp = *this;  // save old state
		usedInternet++;
		return temp;
	}


	friend ostream& operator<<(ostream &os, PrivateInvoice &mi) {
		operator<<(os, (MonthlyInvoice&)mi);

		os << mi.usedInternet << endl;
		os << mi.noMovies << ", " << mi.totalAmountOfGigabytesFromTheWatchedMovies() << endl;

		return os;
	}
};

MonthlyInvoice& biggestInvoice(MonthlyInvoice ** p, int n) {
	int maxIndex = 0;
	for (int i = 1; i < n; i++) {
		if (*p[i] > *p[maxIndex])
			maxIndex = i;
	}
	return *p[maxIndex];
}

// Testing the program!!!
int main(){
    int test_case;
    char username[101];
    int userNumber;
    float basic_price;
    int spent_gigabytes;
    bool optical;
    int free_gigabytes;
    int num_inc;

    cin>>test_case;
    if (test_case == 1){
        // Test Case Business Invoice - Constructor, operator <<
        cin>>username>>userNumber>>basic_price>>spent_gigabytes;
        cin>>optical>>free_gigabytes;
        BusinessInvoice bi(username, userNumber,basic_price, spent_gigabytes, optical, free_gigabytes);
        cout<<"BusinessInvoice Created:\n";
        cout<<bi;
    }
    else if (test_case == 2) {
        // Test Case Business Invoice - Constructor, operators <<, ++
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        cin >> optical >> free_gigabytes;
        BusinessInvoice bi(username, userNumber, basic_price, spent_gigabytes, optical, free_gigabytes);
        cout << "BusinessInvoice:\n";
        cout << bi;
        cout << "testing operator++\n";

        // Additional spent gigabytes
        cin >> num_inc;
        for (int i=0; i<num_inc; ++i) {
            bi++;
        }
        cout << bi;
    }
    else if (test_case == 3) {
        // Test Case Business Invoice - Constructor, total_price, operators <<, ++,
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        cin >> optical >> free_gigabytes;
        BusinessInvoice bi(username, userNumber, basic_price, spent_gigabytes, optical, free_gigabytes);
        cout << "Testing total_price()\n";
        cout << bi;
        cout<<bi.total_price()<<endl;
        bi++;
        cout << bi;
        cout<<bi.total_price()<<endl;
    }
    else if (test_case == 4){
        // Test Case Private Invoice - Constructor, operator <<
        cin>>username>>userNumber>>basic_price>>spent_gigabytes;

        PrivateInvoice pi(username, userNumber,basic_price, spent_gigabytes);
        cout<<"Private Invoice Created:\n";
        cout<<pi;
    }
    else if (test_case == 5) {
        // Test Case Private Invoice - Constructor, operators <<, ++
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        PrivateInvoice pi(username, userNumber,basic_price, spent_gigabytes);
        cin >> num_inc;
        for (int i=0; i<num_inc; ++i) {
            pi++;
        }
        cout << pi;
    }
    else if (test_case == 6) {
        // Test Case Private Invoice - Constructor, operators <<, +=
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        PrivateInvoice pi(username, userNumber,basic_price, spent_gigabytes);
        cin >> num_inc;
        int film_length;
        for (int i=0; i<num_inc; ++i) {
            cin>>film_length;
            pi+=film_length;
        }
        cout << pi;
    }
    else if (test_case == 7) {
        // Test Case Private Invoice - Constructor, operators <<, +=, []
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        PrivateInvoice pi(username, userNumber,basic_price, spent_gigabytes);
        cin >> num_inc;
        int film_length;
        for (int i=0; i<num_inc; ++i) {
            cin>>film_length;
            pi+=film_length;
        }
        cout << pi;
        cout << "Movie sizes: [";
        for (int i=0; i<pi.getMoviesNo(); ++i){
            cout << pi[i] << " ";
        }
        cout << "]" << endl;
    }
    else if (test_case == 8) {
        // Test Case Private Invoice - Constructor, total_price
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        PrivateInvoice pi(username, userNumber,basic_price, spent_gigabytes);
        cout<<pi;
        cout<< pi.total_price() <<endl;
        cin >> num_inc;
        int film_length;
        for (int i=0; i<num_inc; ++i) {
            cin>>film_length;
            pi+=film_length;
        }
        cin >> num_inc;
        for (int i=0; i<num_inc; ++i){
            pi++;
        }
        cout << pi;
        cout<< pi.total_price() <<endl;
    }
    else if (test_case == 9) {
        // Test Case

        int num_invoices;
        int invoice_type;

        cin >>num_invoices;
        MonthlyInvoice ** mi = new MonthlyInvoice*[num_invoices];
        for (int j=0;j<num_invoices; ++j) {

            cin >> invoice_type;
            if (invoice_type == 1){
                cin >> username >> userNumber >> basic_price >> spent_gigabytes;
                cin >> optical >> free_gigabytes;
                BusinessInvoice * bip;
                bip = new BusinessInvoice(username, userNumber, basic_price, spent_gigabytes, optical, free_gigabytes);
                cin >> num_inc;
                for (int i=0; i<num_inc; ++i) {
                    (*(bip))++;
                }
                cout << *(bip);
                cout<<bip->total_price()<<endl;

                mi[j] = bip;
            }
            if (invoice_type == 2) {
                cin >> username >> userNumber >> basic_price >> spent_gigabytes;
                PrivateInvoice* pip = new PrivateInvoice(username, userNumber, basic_price, spent_gigabytes);
                cin >> num_inc;
                int film_length;
                for (int i = 0; i < num_inc; ++i) {
                    cin >> film_length;
                    (*pip) += film_length;
                }
                cin >> num_inc;
                for (int i = 0; i < num_inc; ++i) {
                    (*pip)++;
                }
                cout << (*pip);
                cout << pip->total_price() << endl;
                mi[j] = pip;
            }
        }

        cout << "The biggest invoice is:\n";
        MonthlyInvoice& invoice = biggestInvoice(mi, num_invoices);

        MonthlyInvoice* m = &invoice;
        BusinessInvoice* bip;
        PrivateInvoice* pip;
        if (dynamic_cast<BusinessInvoice *> (m)){
            bip = dynamic_cast<BusinessInvoice *> (m);
            cout<<*bip << bip->total_price();
        }
        if (dynamic_cast<PrivateInvoice *> (m)){
            pip = dynamic_cast<PrivateInvoice *> (m);
            cout<<*pip << pip->total_price();
        }

    }
    return 0;
}