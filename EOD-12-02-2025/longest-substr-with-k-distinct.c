#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

int findMaxArray(char* string,int distinct)
{
    int max=0;
    int countArray[26]={0};
    int left=0;
    int right=0;
    int currentDistinct=0;
    while(right<strlen(string))
    {
      if(countArray[string[right]-'a']==0)
      {
        currentDistinct++;
      }
      countArray[string[right]-'a']++;
      right++;
      while(currentDistinct>distinct)
      {
        countArray[string[left]-'a']--;
        if(countArray[string[left]-'a']==0)
        {
           currentDistinct--;
           left++;
           break;
        }
        left++;
      }
      if(right-left >= max)
      {
        max=right-left;
      }
    }
return max;
}
int main()
{
    char* string=(char*)malloc(sizeof(char)*MAX_LENGTH);
    int possibleDistinctChar;
    scanf("%s",string);
    getchar();
    scanf("%d",&possibleDistinctChar);
    printf("%d",findMaxArray(string,possibleDistinctChar));
    return 0;
}