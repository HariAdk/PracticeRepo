#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 2000

int* array;
int size;

typedef struct HashNode{
    int key;
    struct HashNode* next;
}HashNode;

HashNode* createHashNode(int key)
{
    HashNode* newHashNode=(HashNode*)malloc(sizeof(HashNode));
    newHashNode->key=key;
    newHashNode->next=NULL;
    return newHashNode;
}

int hashFunction(int key)
{
   return (key+TABLE_SIZE)%TABLE_SIZE;
}

void insert(HashNode** hashTable,int key)
{
    int index=hashFunction(key);
    if(!hashTable[index])
    {
        hashTable[index]=createHashNode(key);
        return;
    }
    HashNode* tempHashNode=hashTable[index];
    if(tempHashNode->key==key) return;
    while(tempHashNode->next!=NULL && tempHashNode->next->key!=key) tempHashNode=tempHashNode->next;
    if(!tempHashNode->next) tempHashNode->next=createHashNode(key);
}

int search(HashNode** hashTable,int key)
{
    int index=hashFunction(key);
    if(!hashTable[index])
    {
        return 0;
    }
    HashNode* tempHashNode=hashTable[index];
    while(tempHashNode!=NULL && tempHashNode->key!=key) tempHashNode=tempHashNode->next;
    if(!tempHashNode) return 0;
    return 1;
}

void takeInput()
{
    array=(int*)malloc(sizeof(int)*1001);
    size=0;
    while(1)
    {
        scanf("%d",&array[size++]);
        char ch=getchar();
        if(ch=='\n' || ch==EOF) break;
    }
}

void hashArray(HashNode** hashTable)
{
    for(int i=0;i<size;i++)
    {
        insert(hashTable,array[i]);
    }
}

int findLongestSequence(HashNode** hashTable)
{
    int longestSequence=0;
    for(int i=0;i<size;i++)
    {
        int tempLongestSequence=0;
        int j=0;
        while(search(hashTable,array[i]+j)) 
        {
             tempLongestSequence++;
             j++;
        }
        if(tempLongestSequence>longestSequence) longestSequence=tempLongestSequence;
    }
    return longestSequence;
}

int main()
{
    HashNode** hashTable=(HashNode**)calloc(TABLE_SIZE,sizeof(HashNode*));
    takeInput();
    hashArray(hashTable);
    int largestSequence=findLongestSequence(hashTable);
    printf("%d",largestSequence);
    return 0;
}