#include <stdio.h>

int main() {
    int num, i;
    unsigned long long factorial = 1;  // Using long long to handle large results

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check for negative numbers
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Loop to calculate factorial
        for(i = 1; i <= num; i++) {
            factorial *= i;
        }

        // Output the result
        printf("Factorial of %d = %llu\n", num, factorial);
    }

    return 0;
}

