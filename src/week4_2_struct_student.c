/*
 * Lab 4, Task 2
 * Name: Rostyslav Hrabenko
 * Student ID: 260ADB166
 */

#include <stdio.h>
#include <stdlib.h>

struct Student {  // initializing structure at runtime
  char name[50];
  int id;
  float grade;
};

int main() {
  // creating structures with specified data
  struct Student Student1 = {"Alice Johnson", 1001, 9.1};
  struct Student Student2 = {"Bob Smith", 1002, 8.7};

  // Displaying data. %s for string output without for() loop
  printf("Student 1: %s, ID: %d, Grade: %.1f\n", Student1.name, Student1.id,
         Student1.grade);
  printf("Student 2: %s, ID: %d, Grade: %.1f\n", Student2.name, Student2.id,
         Student2.grade);

  return 0;
}