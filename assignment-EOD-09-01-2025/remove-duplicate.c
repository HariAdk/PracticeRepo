#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char lowerChar(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch;
    }
    else{
        int temp=ch-'A';
        return ('a'+temp);
    }
}

void removeDuplicate(char *string)
{
    char *ch=string;
    int count=0;
    int *arr=(int *)calloc(26,sizeof(int));
    while(string[count]!='\0')
    {
        char temp=lowerChar(string[count]);
       
            if(arr[temp-'a']==0)
            {
                ch[0]=temp;
                arr[temp-'a']++;
                ch++;
            }
          count++;

    }
    ch[0]='\0';
}
int main()
{
    char *string;
    scanf("%[^\n]%*c",string);
    removeDuplicate(string);
    printf("%s",string);
}