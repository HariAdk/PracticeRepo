#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 101

int stringLength(char *string)
{
    int count=1;
    while(string[count]!='\0')
    {
        count++;
    }
    return count;
}

bool checkPalindrome(char *string)
{
    int start=0;
    int end=stringLength(string)-1;
    while(start<end)
    {
        if(string[start++]!=string[end--]) return false;
    }
    return true;
}

int main()
{
    char string[MAX_LENGTH];
    scanf("%[^\n]%*c",string);
    bool check=checkPalindrome(string);
    if(check)
    {
        printf("String is a palindrome.");
    }

    else{
        printf("String is not a palindrome.");
    }
    return 0;
}