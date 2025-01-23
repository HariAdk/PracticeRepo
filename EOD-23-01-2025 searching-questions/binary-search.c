#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inputArray(int array[],int arrayLength)
{
    for(int row=0;row<arrayLength;row++)
    {
        scanf("%d",&array[row]);
    }
}
int compare(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
void printArray(int array[],int arrayLength)
{
    for(int row=0;row<arrayLength;row++)
    {
       printf("%d ",array[row]);
    }
    printf("\n");
}
bool binarySearch(int array[],int arrayLength,int key)
{
    int start=0;
    int end=arrayLength-1;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(array[mid]==key)
        {
            return true;
        }
        else if(array[mid]<key)
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return false;
}

int main()
{
    int arrayLength;
    int key;
    printf("Enter the length of an array:");
    scanf("%d",&arrayLength);
    int array[arrayLength];
    inputArray(array,arrayLength);
    qsort(array,arrayLength,sizeof(int),compare);
    printArray(array,arrayLength);
    printf("Enter the value you want to search:");
    scanf("%d",&key);
    bool isKeyPresent=binarySearch(array,arrayLength,key);
    if(!isKeyPresent)
    {
        printf("Key is not present");
        return 0;
    }
    printf("Key is present");
    return 0;
}