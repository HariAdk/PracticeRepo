#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node* prev;
}Node;

Node* createNode(int value)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("Memory cannot assigned!\n");
        return NULL;
    }
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertAtTail(Node** head,Node** tail,int value)
{
    if(*head==NULL)
    {
        *head=createNode(value);
        *tail=*head;
        return;
    }
    Node* tempNode=createNode(value);
    (*tail)->next=tempNode;
    tempNode->prev=(*tail);
    (*tail)=(*tail)->next;
}

void printList(Node* head)
{
    if(head==NULL)
    {
        printf("NULL\n");
    }
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void reverse(Node** head,Node* previousNode,Node* currentNode)
{
    if(currentNode==NULL)
    {
        return;
    }
    if(currentNode->next==NULL)
    {
        (*head)=currentNode;
        currentNode->prev=NULL;
        currentNode->next=previousNode;
        return;
    }
    reverse(head,currentNode,currentNode->next);
    currentNode->next=previousNode;
    if(previousNode!=NULL)
    previousNode->prev=currentNode;
}
 
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    while(1)
    {
        int value;
        scanf("%d",&value);
        insertAtTail(&head,&tail,value);
        char ch=getchar();
        if(ch=='\n' || ch==EOF) break;
    }
    printList(head);
    reverse(&head,NULL,head);
    printList(head);

    return 0;
}