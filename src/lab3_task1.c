/*
 * Lab 3, Task 1
 * Name: Rostyslav Hrabenko
 * Student ID: 260ADB166
 *
 * Implement array algorithms:
 *   - find minimum value
 *   - find maximum value
 *   - calculate sum
 *   - calculate average
 *
 * Rules:
 *   - Write separate functions for each operation.
 *   - Work with int arrays.
 *   - Do not include any headers besides <stdio.h>.
 *   - You may assume size >= 1 and that the sum fits in an int.
 *   - Average must return a float and must NOT be truncated
 *     (e.g. {1, 2} -> 1.50, not 1.00).
 *   - Do not modify main.
 *
 * Example:
 *   int arr[] = {1, 2, 3, 4, 5};
 *   min = array_min(arr, 5); // 1
 *   max = array_max(arr, 5); // 5
 *   sum = array_sum(arr, 5); // 15
 *   avg = array_avg(arr, 5); // 3.0
 *
 * Required output:
 *   Min: 5
 *   Max: 30
 *   Sum: 80
 *   Avg: 16.00
 */

#include <stdio.h>

// Function prototypes
int array_min(int arr[], int size);
int array_max(int arr[], int size);
int array_sum(int arr[], int size);
float array_avg(int arr[], int size);

int main(void) {
  int arr[] = {10, 20, 5, 30, 15};
  int size = 5;

  printf("Min: %d\n", array_min(arr, size));
  printf("Max: %d\n", array_max(arr, size));
  printf("Sum: %d\n", array_sum(arr, size));
  printf("Avg: %.2f\n", array_avg(arr, size));

  return 0;
}

// Implement functions below
int array_min(int arr[], int size) {
  // return smallest element
  // Utilizing the simpliest and the least efficient method of array sorting I
  // know of
  int min = *(arr);  // Write first array value as a min
  for (int i = 0; i < size; i++) {
    if (*(arr + i) < min) {  // If the next value is smaller than the saved one,
      min = *(arr + i);      // then we make it the smallest one
    }
  }
  return min;  // After the cycle finishes, the minimal value of the array is
               // being returned
}

int array_max(int arr[], int size) {
  // return largest element
  // Utilizing the simpliest and the least efficient method of array sorting I
  // know of
  int max = *(arr);  // First element is max
  for (int i = 0; i < size; i++) {
    if (*(arr + i) > max) {  // Compare it with other values
      max = *(arr + i);      // If greater, pick it instead
    }
  }
  return max;  // Return max value
}

int array_sum(int arr[], int size) {
  // return sum of elements
  int sum = 0;  // Initialize sum
  for (int i = 0; i < size; i++) {
    sum += *(arr + i);  // increment sum with every array element
  }
  return sum;  // return sum
}

float array_avg(int arr[], int size) {
  // return average as float (avoid integer division)
  float sum = 0;  // initialize sum
  for (int i = 0; i < size; i++) {
    sum += *(arr + i);  // sum all elements of an array
  }
  float avg = sum / size;  // get average value of an array by dividing the sum
                           // of this array by its size
  return avg;              // return the avarage value
}
