#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
int top;
int* stack;

typedef struct HashNode{
    int value;
    struct HashNode* next;
}HashNode;

HashNode* map;

HashNode* createNode(int value)
{
    HashNode* newHashNode=(HashNode*)malloc(sizeof(HashNode));
    newHashNode->value=value;
    newHashNode->next=NULL;
    return newHashNode;
}

void insertBookmark(int page)
{
    if(map==NULL)
    {
        map=createNode(page);
        return;
    }
    if(page<map->value)
    {
        HashNode* tempNode=createNode(page);
        tempNode->next=map;
        map=tempNode;
        return;
    }
    HashNode* tempNode=map;
    while(tempNode->next!=NULL && tempNode->next->value<page)
    {
        tempNode=tempNode->next;
    }
    if(!tempNode->next) {
        tempNode->next=createNode(page);
        return;
    }
    HashNode* curr=tempNode->next;
    tempNode->next=createNode(page);
    tempNode->next->next=curr;
}

void deleteBookmark(int page)
{
    if(map==NULL)
    {
        printf("No Bookmarks\n");
        return;
    }
    HashNode* tempNode=map;
    if(map->value==page)
    {
        HashNode* tempNode=map;
        map=map->next;
        tempNode->next=NULL;
        free(tempNode);
        return;
    }
    while(tempNode->next!=NULL && tempNode->next->value!=page)
    {
        tempNode=tempNode->next;
    }
    if(!tempNode->next)
    {
        printf("No Bookmarks\n");
        return;
    }
    HashNode* curr=tempNode->next;
    tempNode->next=tempNode->next->next;
    curr->next=NULL;
    free(curr);
}

void listAllBookmarks()
{
 HashNode* tempNode=map;
 printf("Pages are:");
 while(tempNode!=NULL)
 {
    printf("%d ",tempNode->value);
    tempNode=tempNode->next;
 }
 printf("\n");
}

void menuOption()
{
    map=NULL;
    int noOfOperations;
    scanf("%d",&noOfOperations);
    getchar();
    while(noOfOperations--)
    {

        char* choose=(char*)malloc(sizeof(char)*20);
        scanf("%[^\n]",choose);
        getchar();
        int page=-1;
        char* option=(char*)malloc(sizeof(char)*20);
        if (choose[0] == 'B') {
            int result = sscanf(choose, "%s %d", option, &page);
            stack[++top]=page;
            insertBookmark(page);
        }
       else if(choose[0]=='D')
        {
            if(top==-1){
                printf("No Bookmarks\n");
                continue;
            }
            int page=stack[top--];
            deleteBookmark(page);
        }
        else if(choose[0]=='E')
        {
            exit(0);
        }
        else if(choose[0]=='L')
        {
            listAllBookmarks();
        }
        
    }
}

int main()
{
    stack=(int*)malloc(sizeof(int)*MAX_SIZE);
    top=-1;
    menuOption();
    return 0;
}
