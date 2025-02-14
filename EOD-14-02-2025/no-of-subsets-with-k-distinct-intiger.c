#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

int findMaxArray(int* array,int distinct,int size)
{
    int countArray[40002]={0};
    int left=0;
    int right=0;
    int currentDistinct=0;
    int ans=0;
    while(right<size)
    {
      if(countArray[array[right]+20001]==0)
      {
        currentDistinct++;
      }
      countArray[array[right]+20001]++;
      right++;
      while(currentDistinct>distinct)
      {
        countArray[array[left]+20001]--;
        if(countArray[array[left]+20001]==0)
        {
          currentDistinct--;
          left++;
          break;
        }
        left++;
      }
      int temp=left;
      int increment=0;
      while(temp<right && distinct==currentDistinct)
      {
        ans++;
        countArray[array[temp]+20001]--;
        if(countArray[array[temp]+20001]==0)
        {
         increment=1;
         break;
        }
        temp++;
      }
      while(increment && temp>=left)
      {
        countArray[array[temp]+20001]++;
        temp--;
      }
    }
  return ans;
}
int main()
{
    int* array=(int*)malloc(sizeof(int)*MAX_LENGTH);
    int possibleDistinctInt;
    int size=0;
    while(1)
    {
      scanf("%d",&array[size++]);
      char ch=getchar();
      if(ch=='\n' || ch==EOF) break;
    }
    scanf("%d",&possibleDistinctInt);
    printf("%d",findMaxArray(array,possibleDistinctInt,size));
    return 0;
}
