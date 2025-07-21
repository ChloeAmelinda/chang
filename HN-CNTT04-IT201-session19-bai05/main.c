#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bool search(Node* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    return search(root->left, data) || search(root->right, data);

}
int main(void) {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node* root = createNode(n);
    root->left = createNode(n+1);
    root->right = createNode(n+2);
    root->left->left = createNode(n+3);

    int find =3;
    if (search(root,find)) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}