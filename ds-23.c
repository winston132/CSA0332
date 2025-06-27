#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int n = strlen(str);
    char temp;

    Print the index of repeated characters given in an array 
for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                // Swap characters
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[] = "computer";

    printf("Original string: %s\n", str);

    sortString(str);

    printf("Sorted string: %s\n", str);

    return 0;
}

