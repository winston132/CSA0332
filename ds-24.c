#include <stdio.h>

int main() {
    char arr[] = {'a', 'b', 'c', 'a', 'd', 'b'};
    int n = sizeof(arr) / sizeof(arr[0]);
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        int found = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                if (found == 0) {
                    printf("Character '%c' is repeated at indices: %d ", arr[i], i);
                    found = 1;
                }
                printf("%d ", j);
                visited[j] = 1;
            }
        }
        if (found)
            printf("\n");
    }

    return 0;
}

