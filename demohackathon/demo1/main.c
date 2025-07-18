#include <stdio.h>
#include <stdlib.h>
//buoc 1: xay dung cau truc du lieu can thiet
//cau truc khoa hoc
typedef struct Course {
    int id;
    char title[20];
    int credits;
}Course;
//cau truc cua node
typedef struct SingleNode {
    Course course;
    struct SingleNode *next;
}SingleNode;
//cau truc lien ket doi
typedef struct DoubleNode {
    Course course;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;

//b3: Xu li yeu cau so 1
//3.1 xay dung ham khoi tao trong danh sach lk don
SingleNode *createSingleNode(Course course) {
    SingleNode *node = (SingleNode *)malloc(sizeof(SingleNode));
    if (node == NULL) {
        return NULL;
    }
    node->course = course;
    node->next = NULL;
    return node;

}
//3.2 xay dung ham node them vao cuoi dslk don
SingleNode *inserstSingleNode(SingleNode *head , Course course) {
    //b1: khoi tao node can them
    SingleNode *newNode = createSingleNode(course);
    //b2:Xu ly dsach trong
    if (head == NULL) {
        head = newNode;
        return head;
    }
    //b3:duyet den cuoi danh sach
    SingleNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    //b4:cap nhap con tro cua node cuoi
    temp->next = newNode;
    return head;
}
//b4: yeu cau so 2:hien thi dslk

void displaySingleNode(SingleNode *head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    SingleNode *temp = head;
    while (temp != NULL) {
        printf("Course ID: %d\n", temp->course.id);
        printf("Title: %s\n", temp->course.title);
        printf("Credits: %d\n", temp->course.credits);
        temp = temp->next;
    }

}
//b5:xu ly yeu cau so3:Xoa khoa hoc
SingleNode *deleteSingleNode(SingleNode *head,int id) {
    SingleNode *temp = head;
    //ktra ds trong
    if (temp == NULL) {
        printf("Empty List\n");
        return NULL;
    }
    //duyet den node co id hoac duyet het danh sach
    SingleNode *prev = NULL;

    //duyet den node co id thi thong bao va ket thuc
    while (temp != NULL && temp->course.id != id) {
        prev = temp;
        temp = temp->next;
    }
    // neu tim thay cos id thi cap nhap con tro next cua con tro truoc do
    if (temp == NULL) {
        printf("ko tim thay\n");
        return head;
    }
    //neu temp = head
    if (temp == head) {
        head = head->next;
        free(temp);
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}
//b6 yeu cau so4:cap nhap
void updateCourse(SingleNode *head , int id) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    SingleNode *temp = head;
    while (temp != NULL && temp->course.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("ko tim thay\n");
        return;
    }
    printf("Course ID: %d\n", temp->course.id);
    printf("Old Title: %s\n", temp->course.title);
    printf("Old Credits: %d\n", temp->course.credits);
    //nhap thong tin moi
    printf("New Credits: %d\n", temp->course.credits);
    gets(temp->course.title);
    printf("New credits:%d\n");
    scanf("%d", &temp->course.credits);


}

int main(void) {
    int choice;
    //khoi tao 2 dslk
    SingleNode *singleHead = NULL;
    DoubleNode *doubleHead = NULL;
    //b2:xay dung menu
    do {
        printf("1.Them khoa hoc\n") ;
        printf("2.Hien thi danh sach\n") ;
        printf("3.Xoa khoa hoc\n") ;
        printf("4.Cap nhap thong tin\n") ;
        printf("1.Them khoa hoc\n") ;
        printf("1.Them khoa hoc\n") ;
        printf("1.Them khoa hoc\n") ;
        printf("8.thoat\n") ;
        printf("Nhap lua chon:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //b1:khoi tao khoa hoc moi
                Course newCourse;
                printf("Nhap id:") ;
                scanf("%d", &newCourse.id);
                fflush(stdin);
                printf("Nhap title:") ;
                gets(newCourse.title);
                fflush(stdin);
                printf("Nhap credits:") ;
                scanf("%d", &newCourse.credits);
                //b2:goi ham them moi vao dslk don
                singleHead = inserstSingleNode(singleHead, newCourse);
                break;
            case 2:
                displaySingleNode(singleHead);
                break;
            case 3:
                int deleteId;
                printf("Nhap id:") ;
                scanf("%d", &deleteId);
                int delete = deleteSingleNode(singleHead,deleteId);
                break;
            case 4:
                int updateCredits;
                printf("Nhap id:") ;
                scanf("%d", &updateCredits);
                updateCourse(singleHead, updateCredits);
                break;
            case 5:

                break;
            case 6:
                break;

            case 7:
                break;
            case 8:
                break;
            default:
                printf("Invalible Choice");
                break;
        }
    }while (choice != 8);
    return 0;
}