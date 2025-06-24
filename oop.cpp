//Shape Calculator
#include <iostream>
using namespace std;
class Shape {
public:
    virtual void area() = 0;
};
class Rectangle : public Shape {
public:
    void area() override {
        cout << "Area of Rectangle: length * breadth\n";
    }
};
class Circle : public Shape {
public:
    void area() override {
        cout << "Area of Circle: π * r * r\n";
    }
};
int main() {
    Shape* s1 = new Rectangle();
    Shape* s2 = new Circle();
    s1->area();
    s2->area();
    delete s1;
    delete s2;
    return 0;
}

//Employee System
#include <iostream>
using namespace std;
class Employee {
protected:
    string name;
public:
    virtual void showRole() {
        cout << name << " is a general employee.\n";
    }
    void setName(string n) {
        name = n;
    }
};
class Manager : public Employee {
public:
    void showRole() override {
        cout << name << " is a Manager.\n";
    }
};
int main() {
    Manager m;
    m.setName("Umair");
    m.showRole();
    return 0;
}

//Animal Sound
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void speak() = 0;
};
class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks: Woof!\n";
    }
};
class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows: Meow!\n";
    }
};
int main() {
    Animal* a;
    a = new Dog();
    a->speak();
    a = new Cat();
    a->speak();
    delete a;
    return 0;
}

//Bank System
#include <iostream>
using namespace std;
class BankAccount {
protected:
    double balance;
public:
    BankAccount() : balance(0) {}
    virtual void deposit(double amount) {
        balance += amount;
    }
    virtual void display() = 0;
};
class SavingsAccount : public BankAccount {
public:
    void display() override {
        cout << "Savings Account Balance: $" << balance << endl;
    }
};
class CurrentAccount : public BankAccount {
public:
    void display() override {
        cout << "Current Account Balance: $" << balance << endl;
    }
};
int main() {
    BankAccount* acc;
    acc = new SavingsAccount();
    acc->deposit(1000);
    acc->display();
    acc = new CurrentAccount();
    acc->deposit(2000);
    acc->display();
    delete acc;
    return 0;
}

//Vehicle Demo
#include <iostream>
using namespace std;
class Vehicle {
public:
    virtual void start() = 0;
};
class Car : public Vehicle {
public:
    void start() override {
        cout << "Car is starting with key ignition...\n";
    }
};
class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike is starting with kick...\n";
    }
};
int main() {
    Vehicle* v;
    v = new Car();
    v->start();
    v = new Bike();
    v->start();
    delete v;
    return 0;
}

//Student Result
#include <iostream>
using namespace std;
class Student {
protected:
    string name;
    int rollNo;
public:
    void setData(string n, int r) {
        name = n;
        rollNo = r;
    }
    virtual void showResult() {
        cout << name << " (Roll No: " << rollNo << ") has no result.\n";
    }
};
class CSStudent : public Student {
    int marks;
public:
    void setMarks(int m) {
        marks = m;
    }
    void showResult() override {
        cout << name << " scored " << marks << " in Computer Science.\n";
    }
};
int main() {
    CSStudent s;
    s.setData("Umair", 101);
    s.setMarks(88);
    s.showResult();    return 0;
}

//Library Management
#include <iostream>
#include <vector>
using namespace std;
class Item {
public:
    virtual void showDetails() = 0;
};
class Book : public Item {
    string title, author;
public:
    Book(string t, string a) : title(t), author(a) {}
    void showDetails() override {
        cout << "📚 Book: " << title << " by " << author << endl;
    }
};
class DVD : public Item {
    string title;
public:
    DVD(string t) : title(t) {}
    void showDetails() override {
        cout << "💿 DVD: " << title << endl;
    }
};
int main() {
    vector<Item*> library;
    library.push_back(new Book("C++ Fundamentals", "Umair"));
    library.push_back(new DVD("OOP Concepts Tutorial"));
    for (Item* item : library)
        item->showDetails();
    for (Item* item : library)
        delete item;
    return 0;
}


//Salary System
#include <iostream>
using namespace std;
class Employee {
public:
    virtual float calculateSalary() = 0;
};
class PermanentEmployee : public Employee {
    float basic;
public:
    PermanentEmployee(float b) : basic(b) {}
    float calculateSalary() override {
        return basic + 0.2 * basic; // 20% bonus
    }
};
class ContractEmployee : public Employee {
    float hourlyRate;
    int hours;
public:
    ContractEmployee(float rate, int h) : hourlyRate(rate), hours(h) {}
    float calculateSalary() override {
        return hourlyRate * hours;
    }
};
int main() {
    Employee* emp1 = new PermanentEmployee(30000);
    Employee* emp2 = new ContractEmployee(500, 40);
    cout << "Permanent Salary: " << emp1->calculateSalary() << endl;
    cout << "Contract Salary: " << emp2->calculateSalary() << endl;
    delete emp1;
    delete emp2;
    return 0;
}

//Online Order
#include <iostream>
using namespace std;
class Order {
protected:
    int orderId;
    string product;
public:
    void setOrder(int id, string p) {
        orderId = id;
        product = p;
    }
    virtual void process() {
        cout << "Processing order #" << orderId << " for " << product << endl;
    }
};
class ExpressOrder : public Order {
public:
    void process() override {
        cout << "🚀 Express order #" << orderId << " for " << product << " will be delivered in 1 day.\n";
    }
};
int main() {
    Order* ord = new ExpressOrder();
    ord->setOrder(101, "Headphones");
    ord->process();
    delete ord;
    return 0;
}

// Hospital System
#include <iostream>
#include <vector>
using namespace std;
class Person {
public:
    virtual void showInfo() = 0;
    virtual ~Person() {}
};

class Doctor : public Person {
    string name, specialization;
public:
    Doctor(string n, string s) : name(n), specialization(s) {}
    void showInfo() override {
        cout << "👨‍⚕️ Doctor: " << name << " | Specialty: " << specialization << endl;
    }
};
class Patient : public Person {
    string name;
    int age;
public:
    Patient(string n, int a) : name(n), age(a) {}
    void showInfo() override {
        cout << "🧑‍🤒 Patient: " << name << ", Age: " << age << endl;
    }
};
int main() {
    vector<Person*> people;
    people.push_back(new Doctor("Dr. Umair", "Cardiology"));
    people.push_back(new Patient("Ali", 30));
    for (Person* p : people)
        p->showInfo();
    for (Person* p : people)
        delete p;
    return 0;
}

//Zoo Management
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void sound() = 0;
};
class Lion : public Animal {
public:
    void sound() override {
        cout << "🦁 Lion roars!\n";
    }
};
class Elephant : public Animal {
public:
    void sound() override {
        cout << "🐘 Elephant trumpets!\n";
    }
};
int main() {
    Animal* a1 = new Lion();
    Animal* a2 = new Elephant();
    a1->sound();
    a2->sound();
    delete a1;
    delete a2;
    return 0;
}

//School System
#include <iostream>
using namespace std;
class Person {
protected:
    string name;
public:
    void setName(string n) {
        name = n;
    }
};
class Teacher : public Person {
    string subject;
public:
    void setSubject(string s) {
        subject = s;
    }
    void display() {
        cout << "👩‍🏫 Teacher: " << name << " | Subject: " << subject << endl;
    }
};
int main() {
    Teacher t;
    t.setName("Miss Ayesha");
    t.setSubject("Mathematics");
    t.display();
    return 0;
}


//Hotel Booking
#include <iostream>
using namespace std;
class Booking {
protected:
    string customerName;
public:
    void setCustomer(string name) {
        customerName = name;
    }
    virtual void bookRoom() {
        cout << "Booking room for " << customerName << endl;
    }
};
class LuxuryBooking : public Booking {
public:
    void bookRoom() override {
        cout << "🛎️ Luxury Room booked for " << customerName << " with full services.\n";
    }
};
int main() {
    LuxuryBooking b;
    b.setCustomer("Umair");
    b.bookRoom();
    return 0;
}

//Inventory System
#include <iostream>
using namespace std;
class Product {
protected:
    string name;
    double price;
public:
    void setData(string n, double p) {
        name = n;
        price = p;
    }
    virtual void showDetails() {
        cout << "Product: " << name << ", Price: $" << price << endl;
    }
};
class DiscountedProduct : public Product {
    double discount;
public:
    void setDiscount(double d) {
        discount = d;
    }
    void showDetails() override {
        cout << "🛍️ " << name << " with discount: $" << price - (price * discount / 100) << endl;
    }
};
int main() {
    DiscountedProduct p;
    p.setData("Headphones", 2000);
    p.setDiscount(15);
    p.showDetails();
    return 0;
}

//Online Food Ordering
#include <iostream>
using namespace std;
class Food {
public:
    virtual void order() = 0;
};
class Pizza : public Food {
public:
    void order() override {
        cout << "🍕 Pizza ordered with extra cheese!\n";
    }
};
class Burger : public Food {
public:
    void order() override {
        cout << "🍔 Burger ordered with fries!\n";
    }
};
int main() {
    Food* f;
    f = new Pizza();
    f->order();
    f = new Burger();
    f->order();
    delete f;
    return 0;
}