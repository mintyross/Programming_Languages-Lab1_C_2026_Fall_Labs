#include <stdio.h>
#include <stdbool.h>

// Calculates the sum from 1 to n
int sum_to_n(int n) {
    int sum = 0;
    for (int p = 1; p <= n; p++) {
        sum += p;
    }
    return sum;
}

int main() {
    int num;
    int m;
    printf("Hello from Rostyslav Hrabenko!\n");
    printf("Welcome to the Summing program!\n");
    
    while (true) {
        printf("Enter a number to sum: ");
        scanf("%d", &num);
        
        if (num < 1) {
            printf("ERROR: input number must be greater than zero!\n\n"); 
        } else {
            m = sum_to_n(num);
            printf("The sum from 1 to %d is: %d\n\n", num, m);
        }
    }
    return 0;
}
