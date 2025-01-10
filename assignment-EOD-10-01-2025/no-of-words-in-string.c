#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1001

int totalNoOfWords(char *sentence)
{
    int noOfWords=0;
    int counter=0;
    while((sentence[counter]!='\0')&&(sentence[counter]<'a' || sentence[counter]>'z') && (sentence[counter]<'A' || sentence[counter]>'Z'))
    {
           counter++;
    }
    if(sentence[counter]=='\0')
    {
        return noOfWords;
    }
    noOfWords=1;
    while(sentence[counter]!='\0')
    {
        if((sentence[counter]<'a' || sentence[counter]>'z') && (sentence[counter]<'A' || sentence[counter]>'Z'))
        {
            if((sentence[counter+1]>='a' && sentence[counter+1]<='z') || (sentence[counter+1]>='A' && sentence[counter+1]<='Z'))
            {
                noOfWords++;
            }
        }
        counter++;
       
    }
    return noOfWords;
}

int main()
{
    char *sentence=(char *)malloc(MAX_LENGTH);
    printf("Enter the sentence:\n");
    scanf("%[^\n]%*c",sentence);
    int noOfWords=totalNoOfWords(sentence);
    printf("No of words are: %d",noOfWords);
    return 0;
}