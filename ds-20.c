#include <stdio.h>

int main() {
    int arr[] = {3, 1, 4, 5, 3, 1, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int visited[n];  // To mark visited elements

    // Initialize all elements of visited[] to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Repeated elements and their counts:\n");

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  // Mark as counted
            }
        }

        if (count > 1) {
            printf("Number %d is repeated %d times\n", arr[i], count);
        }
    }

    return 0;
}

