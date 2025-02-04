#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int* array;
    int capacity;
    int top;
}Stack;

Stack* createStack(int size)
{
    Stack* newStack=(Stack*)malloc(sizeof(Stack));
    if(newStack==NULL)
    {
        printf("Memory cannot allocated!\n");
        return NULL;
    }
    newStack->array=(int*)malloc(sizeof(int)*size);
    newStack->capacity=size;
    newStack->top=-1;
    return newStack;
}

int isFull(Stack* stack)
{
    return (stack->top==stack->capacity-1);
}

int isEmpty(Stack* stack)
{
    return stack->top==-1;
}

void push(Stack* stack,int value)
{
    if(isFull(stack))
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack->array[++stack->top]=value;
}

void pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow!\n");
        return;
    }
    stack->top--;
}

int peek(Stack* stack)
{
  return stack->array[stack->top];
}

void findMinimum(int* array, Stack* minStack,int arraySize)
{
    Stack* minStackIndex=createStack(arraySize);
    push(minStackIndex,0);
    push(minStack,-1);
    for(int index=1;index<arraySize;index++)
    {
        if(array[index]>array[peek(minStackIndex)])
        {
            push(minStack,array[peek(minStackIndex)]);
        }
        else{
            push(minStackIndex,index);
            push(minStack,-1);
        }
    }
}

void printStack(Stack* stack)
{
    if(isEmpty(stack))
    {
        return;
    }
    int temp=peek(stack);
    pop(stack);
    printStack(stack);
    printf("%d ",temp);
}

int main()
{
    int size;
    scanf("%d",&size);
    int *array=(int*)malloc(sizeof(int)*size);
    for(int index=0;index<size;index++)
    {
        scanf("%d",&array[index]);
    }
    Stack* minStack=createStack(size);
    findMinimum(array,minStack,size);
    printStack(minStack);
    return 0;
}