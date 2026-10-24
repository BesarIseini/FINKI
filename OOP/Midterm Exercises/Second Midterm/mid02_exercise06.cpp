#include <iostream>
#include <string.h>
using namespace std;

// your code here

class Parcel {
protected:
	int ID;
	static int processingPrice;
public:
	Parcel(int ID = 0) {
		this->ID = ID;
	}
	~Parcel() {

	}

	static void setProcessingPrice(int price) {
		processingPrice = price;
	}

	int getId() {
		return ID;
	}
};
int Parcel::processingPrice = 150;

class Envelope: public Parcel {
	int width;
	int height;
	char receiver[50];
public:
	Envelope(int ID = 0, char * receiver = "", int width = 0, int height = 0): Parcel(ID) {
		this->width = width;
		this->height = height;
		strcpy(this->receiver, receiver);
	}

	int price() {
		return processingPrice + width * height * 0.3;
	}

	char * getReceiver() {
		return receiver;
	}
};

class PostOffice {
	Envelope envelopes[100];
	int n;
public:
	PostOffice() {
		n = 0;
	}
	PostOffice(Envelope * envelopes, int n) {
		for (int i = 0; i < n; i++) {
			this->envelopes[i] = envelopes[i];
		}
		this->n = n;
	}
	~PostOffice() {

	}

	int sendEnvelope(int id, char* receiver, int length, int width) {
		Envelope e = Envelope(id, receiver, width, length);
		envelopes[n++] = e;
		return e.price();
	}

	void printEnvelopsTo(char* receiver) {
		cout << "For " << receiver << " are envelops with ids:";
		for (int i = 0; i < n; i++) {
			if (!strcmp(envelopes[i].getReceiver(), receiver)) {
				cout << " " << envelopes[i].getId();
			}
		}
		cout << endl;
	}
};

int main() {

	int type;
	int n;
	int price;
	int id;
	int height, width;
	char receiver[50];

	PostOffice p;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> type;
		if (type == 1) { // send envelope
			cin >> id >> receiver >> width >> height;
			cout << "The price of sending envelope with id " << id << " is:" << p.sendEnvelope(id, receiver, width, height) << endl;
		} else if (type == 2) { // print envelops to
			cin >> receiver;
			p.printEnvelopsTo(receiver);
		} else if (type == 3) { // set processing price
			cin >> price;
			Parcel::setProcessingPrice(price);
		} else if (type == 4) { // Parcel
			cin >> id;
			Parcel p1(id);
			cout << "Parcel with id [" << p1.getId() << "] is created" << endl;
		} else {// Envelope
			cin >> id >> receiver >> width >> height;
			Envelope p2(id, receiver, width, height);
			cout << "Price of sending envelope with ID: " << p2.getId() << " To: " << p2.getReceiver() << " is: " << p2.price() << endl;
		}
	}
	return 0;
}
