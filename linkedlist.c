#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create();
void display();
void insert();
void search();
void deleteNode();  // Corrected the function name
void insertatbeg();

struct node *start = NULL;

int main() {
    int ch;
    while (1) {
        printf("\n PRESS 1. TO CREATE\n PRESS 2. TO INSERT\n PRESS 3. TO DISPLAY\n PRESS 4. TO SEARCH\n PRESS 5. TO INSERT AT BEGINNING\n PRESS 6. TO DELETE\n PRESS 7. TO EXIT");
        printf("\n ENTER YOUR CHOICE");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                create();
                break;
            }
            case 2: {
                insert();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                search();
                break;
            }
            case 5: {
                insertatbeg();
                break;
            }
            case 6: {
                deleteNode();
                break;
            }
            case 7: {
                exit(0);  // Exiting the program
            }
            default: {
                printf("\n INVALID CHOICE");
            }
        }
    }
    return 0;
}

void create() {
    struct node *n = NULL;
    int key;
    printf("\n ENTER THE INFO FOR NODE");
    scanf("%d", &key);
    if (start == NULL) {
        start = (struct node *)malloc(sizeof(struct node));
        start->data = key;
        start->next = NULL;
    } else {
        for (n = start; n->next != NULL; n = n->next);
        n->next = (struct node *)malloc(sizeof(struct node));
        n->next->data = key;
        n->next->next = NULL;
    }
}

void search() {
    struct node *n = start;  // Added initialization of n
    int key, f = 0;
    printf("ENTER THE NUMBER TO SEARCH");
    scanf("%d", &key);
    for (n = start; n != NULL; n = n->next) {
        if (n->data == key) {
            f = 1;
            break;
        }
    }
    if (f == 0)
        printf("MATCH NOT FOUND");
    else
        printf("\n THE POSITION IS %p", (void *)n);
}

void display() {
    struct node *p;
    p = start;
    while (p != NULL) {
        printf("\n%d", p->data);
        p = p->next;
    }
}

void deleteNode() {
    struct node *n;
    struct node *prev = NULL;  // Added initialization of prev
    int key, f = 0;
    printf("ENTER THE DATA TO DELETE");
    scanf("%d", &key);
    for (n = start; n != NULL; n = n->next) {
        if (n->data == key) {
            f = 1;
            break;
        }
        prev = n;
    }
    if (f == 1) {
        if (prev == NULL) {
            start = n->next;
            free(n);
        } else {
            prev->next = n->next;
            free(n);
        }
        printf("Node with data %d deleted successfully.", key);
    } else
        printf("THE ELEMENT NOT FOUND TO BE DELETED");
    display();
}

void insertatbeg() {
    struct node *newNode;
    int key;
    printf("\n ENTER THE INFO TO ENTER AT THE BEGINNING");
    scanf("%d", &key);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = start;
    start = newNode;
}

void insert() {
    struct node *n = NULL, *newNode;
    int key, f = 0, x;
    printf("\n ENTER THE INFO AFTER WHICH YOU WANT TO INSERT");
    scanf("%d", &key);
    for (n = start; n != NULL; n = n->next) {
        if (n->data == key) {
            f = 1;
            break;
        }
    }
    if (f == 1) {
        printf("\n ENTER DATA FOR NEW NODE");
        scanf("%d", &x);
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = n->next;
        n->next = newNode;
    } else {
        printf("Node with data %d not found for insertion.", key);
    }
}
