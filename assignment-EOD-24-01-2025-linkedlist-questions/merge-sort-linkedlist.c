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

void insertNodeAtTail(Node** head, int noOfNodes)
{
    int value;
    if((*head)==NULL && noOfNodes>0)
    {
        scanf("%d",&value);
        *head=createNode(value);
        noOfNodes--;
    }
    Node *tail=*head;
    while(noOfNodes>0)
    {
       scanf("%d",&value);
       Node* tempNode=createNode(value);
       (tail)->next=tempNode;
       (tail)=(tail)->next;
       noOfNodes--;
    }
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

Node* split(Node* head)
{
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        if(fast!=NULL)
        {
            slow=slow->next;
        }
    }
    fast=slow->next;
    slow->next=NULL;
    return fast;
}

Node* merge(Node* first, Node* second)
{
    if(first==NULL) return second;
    if(second==NULL) return first;

    if(first->data < second->data)
    {
        first->next=merge(first->next,second);
        return first;
    }
    else{
        second->next=merge(first,second->next);
        return second;
    }
}

Node* mergeSort(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* second=split(head);
    head= mergeSort(head);
    second=mergeSort(second);
    return merge(head,second);
}

int main()
{
    Node* head=NULL;
    int noOfNodes;
    int noOfTimesToRotate;
    scanf("%d",&noOfNodes);
    insertNodeAtTail(&head,noOfNodes);
    head=mergeSort(head);
    printList(head);
    return 0;
}