//TODO: Add sort function
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void getMethod(int *choice) {
    printf("\n        Menu        \n");
    printf("[1] Add At the End\n");
    printf("[2] Add At the Start\n");
    printf("[3] Insert Sorted\n");
    printf("[4] Delete by Value\n");
    printf("[5] Delete by Position\n");
    printf("[6] Update by Value\n");
    printf("[7] Update by Position\n");
    printf("[8] Display all\n");
    printf("[9] Exit\n");
    
    printf("\nEnter option: ");
    scanf("%d", choice);
}

void addAtEnd(Node *trav) {
    Node *new = malloc(sizeof(Node));
    
    printf("Enter new data: ");
    scanf("%d", &new->data);
    
    new->next = NULL;
    
    while (trav->next != NULL) {
        trav = trav->next;
    }
    
    trav->next = new;
    
    printf("\nData inserted...!\n");
}

void addAtStart(Node *trav) {
    Node *new = malloc(sizeof(Node));
    
    printf("Enter new data: ");
    scanf("%d", &new->data);
    
    new->next = NULL;
    
    new->next = trav->next;
    trav->next = new;
    
    printf("\nData inserted...!\n");
}

void insertSorted(Node *trav) {
    Node *new = malloc(sizeof(Node));
    
    printf("Enter sorted new data: ");
    scanf("%d", &new->data);
    
    new->next = NULL;
    
    while(trav->next != NULL) {
        trav = trav->next;
        if (new->data >= trav->data && new->data <= trav->next->data) {
            new->next = trav->next;
            trav->next = new;
            break;
        }
    }
}

void deleteByValue(Node *trav, int num) {
    Node *temp;
    
    int status = 0;
    
    while (trav->next != NULL) {
        temp = trav;
        trav = trav->next;
        if (trav->data == num) {
            temp->next = trav->next;
            free(trav);
            trav = temp;
            status = 1;
            // break;
        }
    }
    
    if (status) printf("\nData deleted...!\n");
    else printf("\nData does not exist...\n");
}

void deleteByPosition(Node *trav, int index) {
    Node *temp;
    
    for (int i = 1; trav->next != NULL; i++) {
        temp = trav;
        trav = trav->next;
        if (i == index) {
            temp->next = trav->next;
            free(trav);
            break;
        }
    }
}

void updateByValue(Node *trav, int num) {
    while (trav->next != NULL) {
        trav = trav->next;
        if (trav->data == num) {
            printf("\nData found...!\n\n");
            printf("Enter new data: ");
            scanf("%d", &trav->data);
            
            printf("\nData updated.\n");
            
            return;
        }
    }
    printf("Data not found...\n");
}

void updateByPosition(Node *trav, int index) {
    for (int i = 1; trav->next != NULL; i++) {
        trav = trav->next;
        if (i == index) {
            printf("Enter new data: ");
            scanf("%d", &trav->data);
            
            printf("\nData updated.\n");
            
            return;
        }
    }
    printf("\nList is currently empty...\n");
}

void displayAll(Node *trav) {
    printf("Current list: ");
    while (trav->next != NULL) {
        trav = trav->next;
        printf("%d ", trav->data);
    }
    printf("\n");
}

int main(void) {
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    
    int choice;
    int num;
    int index;

    do {
        getMethod(&choice);
        switch(choice) {
            case 1:
                addAtEnd(head);
                break;
            case 2:
                addAtStart(head);
                break;
            case 3:
                insertSorted(head);
                break;
            case 4:
                printf("Enter value to be deleted: ");
                scanf("%d", &num);
                deleteByValue(head, num);
                break;
            case 5:
                printf("Enter position to be deleted: ");
                scanf("%d", &index);
                deleteByPosition(head, index);
                break;
            case 6:
                printf("Find value to be updated: ");
                scanf("%d", &num);
                updateByValue(head, num);
                break;
            case 7:
                printf("Enter position to be updated: ");
                scanf("%d", &index);
                updateByPosition(head, index);
                break;
            case 8:
                displayAll(head);
                break;
            case 9:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid Input...");
                break;
        }
    } while(choice != 9);

    return 0;
}
