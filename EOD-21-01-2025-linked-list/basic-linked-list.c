#include <stdio.h>
#include <string.h>
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

void insertAtTailUsingArray(int valueArr[], int counter) {
    if (counter == 0) {
        return;
    }

    head = createNode(valueArr[0]);
    Node* currentNode = head;

    for (int i = 1; i < counter; i++) {
        Node* tempNode = createNode(valueArr[i]);
        currentNode->next = tempNode;
        currentNode = tempNode;
    }
}

void convertStringToLinkedList(char* inputString) {
    int valueArr[MAX_SIZE];
    int counter = 0;

    while (*inputString != '\0') {
        if (*inputString == ' ') {
            inputString++;
            continue;
        }

        int value = 0;
        bool negative = false;

        if (*inputString == '-') {
            negative = true;
            inputString++;
        }

        while (*inputString != '\0' && *inputString != ' ') {
            value = value * 10 + (*inputString - '0');
            inputString++;
        }

        if (negative) {
            value = -value;
        }

        valueArr[counter] = value;
        counter++;
    }
    insertAtTailUsingArray(valueArr, counter);
}

void printList() {
    Node* tempNode=head;
    if (tempNode == NULL) {
        printf("NULL\n");
        return;
    }

    while (tempNode != NULL) {
        printf("%d", tempNode->data);
        if (tempNode->next != NULL) {
            printf(" ");
        }
        tempNode = tempNode->next;
    }
    printf("\n");
}
int main() {
    char inputString[MAX_SIZE];
    scanf("%[^\n]", inputString);
    getchar();  
    convertStringToLinkedList(inputString);
    printList();
    return 0;
}
