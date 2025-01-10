#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stringLength(char *string) {
    int count = 0;
    while (string[count] != '\0') {
        count++;
    }
    return count;
}

void swapChar(char *ch1, char *ch2) {
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void findAllPermutations(char *string, char **ans, int index, int *counter) {
    int len = stringLength(string);
    if (index == len) {
        ans[*counter] = (char *)malloc(len + 1);  
        strcpy(ans[*counter], string);  
        (*counter)++;
        return;
    }

    for (int i = index; i < len; i++) {
        swapChar(string + index, string + i);  
        findAllPermutations(string, ans, index + 1, counter);  
        swapChar(string + index, string + i);  
    }
}

void printPermutations(char **ans, int size) {
    printf("\"%s\"", ans[0]); 
    for (int index = 1; index < size; index++) {
        printf(",\"%s\"", ans[index]);  
    }
}

int main() {
    char string[100];
    scanf("%[^\n]%*c", string);  

    int len = stringLength(string);
    int maxLen = 1;
    for (int i = 1; i <= len; i++) {
        maxLen *= i;
    }
    int counter = 0;
    char **ans = (char **)malloc(maxLen * sizeof(char *));  
    findAllPermutations(string, ans, 0, &counter);
    printPermutations(ans, counter);
    for (int i = 0; i < counter; i++) {
        free(ans[i]);
    }
    free(ans);
    return 0;
}
