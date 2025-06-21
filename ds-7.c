#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n = 0, choice, pos, i, value;

    while (1) {
        // Menu
        printf("\nArray Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Insert
                if (n == MAX_SIZE) {
                    printf("Array is full! Cannot insert.\n");
                    break;
                }
                printf("Enter the position (0 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter the value to insert: ");
                scanf("%d", &value);

                // Shift elements to right
                for (i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;
                printf("Element inserted successfully.\n");
                break;

            case 2:  // Delete
                if (n == 0) {
                    printf("Array is empty! Cannot delete.\n");
                    break;
                }
                printf("Enter the position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                    break;
                }

                // Shift elements to left
                for (i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted successfully.\n");
                break;

            case 3:  // Display
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:  // Exit
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}

