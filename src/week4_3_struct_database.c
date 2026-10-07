/*
 * Lab 4, Task 3
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

// Global context pointer so the qsort comparison function can inspect student data
const struct Student* g_students = NULL;

// Comparison function for qsort 
// Sorts indices by Grade in descending order
int compare_indices(const void* a, const void* b) {
  int idx_a = *(const int*)a;
  int idx_b = *(const int*)b;
  
  float grade_a = g_students[idx_a].grade;
  float grade_b = g_students[idx_b].grade;
  
  if (grade_a < grade_b) return 1;
  if (grade_a > grade_b) return -1;
  return 0;
}

int main() {
  int n = 0;  // size of the array
  printf("Enter number of students: ");

  // Validate that scanf successfully read an integer and that n is positive
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  struct Student* Students = malloc(n * sizeof(struct Student));  // allocates memory for the array with size n
  if (Students == NULL) {  // if memory allocation failed, program cannot work properly
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Enter data for each student. One student - one line.
  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d: ", i + 1);
    // If user does not provide 3 variables, program exits.
    if (scanf("%49s %d %f", Students[i].name, &Students[i].id, &Students[i].grade) != 3) {
      free(Students);
      Students = NULL;
      printf("Invalid input.\n");
      return 1;
    }
  }

  // Initializing ranking array and checking its successful creation
  int* rank_indices = malloc(n * sizeof(int));
  if (rank_indices == NULL) {
    printf("Memory allocation failed.\n");
    free(Students);
    Students = NULL;
    return 1;
  }

  // Fill index array with sequential indices
  for (int i = 0; i < n; i++) {
    rank_indices[i] = i;
  }

  // Assign the global reference and execute efficient qsort
  g_students = Students;
  qsort(rank_indices, n, sizeof(int), compare_indices);

  // Output results
  // List of students
  printf("\n%-6s %-11s %s\n", "ID", "Name", "Grade");
  for (int i = 0; i < n; i++) {
    printf("%-6d %-11s %.1f\n", Students[i].id, Students[i].name, Students[i].grade);
  }

  // Calculating overall summary metrics
  float sumOfGrades = 0.0f;
  float topStudentGrade = -1.0f; // Initialized to an impossible low value
  int topStudentID = 0;

  // Calculating sum of grades and finding the top student
  for (int i = 0; i < n; i++) {
    sumOfGrades += Students[i].grade;
    if (Students[i].grade > topStudentGrade) {
      topStudentGrade = Students[i].grade;
      topStudentID = i;
    }
  }

  // Calculating average grade
  float avgGrade = sumOfGrades / n;

  // Statistics output
  printf("\nAverage Grade = %.2f\n", avgGrade);
  printf("\nTop student:\n");
  printf("%-6d %-11s %.1f\n", Students[topStudentID].id, Students[topStudentID].name, Students[topStudentID].grade);
  
  // Printing Sorted Rankings via our dedicated index pointer mapper array
  printf("\nStudents Ranked by Grade (Highest First):\n");
  printf("%-6s %-11s %s\n", "ID", "Name", "Grade");
  for (int i = 0; i < n; i++) {
    int sorted_idx = rank_indices[i];
    printf("%-6d %-11s %.1f\n", Students[sorted_idx].id, Students[sorted_idx].name, Students[sorted_idx].grade);
  }

  // Cleaning up
  free(rank_indices);
  free(Students);
  Students = NULL;
  return 0;
}