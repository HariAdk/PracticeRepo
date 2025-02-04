#include <stdio.h>
#include <stdlib.h>

void takeInput(int *array,int arrayLength)
{
    for(int index=0;index<arrayLength;index++)
    {
        scanf("%d",array+index);
    }
}
void swapNumbers(int *value1, int *value2)
{
    int temp=*value1;
    *value1=*value2;
    *value2=temp;
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
 void selectionSort(int *array, int arrayLength)
 {
    for(int outerIndex=0;outerIndex<arrayLength-1;outerIndex++)
    {
        int minIndex=outerIndex;

        for(int innerIndex=outerIndex+1;innerIndex<arrayLength;innerIndex++)
        {
            if(*(array+innerIndex) < *(array+minIndex))
            {
                minIndex=innerIndex;
            }
        }
        swapNumbers(array+minIndex,array+outerIndex);
    }
 }

int main()
{
    int arrayLength;
    scanf("%d",&arrayLength);
    int *array=(int *)malloc(arrayLength*sizeof(int));
    takeInput(array,arrayLength);
    selectionSort(array,arrayLength);
    printArray(array,arrayLength);
    return 0;
}