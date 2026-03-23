#include <iostream>
#include <string>
#include <climits>
using namespace std;

#include "student.h"
#define N 3

int main(int argc, char* argv[]) {

  // -------------------------------------------------------
  // Exercise 2 : compare two students
  // -------------------------------------------------------
  student s1, s2;
  s1.set_name("Amy");   s1.set_age(20);
  s2.set_name("James"); s2.set_age(17);

  // Ternary shortcut for IF  (condition ? true : false)
  if (s1.get_age() > s2.get_age()) {
    s1.print_name(); cout << " is older" << endl;
  } else {
    s2.print_name(); cout << " is older" << endl;
  }

  cout << endl;

  // -------------------------------------------------------
  // 1. Ask for N names and N ages using cin
  // -------------------------------------------------------
  student a[N];
  int i, age;
  string n;

  cout << "=== Enter info for " << N << " students ===" << endl;
  for (i = 0; i < N; i++) {
    cout << "Enter name for student " << (i + 1) << ": ";
    cin >> n;
    a[i].set_name(n);
    cout << "Enter age  for student " << (i + 1) << ": ";
    cin >> age;
    a[i].set_age(age);
  }

  // -------------------------------------------------------
  // 2. Print name and age of all N people
  // -------------------------------------------------------
  cout << "\n=== All students ===" << endl;
  for (i = 0; i < N; i++) {
    a[i].display();
    cout << "---" << endl;
  }

  // -------------------------------------------------------
  // 3. Print name and age of the youngest person
  // -------------------------------------------------------
  int minAge = INT_MAX;
  for (i = 0; i < N; i++) {
    if (a[i].get_age() < minAge) {
      minAge = a[i].get_age();
    }
  }

  cout << "\n=== Youngest person(s) ===" << endl;
  for (i = 0; i < N; i++) {
    if (a[i].get_age() == minAge) {
      a[i].display();
      cout << "---" << endl;
    }
  }

  // -------------------------------------------------------
  // 4. Change input from cin to argv
  //    Usage: ./student name1 age1 name2 age2 name3 age3 ...
  //    (requires argc == 1 + N*2 + 1 for the program name)
  // -------------------------------------------------------
  if (argc == 1 + N * 2) {
    cout << "\n=== Input from argv ===" << endl;
    student b[N];
    for (i = 0; i < N; i++) {
      b[i].set_name(string(argv[1 + i * 2]));
      b[i].set_age(atoi(argv[2 + i * 2]));
    }

    // Print all
    cout << "--- All students (argv) ---" << endl;
    for (i = 0; i < N; i++) {
      b[i].display();
      cout << "---" << endl;
    }

    // Find oldest (Lab requirement: show oldest, if >1 show all)
    int maxAge = 0;
    for (i = 0; i < N; i++) {
      if (b[i].get_age() > maxAge) {
        maxAge = b[i].get_age();
      }
    }

    cout << "\n--- Oldest person(s) (argv) ---" << endl;
    for (i = 0; i < N; i++) {
      if (b[i].get_age() == maxAge) {
        b[i].display();
        cout << "---" << endl;
      }
    }
  }

  return 0;
}
  
  


