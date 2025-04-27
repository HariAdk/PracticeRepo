#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 20

bool checkValidationOfIpv4String( char* ipv4String)
{
    int counter1=0;
    while(ipv4String[counter1]!='\0')
    {
        char* insideIpv4String=&ipv4String[counter1];
        int octetsLength=0;
        int counter=0;
        int octetValue=0;
        while(insideIpv4String[counter]!='\0'&& insideIpv4String[counter]!='.')
        {
           octetValue=octetValue*10+(insideIpv4String[counter]-'0');
           octetsLength++;
           counter++;
           counter1++;
        }
        if(octetsLength>3)
        {
            return false;
        }
        if(octetValue%10==0 && octetValue!=0)
        {
            return false;
        }
        if(octetsLength==3 && (octetValue<101 || octetValue>255))
        {
           return false;
        }
        if(octetsLength==2 && octetValue<11 )
        {
           return false;  
        }
        counter1++;
    }
    return true;
}

int main()
{
    char ipv4String[MAX_LEN];
    scanf("%[^\n]",ipv4String);
    getchar();
    bool isValid=checkValidationOfIpv4String(ipv4String);
    if(isValid)
    {
        printf("Valid");
    }
    else{
        printf("Invalid");
    }
    return 0;

}