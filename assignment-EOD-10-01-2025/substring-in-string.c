#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void takeInput(char *string)
{   *string='\0';
    scanf("%[^\n]",string);
    getchar();
}

int stringLength(char* string)
{
    int counter=0;
    while(string[counter]!='\0')
    {
        counter++;
    }
    return counter;
}

bool compareTwoStrings(char* string1,char* string2,int length)
{
    int counter=0;
    while(string1[counter]!='\0' && counter<length)
    {
        if(string2[counter]!=' ' && string1[counter]!=string2[counter])
        {
            return false;
        }
        counter++;
    }
    return true;
}

bool checkForSubstring(char *mainString,char *subString)
{
   int subStringlength=stringLength(subString);
   int counter=0;
   if(subStringlength>stringLength(mainString))
   {
    return false;
   }
   char *tempString=&mainString[counter];
   while(stringLength(tempString)>=subStringlength)
   {
      if(compareTwoStrings(tempString,subString,subStringlength))
      {
        return true;
      }
      counter++;
      tempString=&mainString[counter];
   }
   return false;
}

void printIsSubStringIsPresent(bool isSubStringIsPresent)
{
    if(isSubStringIsPresent)
    {
        printf("true");
    }
    else{
        printf("false");
    }
}

int main()
{
    char *mainString= (char *)malloc(MAX_LENGTH);
    char *subString= (char *)malloc(MAX_LENGTH);
    printf("Enter main string: ");
    takeInput(mainString);
    printf("Enter substring: ");
    takeInput(subString);
    bool isSubStringIsPresent=checkForSubstring(mainString,subString);
    printIsSubStringIsPresent(isSubStringIsPresent);
    return 0;
}