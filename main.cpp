#include <iostream>
#include <string>
#include <climits>
using namespace std;

#include "student.h"

int main(int argc, char* argv[]) {

  // Number of students is derived from argv: each student needs name + age (2 args)
  // argc = 1 (program name) + N*2
  int N = (argc - 1) / 2;

  if (N <= 0) {
    cout << "Usage: " << argv[0] << " name1 age1 name2 age2 ..." << endl;
    return 1;
  }

  // -------------------------------------------------------
  // Read students from argv
  // -------------------------------------------------------
  student* a = new student[N];
  for (int i = 0; i < N; i++) {
    a[i].set_name(string(argv[1 + i * 2]));
    a[i].set_age(atoi(argv[2 + i * 2]));
  }

  // -------------------------------------------------------
  // Print name and age of all students
  // -------------------------------------------------------
  for (int i = 0; i < N; i++) {
    a[i].display();
  }

  // -------------------------------------------------------
  // Find and print the youngest person(s)
  // If more than 1, display all
  // -------------------------------------------------------
  int minAge = INT_MAX;
  for (int i = 0; i < N; i++) {
    if (a[i].get_age() < minAge) {
      minAge = a[i].get_age();
    }
  }

  cout << "Youngest student" << endl;
  for (int i = 0; i < N; i++) {
    if (a[i].get_age() == minAge) {
      a[i].display();
    }
  }

  delete[] a;
  return 0;
}
  
  


