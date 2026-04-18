#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Print elements in range
void findInRange(struct Node* root, int low, int high) {
    if (root == NULL) return;

    if (root->data > low)
        findInRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        findInRange(root->right, low, high);
}

// Main function
int main() {
    struct Node* root = NULL;

    // Your details printed in output
    printf("Name: Siddhi Timkhede\n");
    printf("PRN: 25070521236\n");
    printf("Batch: D-2\n\n");

    // Creating BST
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 18);

    int low = 7, high = 15;

    printf("Elements in range [%d, %d]: ", low, high);
    findInRange(root, low, high);

    return 0;
}
