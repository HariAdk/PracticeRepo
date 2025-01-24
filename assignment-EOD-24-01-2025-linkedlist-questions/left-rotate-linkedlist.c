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

void rotateList(Node** head, int noOfTimesToRotate)
{
    if((*head)==NULL || (*head)->next==NULL)
    {
        return;
    }
    Node* tail=*head;
    while(tail->next!=NULL)
    {
       tail=tail->next;
    }
    tail->next=*head;
    while(noOfTimesToRotate>0)
    {
        (*head)=(*head)->next;
        noOfTimesToRotate--;
    } 
    while(tail->next!=*head)
    {
      tail=tail->next;
    }
    tail->next=NULL;
}

int main()
{
    Node* head=NULL;
    int noOfNodes;
    int noOfTimesToRotate;
    scanf("%d",&noOfNodes);
    insertNodeAtTail(&head,noOfNodes);
    scanf("%d",&noOfTimesToRotate);
    rotateList(&head,noOfTimesToRotate);
    printList(head);
    return 0;
}