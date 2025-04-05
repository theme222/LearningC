#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node 
{
    int value;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
}
Node;

typedef struct BST
{
    Node *root;
} 
BST;

void Visualize(Node *root) // DFS visualization
{
    if (root == NULL) return;
    printf("%d\n", root->value);
    Visualize(root->left);
    Visualize(root->right);
}

Node* InitializeNode(int value)
{
    printf("Initializing node with value %d\n", value);
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void AddNode(Node *node, BST* tree)
{
    printf("Adding node with value %d\n", node->value);
    Node *root = tree->root;
    Node *prevroot = NULL;
    while (root != NULL)
    {
        puts("running");
        prevroot = root;
        if (node->value > root->value) root = root->right;
        else root = root->left;
    }
    if (prevroot == NULL) tree->root = node;
    else if (node->value > prevroot->value) prevroot->right = node;
    else prevroot->left = node;
    node->parent = prevroot;
}

Node* FindNode(int value, BST* tree)
{
    Node* currentNode = tree->root;
    while (currentNode != NULL)
    {
        if (currentNode->value > value) currentNode = currentNode->left;
        else if (currentNode->value == value) return currentNode;
        else currentNode = currentNode->right;
    }
    return NULL;
}

Node* FindSuccessor(Node* node)
{
    Node* prevNode = NULL;
    node = node->right;
    while (node != NULL)
    {
        prevNode = node;
        node = node->left;
    }
    return prevNode;
}

int IsRightChild(Node *child)
{
    if (child->parent->right == child) return 1;
    return 0;
}

void Transplant(Node *before, Node* after, BST* tree) // Sets the parent's child to be after and sets after's parent to be before's parent
{
    if (tree->root == before) 
    {
        tree->root = after;
    }
    else if (IsRightChild(before))
    {
        before->parent->right = after;
    }
    else 
    {
        before->parent->left = after;
    }
    after->parent = before->parent;
}

void DeleteNode(Node *node, BST* tree)
{
    if (node == NULL)
    {
        puts("Node is null (Value not found)");
        return;
    }
    if (node->left == NULL && node->right == NULL)
    {
        puts("condition 0");
        if (node == tree->root) tree->root = NULL;
        else if (IsRightChild(node)) node->parent->right = NULL;
        else node->parent->left = NULL;
    }
    else if (node->left == NULL && node->right != NULL)
    {
        puts("condition 1");
        Transplant(node, node->right, tree);
    }
    else if (node->right == NULL && node->left != NULL)
    {
        puts("condition 2");
        Transplant(node, node->left, tree);
    }
    else // Both left and right child exist
    {
        puts("condition 3");
        Node* successor = FindSuccessor(node);
        printf("successor is %d\n", successor->value);
        if (successor->parent != node)
        {
            successor->parent->left = successor->right;
            if (successor->right != NULL) successor->right->parent = successor->parent;
            successor->right = node->right;
            if (node->right != NULL) node->right->parent = successor;
        }
        Transplant(node, successor, tree);
        successor->left = node->left;
        if (node->left != NULL) node->left->parent = successor;
    }
    free(node);
}

void DeleteTree(BST* tree)
{
    while (tree->root != NULL)
    {
        DeleteNode(tree->root, tree);
    }
    free(tree);
}

int main()
{
    BST* tree = malloc(sizeof(BST));
    tree->root = NULL;
    int value;

    puts("Binary search tree\nINSERT MODE");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1) break;
        Node *node = InitializeNode(value);
        AddNode(node, tree);
        puts("---");
        Visualize(tree->root);
    }
    puts("DELETE MODE");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1) break;
        DeleteNode(FindNode(value, tree), tree);
        puts("---");
        Visualize(tree->root);
    }
    DeleteTree(tree);
}










