#include <iostream>
#include <string>
using namespace std;

class student{
private:
  string name;
  int age;

public:
  student();                        // constructor: default values
  void set_name(string n = "Yme");
  void set_age(int a);
  string get_name();
  int  get_age();
  void print_name();
  void display();                   // prints Name: ___ and Age: ___
};

// ---- Implementations ----

student::student() : name("Yme"), age(0) {}

void student::set_name(string n) { name = n; }

void student::set_age(int a) { age = a; }

string student::get_name() { return name; }

int student::get_age() { return age; }

void student::print_name() { cout << name; }

void student::display() {
  cout << "Name: " << name << endl;
  cout << "Age: "  << age  << endl;
}
