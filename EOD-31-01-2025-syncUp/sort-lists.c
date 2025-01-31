#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
    char* cases;
}Node;
Node* createNode(int value,char* cases)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->cases=cases;
    newNode->next=NULL;
    return newNode;
}
Node* insertAtTail(Node* head, int value, char* cases) {
    Node* newNode = createNode(value, cases);
    if (head == NULL) {
        return newNode;
    }
    Node* currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next=newNode;
    return head;
}
void printNode(Node* head)
{
    while(head!=NULL)
    {
        printf("%d %s ",head->data,head->cases);
        head=head->next;
    }
}
Node* mergeNodes(Node* criticalNode,Node* seriousNode, Node* stableNode)
{
    Node* currentNode=criticalNode;
    if (currentNode!=NULL) {
    
        while (currentNode->next!=NULL) {
            currentNode=currentNode->next;
        }
        currentNode->next=seriousNode;
    } else {
        criticalNode=seriousNode; 
    }
    currentNode=seriousNode;
    if (currentNode!=NULL) {
        while (currentNode->next!=NULL) {
            currentNode=currentNode->next;
        }
        currentNode->next=stableNode;
    } else if (criticalNode!=NULL) {
        
        currentNode=criticalNode;
        while (currentNode->next!=NULL) {
            currentNode=currentNode->next;
        }
        currentNode->next=stableNode;
    }
    return currentNode;
}

int main()
{
    Node* criticalNode=NULL;
    Node* seriousNode=NULL;
    Node* stableNode=NULL;
    Node* headNode=NULL;
    int noOfPatients;
    scanf("%d",&noOfPatients);
    int index=0;
    while(index<noOfPatients)
    {
        char cases[100];
        int value;
        scanf("%d %[^\n]",&value,cases);
         if (strcmp(cases, "Critical") == 0) {
            criticalNode= insertAtTail(criticalNode,value,"Critical");
        } else if (strcmp(cases, "Serious") == 0) {
            seriousNode= insertAtTail(seriousNode,value,"Serious");
        } else if (strcmp(cases, "Stable") == 0) {
            stableNode= insertAtTail(stableNode, value,"Stable");
        }
        index++;
    }
    headNode=mergeNodes(criticalNode,seriousNode,stableNode);
    printNode(criticalNode);
    return 0;

}