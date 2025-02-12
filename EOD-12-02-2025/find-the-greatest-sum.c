#include <stdio.h>
#include <stdlib.h>

int convertIntoTwoArray(int* array, int size)
{
    int firstSum=0;
    int secondSum=0;
    if(array[0]<0)
    {
    secondSum+=array[0];
    }
    else{
        firstSum+=array[0];
    }
    for(int i=1;i<size;i++)
    {
     if(array[i]<0 && array[i-1]!=array[i])
     {
        secondSum+=array[i];
        continue;
     }

     else if(array[i]>0 && array[i]==array[i-1])
     {
        secondSum+=array[i];
        continue;
     }
     else{
        firstSum+=array[i];
     }

    }
    return firstSum-secondSum;
}

void swap(int* value1, int* value2)
{
    int temp=*value1;
    *value1=*value2;
    *value2=temp;
}

int findPivot(int* array,int start,int end)
{
    int pivotIndex=start;
    int pivotElement=array[end];
    for(int i=start;i<end;i++)
    {
        if(array[i]<pivotElement)
        {
           swap(&array[i],&array[pivotIndex]);
           pivotIndex++;
        }
    }
    swap(&array[pivotIndex],&array[end]);
    return pivotIndex;
}

void quickSort(int* array,int start, int end)
{
    if(start>=end)
    {
       return;
    }
    int pivot=findPivot(array,start,end);
    quickSort(array,start,pivot-1);
    quickSort(array,pivot+1,end);
}

int main()
{
    int* array=(int*)malloc(sizeof(int)*100);
    int size=0;
    while(1)
    {
       scanf("%d",&array[size++]);
       char ch=getchar();
       if(ch=='\n' || ch==EOF) break;
    }
    quickSort(array,0,size-1);
    int ans=convertIntoTwoArray(array,size);
    printf("%d",ans);
    return 0;
}