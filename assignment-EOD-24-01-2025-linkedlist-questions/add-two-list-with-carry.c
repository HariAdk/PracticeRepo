#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;

} Node;

Node* createNode(int value)
{
    Node* newNode=(Node *)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertNodeAtTail(Node** head, Node** tail)
{
    int value;
    if((*head)==NULL)
    {
        scanf("%d",&value);
        *head=createNode(value);
        *tail=*head;
         return;
    }
       scanf("%d",&value);
       Node* tempNode=createNode(value);
       (*tail)->next=tempNode;
       (*tail)=(*tail)->next;
}

void printList(Node* head)
{
    if(head==NULL)
    {
        printf("NULL");
        return;
    }
    printf("%d",head->data);
    head=head->next;
    while(head!=NULL)
    {
        printf("->%d",head->data);
        head=head->next;
    }
}

Node* sumTwoList(Node*head1,Node*head2,int *carry)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node* temp=sumTwoList(head1->next,head2->next,carry);
    Node* head=createNode((head1->data+head2->data+*carry)%10);
    *carry=(head1->data+head2->data+*carry)/10;
    head->next=temp;
    return head;
}


int main()
{
    Node* head1=NULL;
    Node* tail1=NULL;
    Node* head2=NULL;
    Node* tail2=NULL;
    while(1)
    {
        insertNodeAtTail(&head1,&tail1);
        char ch=getchar();
        if(ch=='\n' || ch==EOF) break;
    }
    while(1)
    {
        insertNodeAtTail(&head2,&tail2);
        char ch=getchar();
        if(ch=='\n' || ch==EOF) break;
    }
    Node*head=NULL;
    int carry=0;
    head=sumTwoList(head1,head2,&carry);
    if(carry!=0)
    {
        Node* temp=createNode(carry);
        temp->next=head;
        head=temp;
    }
    printList(head);
    return 0;
}