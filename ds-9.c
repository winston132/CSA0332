#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid; // Found at index mid
        else if (arr[mid] < target)
            low = mid + 1; // Search in right half
        else
            high = mid - 1; // Search in left half
    }

    return -1; // Not found
}

int main() {
    int arr[100], n, i, target, result;

    // Input size and sorted array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Call binary search
    result = binarySearch(arr, n, target);

    // Output result
    if (result != -1)
        printf("Element found at index %d (position %d).\n", result, result + 1);
    else
        printf("Element not found in the array.\n");

    return 0;
}

