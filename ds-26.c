#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Function to initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Function to insert a key using linear probing
void insert(int key) {
    int index = key % SIZE;
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        // If full cycle is done and no empty slot
        if (index == startIndex) {
            printf("Hash Table is Full! Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
}

// Function to display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

int main() {
    int n, key;

    initialize();

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}

