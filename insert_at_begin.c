#include<stdio.h>
#include<stdlib.h>
//TIme Complexity of insert at begin is = O(1 )
struct node
{
    int data;
    struct node * next;//humesha next node yahi define hoga.
};
void linkedlistraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("Elements are: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node * InsertAtFirst(struct node * head , int data ){
    struct node *ptr=(struct node *)malloc(sizeof (struct node));
ptr->next=head;
ptr->data=data;
return ptr;

}

int main(){
    struct node * head;//humesha linked list ke main nodes,int main mei define hongay.
    struct node * second;
    struct node * third;
    struct node * fourth;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=11;
    head->next=second;
    second->data=69;
    second->next=third;
    third->data=30;
    third->next=fourth;
    fourth->data=16;
    fourth->next=NULL;
    head=InsertAtFirst(head,93);
    linkedlistraversal(head);//head is given kyuki wahi se output start hoga print hona agar,second do gay to head nahi print hoga ans mei
    return 0;
}