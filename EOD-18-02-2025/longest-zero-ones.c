#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void takeInput(int *array, int *size)
{
    while (*size < MAX_LENGTH)
    {
        scanf("%d", &array[(*size)++]);
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }
}

int findLongestLength(int *array, int size)
{
    int maxLength = 0;
    int prefixSum = 0;
    int *hashMap = (int *)malloc(sizeof(int *) * ((2 * MAX_LENGTH) + 1));
    for (int i = 0; i < (2 * MAX_LENGTH + 1); i++)
    {
        hashMap[i] = -1;
    }

    hashMap[MAX_LENGTH] = 0;
    for (int i = 0; i < size; i++)
    {
        prefixSum += array[i] == 0 ? -1 : 1;
        int hashIndex = prefixSum + MAX_LENGTH;

        if (hashMap[hashIndex] != -1)
        {
            int length = i - hashMap[hashIndex] + 1;
            if (length > maxLength)
                maxLength = length;
        }
        else
        {
            hashMap[hashIndex] = i + 1;
        }
    }
    return maxLength;
}

int main()
{
    int *array = (int *)malloc(sizeof(int) * MAX_LENGTH);
    int size = 0;
    takeInput(array, &size);
    printf("%d", findLongestLength(array, size));
    return 0;
}
