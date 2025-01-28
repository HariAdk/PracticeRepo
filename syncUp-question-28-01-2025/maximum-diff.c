#include <stdio.h>
#include <stdlib.h>

void takeInput(int *array,int *arraySize)
{
    while(1)
    {
        if(scanf("%d",&array[*arraySize])!=1) break;
        (*arraySize)++;
        char lastCharacter=getchar();
        if(lastCharacter=='\n' || lastCharacter==EOF) break;
    
    }
}
void countSort(int *array, int arraySize)
{
    int max=0;
    for(int i=0;i<arraySize;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }
    int *countArray=(int *)calloc(max+1,sizeof(int));

    for(int i=0;i<arraySize;i++)
    {
        countArray[array[i]]++;
    }

    for(int i=1;i<=max;i++)
    {
        countArray[i]+=countArray[i-1];
    }

    int *outputArray=(int *)malloc(sizeof(int)*arraySize);
    for(int i=arraySize-1;i>=0;i--)
    {
        outputArray[countArray[array[i]]-1]=array[i];
        countArray[array[i]]--;
    }

    for(int i=0;i<arraySize;i++)
    {
        array[i]=outputArray[i];
    }
}
int findMaxDiff(int *array, int arraySize)
{
    int maxDiff=0;
    for(int i=1;i<arraySize;i++)
    {
        if(array[i]-array[i-1]>maxDiff)
        {
            maxDiff=array[i]-array[i-1];
        }
    }
    return maxDiff;

}

int main()
{
    int *array=(int*)malloc(sizeof(int)*1000);
    int arraySize=0;
    takeInput(array,&arraySize);
    if(arraySize<2)
    {
        printf("0");
        return 0;
    }
    countSort(array,arraySize);
    int maxDiff=findMaxDiff(array,arraySize);
    printf("%d",maxDiff);
    return 0;
}