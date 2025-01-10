#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void countNoOfDigitsAlphabetSymbol(char *string,int arr[])
{
    int counter=0;
    while(string[counter]!='\0')
    {
        if(string[counter]==' ')
        {
            counter++;
            continue;;
        }
        if((string[counter]>='a' && string[counter]<='z') || (string[counter]>='a' && string[counter]<='z'))
        {
            arr[0]++;
        }
        else if(string[counter]>='0' && string[counter]<='9')
        {
            arr[1]++;
        }
        else {
            arr[2]++;
        }
        counter++;
    }
}

void printNoOfDigitsAlphabetSymbol(int arr[])
{
    printf("No of Alphabets: %d\n",arr[0]);
    printf("No of digits: %d\n",arr[1]);
    printf("No of Sybols: %d\n",arr[2]);
}

void takeInput(char *string)
{   *string='\0';
    scanf("%[^\n]",string);
    getchar();
}

int main()
{
    char *string = (char *)malloc(MAX_LENGTH);
    printf("Enter a string: ");
    takeInput(string);
    int arr[3];
    for(int index=0;index<3;index++)
    {
        arr[index]=0;
    }
    countNoOfDigitsAlphabetSymbol(string,arr);
    printNoOfDigitsAlphabetSymbol(arr);
    free(string);
    return 0;
}