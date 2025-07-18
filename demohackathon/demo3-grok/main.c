#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Course structure
typedef struct Course {
    int id;
    char title[100]; // Increased to match requirement
    int credits;
} Course;

// Singly Linked List Node
typedef struct SingleNode {
    Course course;
    struct SingleNode *next;
} SingleNode;

// Doubly Linked List Node
typedef struct DoubleNode {
    Course course;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;

// Create single node
SingleNode *createSingleNode(Course course) {
    SingleNode *node = (SingleNode *)malloc(sizeof(SingleNode));
    if (!node) return NULL;
    node->course = course;
    node->next = NULL;
    return node;
}

// Create double node
DoubleNode *createDoubleNode(Course course) {
    DoubleNode *node = (DoubleNode *)malloc(sizeof(DoubleNode));
    if (!node) return NULL;
    node->course = course;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Insert to singly linked list (end)
SingleNode *insertSingleNode(SingleNode *head, Course course) {
    SingleNode *newNode = createSingleNode(course);
    if (!head) return newNode;
    SingleNode *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Insert to doubly linked list (end)
DoubleNode *insertDoubleNode(DoubleNode *head, Course course) {
    DoubleNode *newNode = createDoubleNode(course);
    if (!head) return newNode;
    DoubleNode *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Display singly linked list
void displaySingleNode(SingleNode *head) {
    if (!head) {
        printf("Empty List\n");
        return;
    }
    SingleNode *temp = head;
    while (temp) {
        printf("ID: %d, Title: %s, Credits: %d\n", temp->course.id, temp->course.title, temp->course.credits);
        temp = temp->next;
    }
}

// Delete from singly linked list by ID
SingleNode *deleteSingleNode(SingleNode *head, int id) {
    if (!head) {
        printf("Empty List\n");
        return NULL;
    }
    SingleNode *temp = head, *prev = NULL;
    while (temp && temp->course.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("ID %d not found\n", id);
        return head;
    }
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    return head;
}

// Update course by ID
void updateCourse(SingleNode *head, int id) {
    if (!head) {
        printf("Empty List\n");
        return;
    }
    SingleNode *temp = head;
    while (temp && temp->course.id != id) temp = temp->next;
    if (!temp) {
        printf("ID %d not found\n", id);
        return;
    }
    printf("Old Title: %s, Credits: %d\n", temp->course.title, temp->course.credits);
    printf("New Title: ");
    getchar(); // Clear newline
    fgets(temp->course.title, 100, stdin);
    temp->course.title[strcspn(temp->course.title, "\n")] = 0;
    printf("New Credits: ");
    scanf("%d", &temp->course.credits);
    printf("Course updated\n");
}

// Mark course as completed (move to doubly linked list)
SingleNode *markCompleted(SingleNode *head, DoubleNode **doubleHead, int id) {
    if (!head) {
        printf("Empty List\n");
        return NULL;
    }
    SingleNode *temp = head, *prev = NULL;
    while (temp && temp->course.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("ID %d not found\n", id);
        return head;
    }
    *doubleHead = insertDoubleNode(*doubleHead, temp->course);
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Course marked completed\n");
    return head;
}

// Sort singly linked list by credits (bubble sort)
void sortCourses(SingleNode *head) {
    if (!head || !head->next) return;
    int swapped;
    SingleNode *cur, *last = NULL;
    do {
        swapped = 0;
        cur = head;
        while (cur->next != last) {
            if (cur->course.credits > cur->next->course.credits) {
                Course temp = cur->course;
                cur->course = cur->next->course;
                cur->next->course = temp;
                swapped = 1;
            }
            cur = cur->next;
        }
        last = cur;
    } while (swapped);
    printf("Courses sorted by credits\n");
}

// Search courses by title
void searchCourse(SingleNode *head) {
    char title[100];
    printf("Enter title to search: ");
    getchar();
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0;
    int found = 0;
    SingleNode *temp = head;
    while (temp) {
        if (strstr(temp->course.title, title)) {
            printf("ID: %d, Title: %s, Credits: %d\n", temp->course.id, temp->course.title, temp->course.credits);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("No courses found\n");
}

// Free singly linked list
void freeSingleList(SingleNode *head) {
    SingleNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Free doubly linked list
void freeDoubleList(DoubleNode *head) {
    DoubleNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;
    SingleNode *singleHead = NULL;
    DoubleNode *doubleHead = NULL;
    do {
        printf("1. Them khoa hoc\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Cap nhap thong tin\n");
        printf("5. Danh dau hoan thanh\n");
        printf("6. Sap xep khoa hoc\n");
        printf("7. Tim kiem khoa hoc\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Course newCourse;
                printf("Nhap ID: ");
                scanf("%d", &newCourse.id);
                getchar();
                printf("Nhap title: ");
                fgets(newCourse.title, 100, stdin);
                newCourse.title[strcspn(newCourse.title, "\n")] = 0;
                printf("Nhap credits: ");
                scanf("%d", &newCourse.credits);
                singleHead = insertSingleNode(singleHead, newCourse);
                break;
            }
            case 2:
                displaySingleNode(singleHead);
                break;
            case 3: {
                int id;
                printf("Nhap ID: ");
                scanf("%d", &id);
                singleHead = deleteSingleNode(singleHead, id);
                break;
            }
            case 4: {
                int id;
                printf("Nhap ID: ");
                scanf("%d", &id);
                updateCourse(singleHead, id);
                break;
            }
            case 5: {
                int id;
                printf("Nhap ID: ");
                scanf("%d", &id);
                singleHead = markCompleted(singleHead, &doubleHead, id);
                break;
            }
            case 6:
                sortCourses(singleHead);
                break;
            case 7:
                searchCourse(singleHead);
                break;
            case 8:
                freeSingleList(singleHead);
                freeDoubleList(doubleHead);
                printf("Thoat\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (choice != 8);
    return 0;
}