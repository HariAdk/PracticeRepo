#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void takeInput(int *array,int arrayLength)
{
    for(int index=0;index<arrayLength;index++)
    {
        scanf("%d",array+index);
    }
}
void printArray(int *array,int arraySize)
{
    int index=0;
    while(index<arraySize)
    {
        printf("%d ",*(array+index));
        index++;
    }
}

void bubbleSort(int *array,int arrayLength)
{
    for(int firstIndex=0;firstIndex<arrayLength-1;firstIndex++)
    {
        bool isSwap=false;
       for(int secondIndex=0;secondIndex<arrayLength-firstIndex-1;secondIndex++)
       {
        if(*(array+secondIndex)>*(array+secondIndex+1))
        {
            isSwap=true;
            swapNumbers((array+secondIndex),(array+secondIndex+1));
        }
       }
       if(!isSwap)
       {
        return;
       }
    }
}
int main()
{
    int arrayLength;
    scanf("%d",&arrayLength);
    int *array=(int *)malloc(arrayLength*sizeof(int));
    takeInput(array,arrayLength);
    bubbleSort(array,arrayLength);
    printArray(array,arrayLength);
    return 0;
}