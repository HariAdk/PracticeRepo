#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 1001

void takeInput(char **string) {
    **string = '\0';
    scanf("%[^\n]", *string);
    getchar(); 
}

int largestSubString(char *string)
{
   int *characterMemory=(int *)calloc(26,sizeof(int));
   int maxNonRepetingSubstringLength=0;
   int right=0;
   int left=0;
   while(string[right]!='\0')
   {
      if(characterMemory[string[right]-'a']==0)
      {
        characterMemory[string[right]-'a']=1;
        right++;
      }
      else{
         if(maxNonRepetingSubstringLength<right-left)
         {
            maxNonRepetingSubstringLength=right-left;
         }
        while(string[left]!=string[right])
        {
            characterMemory[string[left]-'a']=0;
            left++;
        }
        characterMemory[string[left]-'a']=0;
        left++;
      }
   }
        if(maxNonRepetingSubstringLength<right-left)
         {
            maxNonRepetingSubstringLength=right-left;
         }
   return maxNonRepetingSubstringLength;
   
}
int main()
{
    char *string = (char *)malloc(MAX_LENGTH);
    printf("Enter the sentence: ");
    takeInput(&string);
    printf("%s\n",string);
    int maxNonRepetingSubstringLength= largestSubString(string);
    printf("Maximum non repeting string is: %d",maxNonRepetingSubstringLength);
    return 0;
}