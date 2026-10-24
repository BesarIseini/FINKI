#include<iostream>
#include<cstring>
using namespace std;

class InvestmentPlan {
protected:
    char investor[80];
    float sumOfInvesment;
    float shares;
    bool currentDay;
public:
    InvestmentPlan(char * investor = "", float sumOfInvesment = 0.0, float shares = 0.0, bool currentDay = 0) {
        strcpy(this->investor, investor);
        this->sumOfInvesment = sumOfInvesment;
        this->shares = shares;
        this->currentDay = currentDay;
    }
    InvestmentPlan(const InvestmentPlan &p) {
        strcpy(this->investor, p.investor);
        this->sumOfInvesment = p.sumOfInvesment;
        this->shares = p.shares;
        this->currentDay = p.currentDay;
    }
    ~InvestmentPlan() {

    }
    InvestmentPlan operator=(const InvestmentPlan &p) {
        if (this == &p) return *this;
        strcpy(this->investor, p.investor);
        this->sumOfInvesment = p.sumOfInvesment;
        this->shares = p.shares;
        this->currentDay = p.currentDay;
        return *this;
    }

    float getShares() {
        return shares;
    }

    bool getCurrentDay() {
        return currentDay;
    }

    float getSumInvestment() {
        return sumOfInvesment;
    }
};

class InvestmentFund {
protected:
    char name[50];
    InvestmentPlan * ip;
    int nIp;
    float priceOfShare;
public:
    InvestmentFund(char *name, InvestmentPlan * ip, int nIp, float priceOfShare) {
        strcpy(this->name, name);
        this->ip = new InvestmentPlan[nIp];
        this->nIp = nIp;
        for (int i = 0; i < nIp; i++) {
            this->ip[i] = ip[i];
        }
        this->priceOfShare = priceOfShare;
    }
    InvestmentFund(const InvestmentFund & c) {
        strcpy(this->name, c.name);
        this->ip = new InvestmentPlan[c.nIp];
        this->nIp = c.nIp;
        for (int i = 0; i < c.nIp; i++) {
            this->ip[i] = c.ip[i];
        }
        this->priceOfShare = c.priceOfShare;
    }
    ~InvestmentFund() {
        delete [] ip;
    }

    virtual double profit() = 0;
};

class MoneyFund: public InvestmentFund {
    static float yearlyProvision;
public:
    MoneyFund(char *name, InvestmentPlan * ip, int nIp, float priceOfShare):
    InvestmentFund(name,ip,nIp,priceOfShare) {

    }
    ~MoneyFund() {

    }
    double profit() {
        double totalSum = 0;
        for (int i = 0; i < nIp; i++) {
            totalSum += ip[i].getShares() * priceOfShare;
        }
        return (totalSum * yearlyProvision / 100.0) / 365;
    }
};

float MoneyFund::yearlyProvision = 1;

class ActionFund: public InvestmentFund {
    static float yearlyProvision;
    static float entryProvision;
public:
    ActionFund(char *name, InvestmentPlan * ip, int nIp, float priceOfShare):
    InvestmentFund(name,ip,nIp,priceOfShare) {

    }
    ~ActionFund() {

    }

    double profit() {
        double newPlansValue = 0;

        double totalSum = 0;
        for (int i = 0; i < nIp; i++) {
            totalSum += ip[i].getShares() * priceOfShare;
            if (ip[i].getCurrentDay())
                newPlansValue += ip[i].getSumInvestment();
        }
        return (totalSum * yearlyProvision / 100.0) / 365 + newPlansValue * entryProvision / 100.0;
    }
};
float ActionFund::yearlyProvision = 1.5;
float ActionFund::entryProvision = 3;

double totalProfit(InvestmentFund** funds, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += funds[i]->profit();
    }
    return sum;
}

int main(){

    char investitor[80], ime[50];
    double plan, brUdeli, udel;
    bool flag = false;
    int n, m;
    cin >> n;
    InvestmentFund **fondovi = new InvestmentFund*[n];
    for(int i = 0; i < n; i++){
        cin >> ime;
        cin >> m;
        InvestmentPlan *ip = new InvestmentPlan[m];
        for(int j = 0; j < m; j++){
            cin >> investitor >> plan >> brUdeli;
            if(j % 2) flag = true;
            else flag = false;
            InvestmentPlan IP(investitor, plan, brUdeli, flag);
            ip[j] = IP;
        }
        cin >> udel;
        if(i % 2){
            fondovi[i] = new ActionFund(ime, ip, m, udel);

        }
        else{
            fondovi[i] = new MoneyFund(ime, ip, m, udel);
        }
    }
    cout << totalProfit(fondovi, n);
    return 0;
}
