#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE], top = -1;

void push() {
    int n;
    if (top == MAXSIZE - 1)
        printf("\n Stack Overflow");
    else {
        printf("\nEnter an Element: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}

void pop() {
    int n;
    if (top == -1)
        printf("\n Stack is Empty");
    else {
        n = stack[top];
        printf("\nPOPed Element is %d", n);
        top--;
    }
}

void display() {
    int i;
    if (top == -1)
        printf("\n Stack is Empty");
    else {
        printf("\n Elements of Stack");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\n----------STACK MENU----------");
        printf("\n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT");
        printf("\n---------ENTER YOUR CHOICE---------");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    } while (choice != 4);

    return 0;
}
