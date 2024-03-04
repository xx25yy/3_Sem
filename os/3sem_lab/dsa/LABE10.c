/*10. Develop a menu driven Program in C for the following operations on Binary Search
Tree (BST)
of Integers .
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit*/
#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left, *right;
};

typedef struct BST NODE;

NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

NODE* insert(NODE* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

NODE* search(NODE* root, int data) {
    if (root == NULL || root->data == data) {
        if (root != NULL)
            printf("\nElement found: %d", root->data);
        else
            printf("\nElement not found");
        return root;
    }
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    NODE* root = NULL;
    int choice, data;
    do {
        printf("\n1. Insert\n2. Search\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("\nEnter element to search: ");
                scanf("%d", &data);
                search(root, data);
                break;
            case 3:
                printf("\nInorder Traversal: ");
                inorder(root);
                break;
            case 4:
                printf("\nPreorder Traversal: ");
                preorder(root);
                break;
            case 5:
                printf("\nPostorder Traversal: ");
                postorder(root);
                break;
            case 6:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (1);
    return 0;
}
