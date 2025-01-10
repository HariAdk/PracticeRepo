#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 50

int stringLength(char* string)
{
    int counter=0;
    while(string[counter]!='\0')
    {
        counter++;
    }
    return counter;
}

bool compareTwoStrings(char* string1,char* string2)
{
    int counter=0;
    if(stringLength(string1)!=stringLength(string2))
    {
        return false;
    }
    while(string1[counter]!='\0')
    {
        if(string1[counter]!=string2[counter])
        {
            return false;
        }
        counter++;
    }
    return true;
}
int main()
{
    char *string1=(char *)malloc(MAX_LENGTH);
    char *string2=(char *)malloc(MAX_LENGTH);
    printf("Enter first string: ");
    *string1='\0';
    *string2='\0';
    scanf("%[^\n]",string1);
    getchar();
    printf("Enter second string: ");
    scanf("%[^\n]",string2);
    getchar();
    bool flag=compareTwoStrings(string1,string2);
    if(flag)
    {
        printf("Two strings are same");
    }
    else{
        printf("Two strings not same");
    }
    return 0;
}