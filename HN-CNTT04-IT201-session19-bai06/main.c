#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (Node **)malloc(sizeof(Node *));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
int isQueueEmpty(Queue *queue) {
    if (queue->rear == queue->capacity - 1) {
        return 1;
    }
    return 0;
}
void enQueue(Queue *queue, Node *node) {
    if (queue->rear > queue->front ) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = node;
}
void levelOderBFS(Node *root) {
    if (root == NULL) {
        return;
    }
    Queue *queue = createQueue(100);
    enQueue(queue, root);
    while (!isQueueEmpty(queue)) {
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        if (node->left != NULL) {
            enQueue(queue, node->left);
        }
        if (node->right != NULL) {
            enQueue(queue, node->right);
        }

    }

}

int main(void) {
   int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node *root = createNode(n);
    root->left = createNode(n+1);
    root->right = createNode(n+2);
    root->left->left = createNode(n+3);
    levelOderBFS(root);
    return 0;
}