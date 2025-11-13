#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create_node(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return create_node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder_traversal(struct Node* root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(struct Node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(struct Node* root)
{
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}
