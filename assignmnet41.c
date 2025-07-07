#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->data = data;
    n->next = NULL;
    return n;
}

Node* insert(Node* head, int data, int pos) {
    Node* n = create(data);

    if (pos == 1) {
        n->next = head;
        return n;
    } else {
        Node* cur = head;
        int c = 1;
        while (cur != NULL && c < pos - 1) {
            cur = cur->next;
            c++;
        }

        if (cur == NULL) {
            printf("Position out of range\n");
            return head;
        }

        n->next = cur->next;
        cur->next = n;
        return head;
    }
}

Node* removeNode(Node* head, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->data == data) {
        Node* t = head;
        head = head->next;
        free(t);
        return head;
    }

    Node* cur = head;
    while (cur->next != NULL && cur->next->data != data) {
        cur = cur->next;
    }

    if (cur->next == NULL) {
        printf("Element not found in the list\n");
    } else {
        Node* t = cur->next;
        cur->next = cur->next->next;
        free(t);
    }

    return head;
}

int count(Node* head) {
    int c = 0;
    Node* cur = head;
    while (cur != NULL) {
        c++;
        cur = cur->next;
    }
    return c;
}

void traverse(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    Node* h = NULL;
    int ch, d, pos, m, x;

    printf("Enter number of nodes: ");
    scanf("%d", &m);

    printf("Enter the elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        h = insert(h, x, i + 1);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &d);
                printf("Enter position: ");
                scanf("%d", &pos);
                h = insert(h, d, pos);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &d);
                h = removeNode(h, d);
                break;
            case 3:
                printf("The total number of nodes: %d\n", count(h));
                break;
            case 4:
                printf("The list is: ");
                traverse(h);
                break;
            
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
