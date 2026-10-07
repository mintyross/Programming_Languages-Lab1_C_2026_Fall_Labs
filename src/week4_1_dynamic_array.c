/*
 * Lab 4, Task 1
 * Name: Rostyslav Hrabenko
 * Student ID: 260ADB166
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 0;  // size of the array
  printf("Enter number of element: ");

  // Validate that scanf successfully read an integer and that n is positive
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  int* nums =
      malloc(n * sizeof(int));  // allocates memory for the array with size n
  if (nums ==
      NULL) {  // if memory allocation failed, program cannot work properly
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter %d integers: ", n);

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &nums[i]) != 1) {
      printf("Invalid input.\n");
      free(nums);
      nums = NULL;
      return 1;
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += *(nums + i);  // calculates sum of the array
  }

  float avg = (float)sum / n;  // calculates average of the array

  printf("Sum = %d\n", sum);        // prints sum of the array
  printf("Average = %.2f\n", avg);  // prints average of the array

  free(nums);   // freeing the array
  nums = NULL;  // good practice

  return 0;
}