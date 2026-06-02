#include <iostream>
#include <cstring>

using namespace std;


class Ingredient {
    char * name;
    int quantity;
    int calories;
public:
    Ingredient() {
        name = new char[1];
        name[0] = '\0';
        quantity = 0;
        calories = 0;
    }
    Ingredient(char * name, int quantity, int calories) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->quantity = quantity;
        this->calories = calories;
    }
    Ingredient(const Ingredient &in) {
        this->name = new char[strlen(in.name) + 1];
        strcpy(this->name, in.name);
        this->quantity = in.quantity;
        this->calories = in.calories;
    }
    ~Ingredient() {
        delete [] name;
    }

    char * getName () {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    int numberOfCalories() {
        return quantity * calories;
    }

    friend ostream& operator<<(ostream &os, Ingredient &la) {
        os  << la.name << ": " << la.quantity << "g/ml";
        return os;
    }

    Ingredient& operator=(const Ingredient &in) {
        if (this== &in) return *this;
        this->name = new char[strlen(in.name) + 1];
        strcpy(this->name, in.name);
        this->quantity = in.quantity;
        this->calories = in.calories;
        return *this;
    }


};

class Dish {
    Ingredient * ingredients;
    char * dishName;
    int ingredientCount;
public:
    Dish(char * name) {
        dishName = new char[strlen(name) + 1];
        strcpy(dishName, name);
        ingredientCount = 0;
        ingredients = new Ingredient[0];
    }
    Dish(char * name, Ingredient * ingredients, int ingredientCount) {
        dishName = new char[strlen(name) + 1];
        strcpy(dishName, name);
        this->ingredientCount = ingredientCount;
        this->ingredients = new Ingredient[ingredientCount];
        for (int i = 0; i < ingredientCount; i++) {
            this->ingredients[i] = ingredients[i];
        }
    }

    Dish(const Dish &d) {
        dishName = new char[strlen(d.dishName) + 1];
        strcpy(dishName, d.dishName);
        ingredientCount = d.ingredientCount;
        ingredients = new Ingredient[ingredientCount];
        for (int i = 0; i < ingredientCount; i++) {
            ingredients[i] = d.ingredients[i];
        }
    }
    ~Dish() {
        delete [] ingredients;
        delete [] dishName;
    }

    int getTotalCalories() const {
        int total = 0;
        for (int i = 0; i < ingredientCount; i++) {
            total += ingredients[i].numberOfCalories();
        }
        return total;
    }

    Dish operator+(const Dish &d) {
        Ingredient * temp = new Ingredient[ingredientCount + d.ingredientCount];
        int j = 0;
        for (int i = 0; i < d.ingredientCount; i++) {
            temp[j] = d.ingredients[i];
            j++;
        }
        for (int i = 0; i < ingredientCount; i++) {
            temp[j] = ingredients[i];
            j++;
        }


        Dish p(d.dishName, temp, ingredientCount + d.ingredientCount);
        return p;
    }

    Dish& operator+=(const Ingredient &d) {
        Ingredient * temp = new Ingredient[ingredientCount + 1];
        for (int i = 0; i < ingredientCount; i++) {
            temp[i] = ingredients[i];
        }
        temp[ingredientCount++] = d;
        delete [] ingredients;
        ingredients = temp;
        return *this;
    }

    bool operator==(const Dish &d) {
        return getTotalCalories() == d.getTotalCalories();
    }

    friend ostream& operator<< (ostream &os, const Dish &d) {
        os << "Dish: " << d.dishName << endl;
        for (int i = 0; i < d.ingredientCount; i++) {
            os << "- " << d.ingredients[i].getName() << ": " << d.ingredients[i].getQuantity() << "g/ml" << endl;
        }
        os << "Total Calories: " << d.getTotalCalories() << endl;
        return os;
    }
};

int main() {

    char name [50];
    cin>>name;
    // Create Ingredients
    Ingredient tomato(name, 200, 20);
    cin>>name;
    Ingredient onion(name, 100, 30);
    cin>>name;
    Ingredient cheese(name, 50, 50);


    cin>>name;
    // Create Dishes
    Dish salad(name);
    salad += tomato;
    salad += onion;

    cin>>name;
    Dish pizza(name);
    pizza += tomato;
    pizza += cheese;

    // Test + operator
    Dish combinedDish = salad + pizza;
    cout<<combinedDish;

    cout<<"---------------------"<<endl;

    //Test = operator
    Ingredient ingredient = tomato;
    cout<<ingredient;
    cout<<endl;

    cout<<"---------------------"<<endl;

    // Test == operator
    if (salad == pizza) {
        cout << "Salad and Pizza have the same calories." << endl;
    } else {
        cout << "Salad and Pizza do not have the same calories." << endl;
    }

    cout<<"---------------------"<<endl;

    //Test << operator
    cout << "Salad:" << endl;
    cout << salad;

    cout << "Pizza:" << endl;
    cout << pizza;

    return 0;
}