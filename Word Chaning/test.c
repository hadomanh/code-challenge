#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLENGTH 100

void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

bool sort(char **arr, int size)
{
    // Anchor case
    if (size == 1)
        return true;

    for (int i = 0; i < size; i++)
    {
        // Try new state
        // Move current element to the end of array
        swap(&arr[i], &arr[size - 1]);

        // In case remaining elements have been sorted
        // And current element can be placed at the end
        // Return true
        if (sort(arr, size - 1) && arr[size - 2][strlen(arr[size - 2]) - 1] == arr[size - 1][0])
        {
            return true;
        }

        // Back to initial state
        swap(&arr[i], &arr[size - 1]);
    }

    return false;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./test <input file name>\n");
        return 1;
    }
    
    FILE *fptr = fopen(argv[1], "r");

    if (fptr == NULL)
    {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }

    int wordCount;
    fscanf(fptr, "%d", &wordCount);

    char **word = (char **)malloc(wordCount * sizeof(char *));

    for (int i = 0; i < wordCount; i++)
    {
        word[i] = (char *)malloc(MAXLENGTH * sizeof(char));
        fscanf(fptr, "%s%*c", word[i]);
    }

    if (!sort(word, wordCount))
    {
        printf("No solution!\n");
    }
    else
    {
        for (int i = 0; i < wordCount; i++)
        {
            printf("%s ", word[i]);
        }
        printf("\n");
    }

    fclose(fptr);
    return 0;
}