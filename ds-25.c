#include <stdio.h>

int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Elements repeated exactly twice:\n");

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        if (count == 2)
            printf("%d\n", arr[i]);
    }

    return 0;
}

