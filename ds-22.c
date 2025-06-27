#include <stdio.h>
#include <stdlib.h>

// BST node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Inorder traversal to find kth minimum
void kthMinUtil(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k)
        return;

    // Traverse left subtree
    kthMinUtil(root->left, k, count, result);

    // Visit current node
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    // Traverse right subtree
    kthMinUtil(root->right, k, count, result);
}

int findKthMin(struct Node* root, int k) {
    int count = 0;
    int result = -1;
    kthMinUtil(root, k, &count, &result);
    return result;
}

int main() {
    struct Node* root = NULL;

    // Input: Build the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 10);

    int k = 3;
    int kthMin = findKthMin(root, k);
    if (kthMin != -1)
        printf("The %dth minimum value in BST is: %d\n", k, kthMin);
    else
        printf("There are less than %d nodes in the tree.\n", k);

    return 0;
}

