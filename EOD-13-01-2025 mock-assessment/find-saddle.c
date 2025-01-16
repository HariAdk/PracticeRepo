#include <stdio.h>

#define MAX_SIZE 25

void takeInput(int rows,int cols,int matrix[rows][cols])
{
    for(int rowIndex=0;rowIndex<rows;rowIndex++)
    {
        for(int columnIndex=0;columnIndex<cols;columnIndex++)
        {
           scanf("%d",&matrix[rowIndex][columnIndex]);
        }
    }
}
void findSaddlePoint(int rows,int cols,int matrix[rows][cols])
{
    int minimumArr[rows];

    for(int rowIndex=0;rowIndex<rows;rowIndex++)
    {
        int min=1e9;
        for(int columnIndex=0;columnIndex<cols;columnIndex++)
        {
            if(min>=matrix[rowIndex][columnIndex])
            {
              min=matrix[rowIndex][columnIndex];
            }
        }
        minimumArr[rowIndex]=min;
    }
    int maximumArray[cols];
    for(int columnIndex=0;columnIndex<cols;columnIndex++)
    {
        int max=-1e9;
        for(int rowIndex=0;rowIndex<rows;rowIndex++)
        {
            if(max<=matrix[rowIndex][columnIndex])
            {
               max=matrix[rowIndex][columnIndex];
            }
            
        }
        maximumArray[columnIndex]=max;
       
        
    }
   

   for(int minimumArrIndex=0;minimumArrIndex<cols;minimumArrIndex++)
   {
    for(int maximumArrayIndex=0;maximumArrayIndex<cols;maximumArrayIndex++)
    {
        if(minimumArr[minimumArrIndex]==maximumArray[maximumArrayIndex])
        {
            printf("%d",minimumArr[minimumArrIndex]);
            return;
        }
    }
   }
   printf("No saddle point");

}

int main()
{
    int rows,cols;
    scanf("%d",&rows);
    cols=rows;
    int matrix[rows][cols];
    takeInput(rows,cols,matrix);
    findSaddlePoint(rows,cols,matrix);

}

