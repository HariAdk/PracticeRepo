#include <stdio.h>
#include <stdlib.h>

void swapNumbers(int *value1, int *value2)
{
    int temp=*value1;
    *value1=*value2;
    *value2=temp;
}
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
void mergeArray(int *array,int start,int mid,int end)
{
    int firstTempArrayLength=mid-start+1;
    int secondTempArrayLength=end-mid;
    int *firstTempArray=(int *)malloc(firstTempArrayLength*sizeof(int));
    int *secondTempArray=(int *)malloc(secondTempArrayLength*sizeof(int));

    for(int index=0;index<firstTempArrayLength;index++)
    {
        *(firstTempArray+index)=*(array+start+index);
    }

    for(int index=0;index<secondTempArrayLength;index++)
    {
        *(secondTempArray+index)=*(array+mid+index+1);
    }

    int firstTempArrayStartIndex=0;
    int secondTempArrayStartIndex=0;
    int arrayStartIndex=start;
    while(firstTempArrayStartIndex<firstTempArrayLength && secondTempArrayStartIndex<secondTempArrayLength)
    {
        if(*(firstTempArray+firstTempArrayStartIndex)>*(secondTempArray+secondTempArrayStartIndex))
        {
            *(array+arrayStartIndex++)=*(secondTempArray+secondTempArrayStartIndex++);
        }
        else{
            *(array+arrayStartIndex++)=*(firstTempArray+firstTempArrayStartIndex++);
        }
    }

    while(firstTempArrayStartIndex<firstTempArrayLength)
    {
        *(array+arrayStartIndex++)=*(firstTempArray+firstTempArrayStartIndex++);
    }
    while(secondTempArrayStartIndex<secondTempArrayLength)
    {
        *(array+arrayStartIndex++)=*(secondTempArray+secondTempArrayStartIndex++);
    }
}

void mergeSort(int *array,int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int mid=start+(end-start)/2;
    mergeSort(array,start,mid);
    mergeSort(array,mid+1,end);
    mergeArray(array,start,mid,end);
}

int main()
{
    int arrayLength;
    scanf("%d",&arrayLength);
    int *array=(int *)malloc(arrayLength*sizeof(int));
    takeInput(array,arrayLength);
    mergeSort(array,0,arrayLength-1);
    printArray(array,arrayLength);
    return 0;
}