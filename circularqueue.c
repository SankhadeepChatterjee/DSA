#include <stdio.h>
#define MAXSIZE 10

int cqueue[MAXSIZE], rear = -1, front = -1;

void insert();
void delete();
void display();

int main() {
    int choice;
    do {
        printf("\n----------CIRCULAR QUEUE MENU----------");
        printf("\n 1.Insert \n 2.Delete \n 3.DISPLAY \n 4.EXIT");
        printf("\n---------ENTER YOUR CHOICE---------");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 4);

    return 0;
}

void insert() {
    int n;
    if ((rear + 1) % MAXSIZE == front)
        printf("\n Queue is overflow");
    else {
        printf("\n Enter a Number: ");
        scanf("%d", &n);
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else
            rear = (rear + 1) % MAXSIZE;
        cqueue[rear] = n;
    }
}

void display() {
    int i;
    if (front == -1 && rear == -1)
        printf("\n Queue is Empty");
    else {
        printf("\n Elements of queue: ");
        for (i = front; i != rear; (i = (i + 1) % MAXSIZE)) {
            printf("%d ", cqueue[i]);
        }
        printf("%d", cqueue[i]);
    }
}

void delete() {
    int n;
    if (front == -1 && rear == -1)
        printf("\n Queue is Empty");
    else {
        n = cqueue[front];
        printf("\n Deleted Element is %d", n);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAXSIZE;
        }
    }
}
