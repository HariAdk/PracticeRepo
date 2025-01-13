#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25

void defineMatrix(int ***matrix,int rows,int cols)
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

int **twoMatrixMultiplication(int **matrix1,int **matrix2,int rows,int cols1,int cols2)
{
    printf("Multiplication of matrix1 and matrix2\n");
    int **resultMatrix=(int **)calloc(rows,sizeof(int *));
    for(int rowIndex=0;rowIndex<rows;rowIndex++)
    {
         resultMatrix[rowIndex]=(int *)calloc(cols2,sizeof(int));
         for(int colIndex=0;colIndex<cols1;colIndex++)
         {
            resultMatrix[rowIndex][colIndex]=0;
            for(int jIndex=0;jIndex<cols2;jIndex++)
             resultMatrix[rowIndex][jIndex]+=matrix1[rowIndex][colIndex]*matrix2[colIndex][jIndex];
         }
    }
    return resultMatrix;

}

void solveAccToQues()
{
    int **matrix1;
    int **matrix2;
    int rows,cols,cols2;
    printf("Enter size of firstMatrix row:");
    scanf("%d",&rows);
    printf("Enter size of column:");
    scanf("%d",&cols);
    printf("Enter size of secondMatrix column:");
    scanf("%d",&cols2);
    defineMatrix(&matrix1,rows,cols);
    defineMatrix(&matrix2,cols,cols2);
    printf("Enter input for first matrix\n");
    inputMatrix(matrix1,rows,cols);
    printf("Enter input for second matrix\n");
    inputMatrix(matrix2,cols,cols2);
    printf("first Matrix\n");
    printMatrix(matrix1,rows,cols);
    printf("second Matrix\n");
    printMatrix(matrix2,cols,cols2);
    int **resultMatrix=twoMatrixMultiplication(matrix1,matrix2,rows,cols,cols2);
    printf("result Matrix\n");
    printMatrix(resultMatrix,rows,cols2);
    free(matrix1);
    free(matrix2);
    free(resultMatrix);
}

int main()
{ 
    solveAccToQues();
    return 0;
}