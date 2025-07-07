#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** h, int d, int p) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = d;
    if (p == 1) {
        n->next = *h;
        *h = n;
        return;
    }
    struct Node* t = *h;
    for (int i = 1; i < p - 1 && t != NULL; i++) t = t->next;
    if (t == NULL) {
        printf("Invalid position. Node not inserted.\n");
        free(n);
        return;
    }
    n->next = t->next;
    t->next = n;
}

void delete(struct Node** h, int d) {
    struct Node* c = *h, *p = NULL;
    while (c != NULL && c->data != d) {
        p = c;
        c = c->next;
    }
    if (c == NULL) {
        printf("Element not found. Node not deleted.\n");
        return;
    }
    if (p == NULL) *h = c->next;
    else p->next = c->next;
    free(c);
}

int count(struct Node* h) {
    int c = 0;
    struct Node* cNode = h;
    while (cNode != NULL) {
        c++;
        cNode = cNode->next;
    }
    return c;
}

void traverse(struct Node* h) {
    struct Node* cNode = h;
    printf("List: ");
    while (cNode != NULL) {
        printf("%d -> ", cNode->data);
        cNode = cNode->next;
    }
    printf("NULL\n");
}

int search(struct Node* h, int k) {
    struct Node* cNode = h;
    int p = 1;
    while (cNode != NULL) {
        if (cNode->data == k) return p;
        cNode = cNode->next;
        p++;
    }
    return -1;
}

void swap(struct Node* a, struct Node* b) {
    int t = a->data;
    a->data = b->data;
    b->data = t;
}

void Reverse(struct Node** head) {
    struct Node* curr, *prev, *temp;
    prev = NULL;
    curr = *head;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *head = prev;
}

void sort(struct Node* h) {
    int s;
    struct Node* c;
    struct Node* l = NULL;
    if (h == NULL) return;
    do {
        s = 0;
        c = h;
        while (c->next != l) {
            if (c->data > c->next->data) {
                swap(c, c->next);
                s = 1;
            }
            c = c->next;
        }
        l = c;
    } while (s);
}

int main() {
    struct Node* h = NULL;
    int c, d, p, k, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        insert(&h, d, i + 1);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &d);
                printf("Enter position to insert: ");
                scanf("%d", &p);
                insert(&h, d, p);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &d);
                delete(&h, d);
                break;
            case 3:
                printf("Number of nodes: %d\n", count(h));
                break;
            case 4:
                traverse(h);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &k);
                p = search(h, k);
                if (p != -1) printf("Element found at position %d\n", p);
                else printf("Element not found.\n");
                break;
            case 6:
                sort(h);
                printf("List sorted in ascending order.\n");
                break;
            case 7:
                Reverse(&h);
                printf("List reversed.\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
