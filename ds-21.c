#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if list is palindrome
int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 1;

    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prevSlow = NULL;

    // Find middle using slow & fast pointers
    while (fast != NULL && fast->next != NULL) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = NULL;
    if (fast != NULL) {
        // Odd number of nodes, skip the middle node
        secondHalf = reverse(slow->next);
    } else {
        // Even number of nodes
        secondHalf = reverse(slow);
    }

    struct Node* firstHalf = head;
    struct Node* temp = secondHalf;

    // Compare both halves
    while (temp != NULL) {
        if (firstHalf->data != temp->data)
            return 0;
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return 1;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Input: 1 ? 2 ? 3 ? 2 ? 1
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printf("Linked List: ");
    printList(head);

    if (isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}

