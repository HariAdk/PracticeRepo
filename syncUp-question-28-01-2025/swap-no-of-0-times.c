#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fillString2(char* string1 , char* string2)
{
    int count=0;
    while(*string1!='\0')
    {
        if(*string1==',' || *string1=='[' || *string1==']')
        {
            string1++;
            continue;
        }
        else{
              string2[count]=*string1;
              string1++;
              count++;
        }
    }
}
int findMaxNumberOfOnes(char* string2, int noOfOnes,int index)
{
   if(string2[index]=='\0')
   {
    return 0;
   }
    char* tempString=&string2[index];
    int  temp=noOfOnes;
    int arr[noOfOnes];
    int index1=0;
    int maxi=0;
    for(int i=0;tempString[i]!='\0';i++)
    {
        if(tempString[i]=='0' && temp>0)
        {
            tempString[i]='1';
            temp--;
            arr[index1++]=i;
        }
    }
    int count=0;
    while(string2[count]!='\0')
    {
        temp=0;
        while(string2[count]!='\0' && string2[count]=='1')
        {
            temp++;
            count++;
        }
        if(temp>maxi)
        {
            maxi=temp;
        }
        if(string2[count]!='\0')
        count++;
    }
    for(int i=0;i<index1;i++)
    {
        tempString[arr[i]]='0';
    }
    temp=findMaxNumberOfOnes(string2,noOfOnes,index+1);
    if(temp>maxi)
    {
        return temp;
    }
    return maxi;
}

int main()
{
    char string[100];
    char string2[100]="";
    int noOfOnes=0;
    scanf("%[^\n]",string);
    fillString2(string,string2);
    scanf("%d",&noOfOnes);
    int maxi=findMaxNumberOfOnes(string2,noOfOnes,0);
    printf("%d",maxi);
    return 0;
}