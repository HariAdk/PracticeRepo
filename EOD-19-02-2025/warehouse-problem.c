// Enter no of commands
// Add <item> <quantity>-- to add addItem and its quantity
// Update <item> <quantity>-- to update its quantity
// Query <item>-- print quantity of item>print "no item present" if it is not present
//Exit to exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct HashNode{
    char* item;
    int quantity;
    struct HashNode* next;
}HashNode;

HashNode** map;

int hashFunction(char* item)
{
  int index=0;
  char* tempChar=item;
  while(*tempChar!='\0')
  {
    index+=*tempChar-'a';
    tempChar++;
  }
  index=index%TABLE_SIZE;
  return index;
}

HashNode* createNode(char* item, int value)
{
    HashNode* newNode=(HashNode*)malloc(sizeof(HashNode));
    newNode->item=(char*)malloc(sizeof(char)*20);
    newNode->item=item;
    newNode->quantity=value;
    newNode->next=NULL;
    return newNode;
}

void addItem(char* item,int value)
{
    int index=hashFunction(item);
    if(!map[index])
    {
        map[index]=createNode(item,value);
        return;
    }
    HashNode* temp=map[index];
    while(temp->next!=NULL && strcmp(temp->item,item)!=0)
    {
        temp=temp->next;
    }
    if(strcmp(temp->item,item)==0)
    {
        temp->quantity+=value;
        return;
    }
    temp->next=createNode(item,value);
}

void updateItem(char* item,int quantity)
{
    int index=hashFunction(item);
    if(!map[index])
    {
        printf("No item present\n");
        return;
    }
    HashNode* temp=map[index];
    while(temp!=NULL && strcmp(temp->item,item)!=0)
    {
        temp=temp->next;
    }
    if(!temp)
    {
        printf("No item present\n");
        return;
    }
    temp->quantity=quantity;
}

void queryItem(char* item)
{
    int index=hashFunction(item);
    if(!map[index])
    {
        printf("No item present\n");
        return;
    }
    HashNode* temp=map[index];
    while(temp!=NULL && strcmp(temp->item,item)!=0)
    {
        temp=temp->next;
    }
    if(!temp)
    {
        printf("No item present\n");
        return;
    }
    printf("%s:%d\n",item,temp->quantity);
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
            char* item=(char*)malloc(sizeof(char)*20);
            int quantity;
            sscanf(command, "%*s %s %d", item, &quantity);
            addItem(item,quantity);
        }
        else if(command[0]=='U')
        {
            char* item=(char*)malloc(sizeof(char)*20);
            int quantity;
            sscanf(command, "%*s %s %d", item, &quantity);
            updateItem(item,quantity);
        }
        else if(command[0]=='Q')
        {
            char* item=(char*)malloc(sizeof(char)*20);
            sscanf(command, "%*s %s", item);
            queryItem(item);
        }
        else if(command[0]=='E')
        {
            exit(0);
        }
        else{
            printf("Invalid Choice!\n");
        }

    }
}

int main()
{
    map=(HashNode**)calloc(TABLE_SIZE,sizeof(HashNode*));
    menuOption();
    return 0;
}