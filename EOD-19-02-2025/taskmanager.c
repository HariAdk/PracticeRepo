#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
    int status;
    char* task;
    struct Node* next;
}Node;

Node* taskManager;

Node* createNode(char* task)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->task=(char*)malloc(sizeof(char)*20);
    newNode->task=task;
    newNode->status=1;
    newNode->next=NULL;
    return newNode;
}

void addTask(char* task)
{
    if(taskManager==NULL)
    {
        taskManager=createNode(task);
        return;
    }
    Node* tempNode=taskManager;
    while(tempNode->next!=NULL)
    {
        tempNode=tempNode->next;
    }
    tempNode->next=createNode(task);
}

void updateTaskStatus(char* task)
{
    if(taskManager==NULL)
    {
        printf("No task found.\n");
        return;
    }
    Node* tempNode=taskManager;
    while(tempNode!=NULL && strcmp(tempNode->task,task)!=0)
    {
      tempNode=tempNode->next;
    }
    if(!tempNode)
    {
        printf("No task found.\n");
        return;
    }
    tempNode->status=0;
}

void printPendingTask()
{
    printf("All pending tasks are:");
    Node* tempNode=taskManager;
    while(tempNode)
    {
        if(tempNode->status==1)
        printf(" %s",tempNode->task);
        tempNode=tempNode->next;
    }
    printf("\n");
}

void toLower(char* task)
{
    while(*task!='\0')
    {
        if(*task>='A' && *task<='Z')
        {
            *task='a'+(*task-'A');
        }
        task++;
    }
}

void menuOption()
{
    int noOfOperations;
    scanf("%d",&noOfOperations);
    getchar();
    char* command=(char*)malloc(sizeof(char)*100);
    while(noOfOperations--)
    {
        scanf("%[^\n]",command);
        getchar();
        
        if(command[0]=='A')
        {
            char* task=(char*)malloc(sizeof(char)*20);
            sscanf(command, "%*s %s", task);
            toLower(task);
            addTask(task);
        }
        else if(command[0]=='C')
        {
            char* task=(char*)malloc(sizeof(char)*20);
            sscanf(command, "%*s %s", task);
            toLower(task);
            updateTaskStatus(task);
            
        }
        else if(command[0]=='P')
        {
          printPendingTask();
        }
        else if(command[0]=='E')
        {
            return;
        }
        else{
            printf("Invalid Choice!\n");
        }

    }
}

int main()
{
    taskManager=NULL;
    menuOption();
    return 0;
}