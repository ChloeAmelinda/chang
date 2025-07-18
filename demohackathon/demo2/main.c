#include <stdio.h>
#include <stdlib.h>

//cau truc du lieu can thiet
typedef struct Call {
    char *phone;
    int time;

}Call;
typedef struct Stack {
    Call *calls;
    int top;
    int capacity;
}Stack;
typedef struct Queue {
    Call *calls;
    int front;
    int rear;
    int capacity;
}Queue;
//xay dung ham khoi tao
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->calls = (Call *)malloc(stack->capacity * sizeof(Call));
    return stack;

}
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->calls = (Call *)malloc(queue->capacity * sizeof(Call));
    return queue;
}

//xu ly yeu cau
//ham ktra gioi han
int isStackFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}
int isQueueFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}
//them vao stack
void push(Stack *stack, Call call) {
    if (isStackFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->calls[stack->top] = call;
}

//them vao queue
void enqueue(Queue *queue, Call call) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->calls[queue->rear] = call;
}

//yeu cau 2
int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}
Call pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return ;
    }
    //luu lai gia tri tren dinh stack
    Call call = stack->calls[stack->top];
    stack->top--;
    return call;
}

//hien thi
void displayQueue(Queue *queue) {
    if (queue->front > queue->rear) {
        printf("Queue is full\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%s %d\n", queue->calls[i].phone, queue->calls[i].time);

    }
}


int main(void) {
    int choice;
    Stack *backStack = createStack(10);
    Stack *forwardStack = createStack(10);
    Queue *historyQueue = createQueue(10);
    do {
        printf("1.Call\n");
        printf("2.Back\n");
        printf("3.Redial\n");
        printf("4.History\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //khoi tao yeu cau nguoi dung
                Call newCall;
                printf("Enter the phone number: ");
                scanf("%s", newCall.phone);
                newCall.time = 10;

                //dua cuoc goi vao backStack
                push(backStack, newCall);
                //dua vao historyQueue
                enqueue(historyQueue, newCall);
                break;
            case 2:
                Call *backCall;
                backCall = pop(backStack);
                if (backCall->phone == NULL) {
                    break;

                }
                push(forwardStack, *backCall);

                break;
            case 3:
                Call *forwardCall= pop(forwardStack);
                if (forwardCall == NULL) {
                    break;
                }
                push(backStack, forwardCall);
                enqueue(historyQueue, *forwardCall);

                break;
            case 4:
                displayQueue(historyQueue);
                break;
            case 5:
                printf("EXit\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }while (choice != 5);
    return 0;
}