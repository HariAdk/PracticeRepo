
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1001

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void printList() {
    Node* tempNode = head;
    if (tempNode == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d",tempNode->data);
    tempNode=tempNode->next;

    while (tempNode != NULL) {
        printf("->%d", tempNode->data);
        if (tempNode->next != NULL) {
        }
        tempNode = tempNode->next;
    }
    printf("\n");
}

void convertOddEvenLinkedList() {
    if (head == NULL) {
        return;
    }

    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data % 2 == 1) { 
            if (oddHead == NULL) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        } else {  
            if (evenHead == NULL) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        }
        current = current->next;
    }

    if (evenTail != NULL) {
        evenTail->next = NULL;
    }

    if (oddTail != NULL) {
        oddTail->next = evenHead;
        head = oddHead; 
    } else {
        head = evenHead; 
    }
}

int main() {
    int noOfNodes;
    printf("Enter numbers of nodes:");
    scanf("%d",&noOfNodes);
    int value;
    printf("Enter all %d nodes\n",noOfNodes);
    while (noOfNodes>0) {
        scanf("%d",&value);
        insertAtTail(value);
        noOfNodes--;             
    }
    convertOddEvenLinkedList();
    printList(); 

    return 0;
}
