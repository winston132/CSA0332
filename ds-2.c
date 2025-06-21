#include <stdio.h>

int main() {
    int n, i, num;

    // Ask user how many numbers will be entered
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Loop through each number
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        if (num % 2 == 0)
            printf("%d is Even\n", num);
        else
            printf("%d is Odd\n", num);
    }

    return 0;
}

