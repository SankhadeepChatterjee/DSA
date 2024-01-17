#include <stdio.h>
#define MAXSIZE 10

int queue[MAXSIZE], rear = -1, front = 0;

void insert();
void delete();
void display();

int main() {
    int choice;
    do {
        printf("\n----------QUEUE MENU----------");
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
    if (rear == MAXSIZE - 1)
        printf("\nQueue is Overflow");
    else {
        printf("Enter an Element: ");
        scanf("%d", &n);
        rear++;
        queue[rear] = n;
    }
}

void display() {
    int i;
    if (front > rear)
        printf("\nQueue is empty");
    else {
        printf("\nQueue Elements are: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

void delete() {
    int n;
    if (front > rear)
        printf("\nQueue is empty");
    else {
        n = queue[front];
        front++;
        printf("Deleted element is %d", n);
    }
}
