#include <stdio.h>

// Recursive function to return nth Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0;  // First Fibonacci number
    else if (n == 1)
        return 1;  // Second Fibonacci number
    else
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive step
}

int main() {
    int n, i;

    // Input from user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}

