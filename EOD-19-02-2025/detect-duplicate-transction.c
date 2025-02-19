#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct HashNode{
    int id;
    int transactionId;
    float amount;
    int timestamp;
    struct HashNode* next;
}HashNode;

HashNode** map;

HashNode* createNode(int id,int transationId,float amount, int timestamp)
{
    HashNode* newNode=(HashNode*)malloc(sizeof(HashNode));
    newNode->id=id;
    newNode->transactionId=transationId;
    newNode->amount=amount;
    newNode->timestamp=timestamp;
    newNode->next=NULL;
    return newNode;
}

int hashFunction(int id)
{
    return id%TABLE_SIZE;
}

void insertTransaction(int id, int transactionId, float amount, int timeStamp)
{
   int index=hashFunction(id);
   if(!map[index])
   {
    map[index]=createNode(id,transactionId,amount,timeStamp);
    return;
   }
   HashNode* tempNode=map[index];
   if(tempNode->id==id && tempNode->amount==amount && (tempNode->timestamp-timeStamp>-60 && tempNode->timestamp-timeStamp<60))
    {
        printf("duplicate.\n");
        return;
    }
   while(tempNode->next!=NULL)
   {
    if(tempNode->id==id && tempNode->amount==amount && (tempNode->timestamp-timeStamp>-60 && tempNode->timestamp-timeStamp<60))
    {
        printf("duplicate.\n");
        return;
    }
    tempNode=tempNode->next;
   }
   tempNode->next=createNode(id,transactionId,amount,timeStamp);
}

void printTransaction()
{
  printf("All transiction are:\n");
  for(int i=0;i<TABLE_SIZE;i++)
  {
    HashNode* temp=map[i];
    while(temp!=NULL)
    {
     printf("Id:%d,Transaction Id:%d,Amount:%.2f,timestamp:%d\n",temp->id,temp->transactionId,temp->amount,temp->timestamp);
     temp=temp->next;
    }
  }
}

void menuOption()
{
    while(1)
    {
        int choice;
        printf("Enter 1 to insert-\nEnter 2 to print all transiction-\nEnter 3 to exit-\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            int transactionId,id,timeStamp;
            float amount;
            printf("Enter id,transiction id,amount,timestamp:");
            scanf("%d %d %f %d",&id,&transactionId,&amount,&timeStamp);
            insertTransaction(id,transactionId,amount,timeStamp);
        }
        else if(choice==2)
        {
            printTransaction();
        }
        else if(choice==3)
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
    map=(HashNode**)calloc(TABLE_SIZE,sizeof(HashNode*));
    menuOption();
    return 0;
}