#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int co;
    int expo;
    struct node* next;
} node;

node* create(int co, int expo) {
    node* n = (node*)malloc(sizeof(node));
    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->co = co;
    n->expo = expo;
    n->next = NULL;
    return n;
}

node* insert(node* head, int co, int expo) {
    node* n = create(co, expo);

    if (head == NULL) {
        return n;
    } else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = n;
        return head;
    }
}

node* add(node* head1, node* head2) {
    node* result = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->expo == head2->expo) {
            result = insert(result, head1->co + head2->co, head1->expo);
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->expo > head2->expo) {
            result = insert(result, head1->co, head1->expo);
            head1 = head1->next;
        } else {
            result = insert(result, head2->co, head2->expo);
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        result = insert(result, head1->co, head1->expo);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        result = insert(result, head2->co, head2->expo);
        head2 = head2->next;
    }

    return result;
}

void display(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->co, current->expo);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(node* head) {
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    node* poly1 = NULL;
    node* poly2 = NULL;
    int n1, n2, co, expo;

    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &co, &expo);
        poly1 = insert(poly1, co, expo);
    }

    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &co, &expo);
        poly2 = insert(poly2, co, expo);
    }

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    node* result = add(poly1, poly2);
    printf("Resultant Polynomial: ");
    display(result);


    return 0;
}
