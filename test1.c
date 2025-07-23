#include<stdio.h>
#include <stdlib.h>


struct Node {
    int rollNo;
    char name[50];
    struct Node* next;
};

struct Node* createNode(int rollNo, const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}


struct Node* deleteEvenNodes(struct Node* head) {
    struct Node *current = head, *prev = NULL;

    while (current != NULL) {
        if (current->rollNo % 2 == 0) {
            if (prev == NULL) {
                head = current->next;
                free(current);
                current = head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}


void traverseReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }

    traverseReverse(head->next);
    printf("Roll No: %d, Name: %s\n", head->rollNo, head->name);
}

int main() {
   
    struct Node* head = createNode(1, "John");
    head->next = createNode(2, "Alice");
    head->next->next = createNode(3, "Bob");
    head->next->next->next = createNode(4, "Eve");

    
    head = deleteEvenNodes(head);

   
    printf("Linked List after deleting even roll numbers:\n");
    traverseReverse(head);

    
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


