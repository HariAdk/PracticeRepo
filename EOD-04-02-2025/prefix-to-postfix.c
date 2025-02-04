#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char** stack;
int top=-1;

int isOperator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

int isFull()
{
    return top>=99;
}

int isEmpty()
{
    return top==-1;
}
void stackPush(char* string)
{
    if(isFull())
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    top++;
    stack[top]=string;
}
void stackPop()
{
    if(isEmpty())
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    top--;
}
char* peek()
{
    if(!isEmpty())
    return stack[top];
    return NULL;
}

int stringLength(char* string)
{
    int count=0;
    while(*string!='\0')
    {
      count++;
      string++;
    }
    return count;
}
void swap(char* ch1, char* ch2)
{
    char temp=*ch1;
    *ch1=*ch2;
    *ch2=temp;
}
void reverse(char* prefix)
{
    int start=0;
    int end=stringLength(prefix)-1;
    while(start<end)
    {
        swap(&prefix[start++],&prefix[end--]);
    }
}

char* convertToPostfix(char* prefix)
{
    reverse(prefix);
    while(*prefix!='\0')
    {
        if(isOperator(*prefix))
        {
            char*st1=peek();
            if(st1==NULL)
            {
                printf("Invalid Input!\n");
                exit(1);
            }
            stackPop();
            char*st2=peek();
            if(st2==NULL)
            {
                printf("Invalid Input!\n");
                exit(1);
            }
            stackPop();
            int length=stringLength(st1)+stringLength(st2)+2;
            char* result=(char*)malloc(sizeof(char)*length);
            char*openPara=(char*)malloc(sizeof(char)*(length+3));
            char*closePara=(char*)malloc(sizeof(char)*2);
            openPara[0]='(';
            openPara[1]='\0';
            closePara[0]=')';
            closePara[1]='\0';
            result[0]='\0';
            strcat(result,st1);
            strncat(result,prefix,1);
            strcat(result,st2);
            strcat(openPara,result);
            strcat(openPara,closePara);
            stackPush(openPara);
        }
        else{
            char* ch=(char*)malloc(sizeof(char)*2);
            ch[0]=*prefix;
            ch[1]='\0';
            stackPush(ch);
        }
        prefix++;
    }
    char* infix=peek();
    return infix;  
}

int main()
{
    char* prefix=(char*)malloc(sizeof(char)*100);
    stack=(char**)malloc(sizeof(char*)*100);
    scanf("%[^\n]",prefix);
    char* infix=convertToPostfix(prefix);
    printf("%s",infix);
    free(stack);
    return 0;
}