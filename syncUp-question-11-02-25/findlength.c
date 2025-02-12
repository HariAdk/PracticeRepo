#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findLength(char** array, int count)
{
    int maxLength=0;
    for(int i=0;i<count-1;i++)
    {
        int countArray[26]={0};
        for(int k=0;k<strlen(array[i]);k++)
        {
            countArray[array[i][k]-'a']++;
        }
        for(int j=i+1;j<count;j++)
        {
            int matched=0;
            for(int p=0;p<strlen(array[j]);p++)
            {
                 if(countArray[array[j][p]-'a']!=0)
                 {
                    matched=1;
                    break;
                 }
            }
            if(!matched)
            {
                int length=strlen(array[i])*strlen(array[j]);
                if(length>maxLength)
                {
                    maxLength=length;
                }
            }
        }
    }
    return maxLength;
}

int main()
{
    char **array=(char**)malloc(sizeof(char*)*100);
    int count=0;
    while(1)
    {
        array[count]=(char*)malloc(sizeof(char)*100);
        scanf("%s",array[count++]);
        char ch=getchar();
        if(ch=='\n' || ch==EOF) break;
    }
    int length=findLength(array,count);
    printf("%d",length);
    return 0;
}