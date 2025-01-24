#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100

void printArray(int array[],int arraySize)
{
    for(int i=0;i<arraySize;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
void convertStringToArray(int array[],char* string,int *arraySize)
{
    int index=0;
    while(*string!='\0' && *string!=']')
    {
        if(*string==',' || *string=='[')
        {
            string++;
            continue;
        }
        int value=0;
        while(*string!='\0' && *string!=',' && *string!=']')
        {
            value=value*10+(*(string)-'0');
            string++;
        }
        array[index++]=value;
    }
    *arraySize=index;
}
bool checkSum(int output[],int outputSize,int pivotValue)
{
    int sum=0;
    for(int i=0;i<outputSize;i++)
    {
        sum+=output[i];
    }
    if(sum==pivotValue)
    {
        return true;
    }
    return false;
}

void printSubsets(int arr[], int arraySize, int output[], int outputSize, int currentIndex,int pivotValue) {
    if(checkSum(output,outputSize,pivotValue))
    {
        printArray(output, outputSize);
        return;
    }
        for(int i=currentIndex;i<arraySize;i++){
        output[outputSize] = arr[i];
        printSubsets(arr, arraySize, output, outputSize+1, i+1,pivotValue);
    }
}
int main()
{
    int array[MAX_SIZE];
   char string[MAX_SIZE];
   int arraySize=0;
   int pivotValue;
   scanf("%[^\n]",string);
   convertStringToArray(array,string,&arraySize);
   scanf("%d",&pivotValue);
   int output[arraySize];
   printSubsets(array,arraySize,output,0,0,pivotValue);
    return 0;
}