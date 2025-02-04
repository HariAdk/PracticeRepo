#include <stdio.h>
#include <stdlib.h>

void findLifeSpan(int* array, int *resultArray,int size)
{
    resultArray[0]=1;
    for(int i=1;i<size;i++)
    {
        if(array[i-1]>array[i])
        {
            resultArray[i]=1;
        }
        if(array[i-1]==array[i])
        {
           resultArray[i]=resultArray[i-1]+1;
        }
        else{
            int j=i-1;
            resultArray[i]=1;
            while(j>=0 && array[j]<=array[i])
            {
                resultArray[i]+=resultArray[j];
                j=j-resultArray[j];
            }
        }
    }
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
    int* resultArray=(int*)malloc(sizeof(int)*size);
    findLifeSpan(array,resultArray,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",resultArray[i]);
    }
    return 0;
}