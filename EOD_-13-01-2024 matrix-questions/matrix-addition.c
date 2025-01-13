#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25

void defineMatrix(int ***matrix,int cols,int rows)
{
    *matrix=(int **)calloc(rows,sizeof(int*));
    for(int rowIndex=0;rowIndex<rows;rowIndex++)
    {
        (*matrix)[rowIndex]=(int *)calloc(cols,sizeof(int));
    }
}

void inputMatrix(int **matrix,int rows, int cols)
{
    for(int rowIndex=0;rowIndex<rows;rowIndex++)
    {
         for(int colIndex=0;colIndex<cols;colIndex++)
    {
        scanf("%d",&matrix[rowIndex][colIndex]);
    }
    }
}

void printMatrix(int **matrix,int rows,int cols)
{
     for(int rowIndex=0;rowIndex<rows;rowIndex++)
    {
         for(int colIndex=0;colIndex<cols;colIndex++)
    {
        printf("%d ",matrix[rowIndex][colIndex]);
    }
       printf("\n");
    }

}

int **twoMatrixAdditon(int **matrix1,int **matrix2,int rows,int cols)
{
    printf("Addition of matrix1 and matrix2\n");
    int **resultMatrix=(int **)calloc(rows,sizeof(int *));
    for(int rowIndex=0;rowIndex<rows;rowIndex++)
    {
         resultMatrix[rowIndex]=(int *)calloc(cols,sizeof(int));
         for(int colIndex=0;colIndex<cols;colIndex++)
         {
            resultMatrix[rowIndex][colIndex]=matrix1[rowIndex][colIndex]+matrix2[rowIndex][colIndex];
         }
    }
    return resultMatrix;

}


int main()
{
    int **matrix1;
    int **matrix2;
    int rows,cols;
    printf("Enter size of row:");
    scanf("%d",&rows);
    printf("Enter size of column:");
    scanf("%d",&cols);
    defineMatrix(&matrix1,cols,rows);
    defineMatrix(&matrix2,cols,rows);
    printf("Enter input for first matrix\n");
    inputMatrix(matrix1,rows,cols);
    printf("Enter input for second matrix\n");
    inputMatrix(matrix2,rows,cols);
    int **resultMatrix=twoMatrixAdditon(matrix1,matrix2,rows,cols);
    printMatrix(resultMatrix,rows,cols);
    return 0;
}