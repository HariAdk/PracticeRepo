
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 1001


void takeInput(char **string) {
    **string = '\0';
    scanf("%[^\n]", *string);
    getchar(); 
}
void largestAndSmallestWord(char *sentence, int *minWordLength, int *maxWordLength, char **smallestStartWord, char **largestStartWord) {
    int counter = 0;
    int wordLength = 0;
    char *startWord =&sentence[counter];
    while (sentence[counter] != '\0') {
        if ((sentence[counter] >= 'a' && sentence[counter] <= 'z') || (sentence[counter] >= 'A' && sentence[counter] <= 'Z')) {
            if (wordLength == 0) {
                startWord = &sentence[counter];
            }
            wordLength++;
        } else {
            if (wordLength > 0) {
                if (*minWordLength > wordLength) {
                    *minWordLength = wordLength;
                    *smallestStartWord = startWord;
                }
                if (*maxWordLength < wordLength) {
                    *maxWordLength = wordLength;
                    *largestStartWord = startWord;
                }
            }
            wordLength = 0;
        }
        counter++;
    }

    if (wordLength > 0) {
        if (*minWordLength > wordLength) {
            *minWordLength = wordLength;
            *smallestStartWord = startWord;
        }
        if (*maxWordLength < wordLength) {
            *maxWordLength = wordLength;
            *largestStartWord = startWord;
        }
    }
}


void printSmallestAndLargestWord(char *smallestStartWord, char *largestStartWord) {
    printf("Smallest word is: ");
    while (*smallestStartWord != '\0' && (((*smallestStartWord >= 'a' && *smallestStartWord <= 'z') || (*smallestStartWord >= 'A' && *smallestStartWord <= 'Z')))) {
        printf("%c", *smallestStartWord);
        smallestStartWord++;
    }
    printf("\n");

    printf("Largest word is: ");
    while (*largestStartWord != '\0' && (((*largestStartWord >= 'a' && *largestStartWord <= 'z') || (*largestStartWord >= 'A' && *largestStartWord <= 'Z')))) {
        printf("%c", *largestStartWord);
        largestStartWord++;
    }
    printf("\n");
}

int main() {
    char *sentence = (char *)malloc(MAX_LENGTH);
    printf("Enter the sentence: ");
    takeInput(&sentence);

    int minWordLength = 1e9;  
    int maxWordLength = -(1e9);  
    char *smallestStartWord = (char*)malloc(100*sizeof(char));
    char *largestStartWord = (char*)malloc(100*sizeof(char));
    largestAndSmallestWord(sentence, &minWordLength, &maxWordLength, &smallestStartWord, &largestStartWord);
    printSmallestAndLargestWord(smallestStartWord, largestStartWord);
    free(sentence);
    return 0;
}
