    #include <iostream>
    #include <cstring>

    using namespace std;

    class Automobile {
        char * brand;
        int * registration;
        int maxSpeed;
    public:
        Automobile() {
            brand = new char [1];
            brand[0] = '\0';
            maxSpeed = 0;
            this->registration = new int [5];

        }
        Automobile(char * brand, int * registration, int maxSpeed) {
            this->brand = new char [strlen(brand) + 1];
            strcpy(this->brand, brand);
            this->registration = new int[5];
            for (int i = 0; i < 5; i++) {
                this->registration[i] = registration[i];
            }
            this->maxSpeed = maxSpeed;
        }
        Automobile(const Automobile &a) {
            this->brand = new char [strlen(a.brand) + 1];
            strcpy(this->brand, a.brand);
            this->registration = new int[5];
            for (int i = 0; i < 5; i++) {
                this->registration[i] = a.registration[i];
            }
            this->maxSpeed = a.maxSpeed;
        }
        ~Automobile() {
            delete [] brand;
            delete [] registration;
        }

        Automobile& operator=(const Automobile &a) {
            if (this == &a) return *this;
            delete [] brand;
            delete [] registration;
            this->brand = new char [strlen(a.brand) + 1];
            strcpy(this->brand, a.brand);
            this->registration = new int[5];
            for (int i = 0; i < 5; i++) {
                this->registration[i] = a.registration[i];
            }
            this->maxSpeed = a.maxSpeed;
            return *this;
        }

        bool operator==(const Automobile &a) {

            for (int i = 0; i < 5; i++) {
                if (registration[i] != a.registration[i]) {
                    return false;
                }
            }
            return true;
        }

        friend ostream& operator<<(ostream &os, const Automobile &a) {
            os << "Marka: " << a.brand << " Registration: [";
            for (int i = 0; i < 5; i++) {
                os << a.registration[i];
                if (i != 4) {
                    os << " ";
                }
            }
            os << "]";

            return os;
        }

        int * getRegistration() {
            return registration;
        }

        int getMaxSpeed() {
            return maxSpeed;
        }
    };

    class RentACar {
        char agencyName[100];
        Automobile * automobiles;
        int numberOfAutomobiles;

    public:
        RentACar(char * name = "") {
            strcpy(agencyName, name);
            numberOfAutomobiles = 0;
            automobiles = new Automobile[0];
        }
        RentACar(const RentACar &r) {
            strcpy(agencyName, r.agencyName);
            numberOfAutomobiles = r.numberOfAutomobiles;
            automobiles = new Automobile[numberOfAutomobiles];
            for (int i = 0; i < numberOfAutomobiles; i++) {
                automobiles[i] = r.automobiles[i];
            }
        }
        RentACar& operator=(const RentACar &r) {
            if (this == &r) return *this;
            strcpy(agencyName, r.agencyName);
            numberOfAutomobiles = r.numberOfAutomobiles;
            delete [] automobiles;
            automobiles = new Automobile[numberOfAutomobiles];
            for (int i = 0; i < numberOfAutomobiles; i++) {
                automobiles[i] = r.automobiles[i];
            }
            return *this;
        }
        ~RentACar() {
            delete [] automobiles;
        }

        RentACar& operator += (const Automobile &r) {
            Automobile * temp = new Automobile[numberOfAutomobiles + 1];
            for (int i = 0; i < numberOfAutomobiles; i++) {
                temp[i] = automobiles[i];
            }
            temp[numberOfAutomobiles++] = r;
            delete [] automobiles;
            automobiles = temp;
            return *this;
        }

        RentACar& operator -= (Automobile &p) {
            for (int i = 0; i < numberOfAutomobiles; i++) {
                bool flag = false;
                for (int j = 0; j < 5; j++) {
                    if (!(automobiles[i] == p)) {
                        break;
                    }
                    flag = true;
                }
                if (flag) {
                    for (int j = i; j < numberOfAutomobiles; j++) {
                        for (int k = i; k < numberOfAutomobiles - 1; k++) {
                            swap(automobiles[i], automobiles[i + 1]);
                        }
                    }
                    numberOfAutomobiles--;
                }
            }
            return *this;
        }
        void pecatiNadBrzina(int max) {
            cout << this->agencyName << endl;
            for (int i = 0; i < this->numberOfAutomobiles; i++) {
                if (this->automobiles[i].getMaxSpeed() > max) {
                    cout << this->automobiles[i];
                }
            }
        }
    };

    int main()
    {
        RentACar agencija("FINKI-Car");
        int n;
        cin>>n;

        for (int i=0;i<n;i++)
        {
            char marka[100];
            int regisracija[5];
            int maximumBrzina;

            cin>>marka;

            for (int i=0;i<5;i++)
                cin>>regisracija[i];

            cin>>maximumBrzina;

            Automobile nov=Automobile(marka,regisracija,maximumBrzina);

            //dodavanje na avtomobil
            agencija+=nov;

        }
        //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
        char marka[100];
        int regisracija[5];
        int maximumBrzina;
        cin>>marka;
        for (int i=0;i<5;i++)
            cin>>regisracija[i];
        cin>>maximumBrzina;

        Automobile greshka=Automobile(marka,regisracija,maximumBrzina);

        //brishenje na avtomobil
        agencija-=greshka;

        agencija.pecatiNadBrzina(150);

        return 0;
    }