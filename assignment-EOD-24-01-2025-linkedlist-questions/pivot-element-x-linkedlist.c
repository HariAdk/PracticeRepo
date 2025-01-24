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
    if((*head)==NULL)
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


Node* sortAccToPivot(Node* head, int pivotValue)
{
    Node* NodeToLess=createNode(0);
    Node* NodeToHigh=createNode(0);
    Node* NodeToPivot=createNode(0);

    Node* less=NodeToLess;
    Node* high=NodeToHigh;
    Node* pivot=NodeToPivot;

    while(head!=NULL)
    {
        if(head->data<pivotValue)
        {
            less->next=head;
            less=less->next;
        }
        else if(head->data==pivotValue)
        {
            pivot->next=head;
            pivot=pivot->next;
        }
        else{
            high->next=head;
            high=high->next;
        }
        head=head->next;
    }
    high->next=NULL;
    pivot->next=NodeToHigh->next;
    less->next=NodeToPivot->next;
    return NodeToLess->next;
}

int main()
{
    Node* head=NULL;
    int noOfNodes;
    int pivotValue;
    scanf("%d",&noOfNodes);
    insertNodeAtTail(&head,noOfNodes);
    scanf("%d",&pivotValue);
    head=sortAccToPivot(head,pivotValue);
    printList(head);
    return 0;
}