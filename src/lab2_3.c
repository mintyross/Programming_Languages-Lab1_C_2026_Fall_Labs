/*
 * Lab 2, Task 3
 * Name: Rostyslav Hrabenko
 * Student ID: 260ADB166
 */

#include <stdbool.h>
#include <stdio.h>

// Calculates the factorial of n
// Returns 1 (true) if prime, 0 (false) if not prime

int is_prime(int n) {
  // Check divisors from 2 up to the square root of n (i * i <= n)
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;  // Found a factor, so it is NOT prime
    }
  }
  return 1;  // No factors found, it IS prime
}

int main() {
  int num;
  int m;
  printf("Hello from Rostyslav Hrabenko!\n");
  printf("Welcome to the Factoring program!\n");

  while (true) {
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 2) {
      printf("ERROR: input number must be greater than one!\n\n");
    } else if (is_prime(num) == 1) {
      printf("The number IS a prime!\n");
    } else if (is_prime(num) == 0) {
      printf("The number is NOT a prime!\n");
    } else {
      printf("Unexpected error!\n\n");
    }
  }
  return 0;
}
