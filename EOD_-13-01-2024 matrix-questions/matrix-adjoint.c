#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void allocateMatrix(int ***matrix, int numCols, int numRows)
{
    *matrix = (int **)calloc(numRows, sizeof(int *));
    for (int row = 0; row < numRows; row++)
    {
        (*matrix)[row] = (int *)calloc(numCols, sizeof(int));
    }
}

void inputMatrix(int **matrix, int numRows, int numCols)
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            scanf("%d", &matrix[row][col]);
        }
    }
}

void printMatrix(int **matrix, int numRows, int numCols)
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void findTranspose(int **matrix, int numRows, int numCols)
{
    int **transposeMatrix = (int **)calloc(numCols, sizeof(int *));
    for (int col = 0; col < numCols; col++)
    {
        transposeMatrix[col] = (int *)calloc(numRows, sizeof(int));
        for (int row = 0; row < numRows; row++)
        {
            transposeMatrix[col][row] = matrix[row][col];
        }
    }

    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            matrix[row][col] = transposeMatrix[row][col];
        }
    }

    printf("Transpose is:\n");
    printMatrix(matrix, numRows, numCols);


    for (int col = 0; col < numCols; col++)
    {
        free(transposeMatrix[col]);
    }
    free(transposeMatrix);
}

void findAdjoint(int **matrix, int numRows, int numCols)
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            bool isPositiveSign = ((row + col) % 2 == 0);
            if (!isPositiveSign)
            {
                matrix[row][col] = -(matrix[row][col]);
            }
        }
    }

    findTranspose(matrix, numRows, numCols);
}

int main()
{
    int **matrix;
    int numRows, numCols;
    printf("Enter number of rows: ");
    scanf("%d", &numRows);
    printf("Enter number of columns: ");
    scanf("%d", &numCols);

    allocateMatrix(&matrix, numCols, numRows);
    inputMatrix(matrix, numRows, numCols);
    findAdjoint(matrix, numRows, numCols);

    for (int row = 0; row < numRows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);

    return 0;
}
