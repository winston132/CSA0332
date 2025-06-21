#include <stdio.h>

int main() {
    int n, i, search, found = 0;
    int arr[100];

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &search);

    for(i = 0; i < n; i++) {
        if(arr[i] == search) {
            found = 1;
            break;
        }
    }

    if(found) {
        printf("Number %d found in the list.\n", search);
    } else {
        printf("Number %d not found in the list.\n", search);
    }

    return 0;
}

