#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void maximumOccurance(char *string)
{
    int *arr=(int *)calloc(26,sizeof(int));
    int count=0;
    while(string[count]!='\0')
    {
        if((string[count]<'a' && string[count]>'z') ||(string[count]<'A' && string[count]>'Z'))
        {   count++;
            continue;
        }
        char ch=lowerChar(string[count]);
        arr[ch-'a']++;
        count++;
    }

    int maxi=-1;
    for(int index=0;index<26;index++)
    {
        if(arr[index]>maxi)
        {
            maxi=arr[index];
        }
       
    }

    for(int index=0;index<26;index++)
    {
        if(arr[index]==maxi)
        {
            printf("%c ",'a'+index);
        }
    }

}

int main()
{
    char *string;
    scanf("%[^\n]%*c",string);
    maximumOccurance(string);
    return 0;
}