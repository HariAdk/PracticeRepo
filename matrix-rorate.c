#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>



void inputMatrix(int row, int cols,int matrix[][cols])
{
    for(int rowIndex = 0; rowIndex < row ; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            scanf("%d",&matrix[rowIndex][colIndex]);
        }
        
    }
}

void rotateMatrix(int row, int cols, int matrix[][cols])
{
    int startRow=0;
    int rowEnd=row-1;
    int startCols=0;
    int colsEnd=cols-1;
    int counter=0;
    int temp=0;
    while(startRow<rowEnd && startCols<colsEnd)
    {
        temp=matrix[startRow][colsEnd];
        for(int index=colsEnd;index>startCols;index--)
        {
            matrix[startRow][index]=matrix[startRow][index-1];
        }
        for(int index=startRow;index<rowEnd;index++)
        {
            matrix[index][startCols]=matrix[index+1][startCols];
        }
         for(int index=startCols;index<colsEnd;index++)
        {
            matrix[rowEnd][index]=matrix[rowEnd][index+1];
        }
         for(int index=rowEnd;index>startRow;index--)
        {
            matrix[index][colsEnd]=matrix[index-1][colsEnd];
        }
        matrix[startRow+1][colsEnd]=temp;
        startCols++;
        startRow++;
        rowEnd--;
        colsEnd--;
    }
}

void printMatrix(int row,int cols, int matrix[][cols])
{
     for(int rowIndex = 0; rowIndex < row ; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            printf("%d ",matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

int main()
{
    int row,cols;
    printf("Enter Row:");
    scanf("%d",&row);
    printf("Enter Column:");
    scanf("%d",&cols);
    int matrix[row][cols];
    inputMatrix(row,cols,matrix);
    rotateMatrix(row,cols,matrix);
    printf("\nAfter Rotation\n");
    printMatrix(row,cols,matrix);
    return 0;
}
