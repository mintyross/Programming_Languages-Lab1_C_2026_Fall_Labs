/*
 * Lab 2, Task 2
 * Name: Rostyslav Hrabenko
 * Student ID: 260ADB166
 */

#include <stdbool.h>
#include <stdio.h>

// Calculates the factorial of n
long long factorial(int n) {
  int fac = 1;
  for (int p = 1; p <= n; p++) {
    fac = fac * p;
  }
  return fac;
}

int main() {
  int num;
  int m;
  printf("Hello from Rostyslav Hrabenko!\n");
  printf("Welcome to the Factoring program!\n");

  while (true) {
    printf("Enter a number to factor: ");
    scanf("%d", &num);

    if (num < 1) {
      printf("ERROR: input number must be greater than zero!\n\n");
    } else {
      m = factorial(num);
      printf("The factorial of %d is: %d\n\n", num, m);
    }
  }
  return 0;
}
