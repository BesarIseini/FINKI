#include<iostream>
#include<string.h>
using namespace std;

class Race {
protected:
	char city[40];
	int year;
	int month;
	float bestTime;
	float length;
public:
	Race(const char * city = "", int year = 0, int month = 0, float bestTime = 0, float length = 0) {
		strcpy(this->city, city);
		this->year=year;
		this->month =month;
		this->bestTime = bestTime;
		this->length = length;
	}

	virtual float complexity() {
		return bestTime / length;
	}

	friend ostream& operator<<(ostream &os, Race &r) {
		os << r.city << " " << r.month << "." << r.year << " " << r.complexity() << endl;
		return os;
	}
};

class InvalidTimeException {
	char msg[256];
public:
	InvalidTimeException(char * msg) {
		strcpy(this->msg, msg);
	}
	void print() {
		cout << msg << endl;
	}
};

class MotoGPRace: public Race {
	float * bestTimes;
	int noBestTimes;
	int laps;
	static float coefficient;
public:
	MotoGPRace(const char * city = "", int year = 0, int month = 0, float bestTime = 0, float length = 0, float * bestTimes = nullptr, int noBestTimes = 0, int laps = 0):
	Race( city, year, month, bestTime, length)
	{
		this->bestTimes = new float [noBestTimes];
		for (int i = 0; i < noBestTimes; i++) {
			this->bestTimes[i] = bestTimes[i];
		}
		this->laps = laps;
		this->noBestTimes = noBestTimes;
	}
	MotoGPRace(const MotoGPRace & p):
	Race( p.city, p.year, p.month, p.bestTime, p.length)
	{
		this->bestTimes = new float [p.noBestTimes];
		for (int i = 0; i < p.noBestTimes; i++) {
			this->bestTimes[i] = p.bestTimes[i];
		}
		this->laps = p.laps;
		this->noBestTimes = p.noBestTimes;
	}

	float averageTimes() {
		float sum = 0;
		for (int i = 0; i< noBestTimes; i++) {
			sum += bestTimes[i];
		}
		return sum / noBestTimes;
	}

	static void setK(float value) {
		coefficient = value;
	}

	float complexity() {
		float increase = 1;
		if (laps > 22) increase = 1.2;
		return (Race::complexity() + coefficient * averageTimes()) * increase;
	}

	MotoGPRace& operator+=(const float time) {
		if (time < 9.5) {
			throw InvalidTimeException("Invalid Time");
		}
		float * temp = new float[noBestTimes + 1];
		for (int i = 0; i < noBestTimes; i++) {
			temp[i] = bestTimes[i];
		}
		temp[noBestTimes++] = time;
		delete [] bestTimes;
		bestTimes = temp;

		return *this;
	}

	MotoGPRace operator++(int) {
		MotoGPRace temp = *this;
		laps++;
		return temp;
	}

	void setNumberLaps(int newLaps) {
		laps = newLaps;
	}

	int getNumberLaps() {
		return laps;
	}
};

float MotoGPRace::coefficient = 0.4;


int main(){
    int testCase;
    cin >> testCase;
    char city[50];
    int year;
    int month;
    float bestTime;
    float length;
    float bestTimes[50];
    int n;
    int m;
    int choice;
    int numberLaps;

    if (testCase == 1){
        cout << "===== Testing - classes ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        Race t(city, year, month, bestTime, length);
        cout<<t;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        cin>>n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];
        MotoGPRace mgt(city, year, month, bestTime, length,bestTimes, n, numberLaps);
        cout << mgt;
        MotoGPRace mgt2;
    }
    if (testCase == 2){
        cout << "===== Testing - operatorot += ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (choice == 1){
                rArray[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length,bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];

        // add a new best time
        float best;
        cin >> best;
        int flag = 1;
        for (int i = 0; i < m; i++){
            MotoGPRace* nn = dynamic_cast<MotoGPRace*>(rArray[i]);
            if (nn != 0){
                flag = 0;
                (*nn) += best;
                break;
            }
        }

        // print the races
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }
    if (testCase == 3){
        cout << "===== Testing - exceptions ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        MotoGPRace mgt(city, year, month, bestTime, length);
        mgt.setNumberLaps(numberLaps);
        float time1,time2;
        cin>>time1>>time2;

    	try {
			mgt+=time1;
    	} catch (InvalidTimeException &e) {
    		e.print();
    	}

    	try {
    		mgt+=time2;

    	} catch (InvalidTimeException &e) {
    		e.print();
    	}

        cout<<mgt;
    }
    if (testCase == 4){
        cout <<"===== Testing - operator++ ======"<<endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        cin>>n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];

        MotoGPRace mgt(city, year, month, bestTime, length,bestTimes,n,numberLaps);
        float v,koef2;
    	try {
    		cout<<(mgt++).getNumberLaps()<<endl;
    	} catch (InvalidTimeException &e) {
    		e.print();
    	}
        cout<<mgt;
    	try {
    		mgt++;
    	} catch (InvalidTimeException &e) {
    		e.print();
    	}
        cout<<mgt;
    }
    if (testCase == 5){
        cout << "===== Testing - coefficient ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (choice == 1){
                rArray[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length,bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];

        MotoGPRace::setK(0.7);
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }

    if (testCase == 6){
        cout << "===== Testing - full functionality ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (choice == 1){
                rArray[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length,bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
        float newCoef;
        cin>>newCoef;
        MotoGPRace::setK(newCoef);
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
        // print the races
        float newBest;
        cin>>newBest;
        int flag = 1;
        for (int i = 0; i < m; i++){
            MotoGPRace * pok= dynamic_cast<MotoGPRace *>(rArray[i]);
            if(pok!=0)
            {
            	try {
					(*pok)++;
            	} catch (InvalidTimeException &e) {
            		e.print();
            	}

            	try {
            		(*pok)+=newBest;
            	} catch (InvalidTimeException &e) {
            		e.print();
            	}
                if(flag==1)
                {
                    flag = 0;
                	try {
                		*pok+=1.4;
                	} catch (InvalidTimeException &e) {
                		e.print();
                	}


                }
            }
        }
        cout << "\nList of the races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }

    return 0;
}
