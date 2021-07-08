/*-------------------------------------------------------------------------------------------
Matrix Calclulator

A simple calculator for matrices written in C that was part of
my "Fundamentals of Programming" course at the University of Zanjan, Fall 2012

Meysam Parvizi (http://meysamparvizi.ir)
--------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void myAddition();
void mySubtraction();
void myMultiplication();
void myTransposed();
void myMinor();
float myDeterminant();
int myReverse();
void getMatrix();
void printMatrix();

int main(void)
{ 
    int choice;
    int m, n, p, q;
    float a[10][10], b[10][10], c[10][10];
    
    printf("\n*********************************************\n"); 
    printf("\n[1] ADDITION OF TWO MATRICES ( A + B )");
    printf("\n[2] SUBTRACTION OF TWO MATRICES ( A - B )");  
    printf("\n[3] MULTIPLICATION OF TWO MATRICES ( A x B )");
    printf("\n[4] TRANSPOSED OF A MATRIX ( A' )"); 
    printf("\n[5] DETERMINANT OF A MATRIX ( det(A) )");
    printf("\n[6] REVERSE OF A MATRIX");
    printf("\n[0] EXIT"); 
    printf("\n\n*********************************************"); 
    printf("\n\nENTER YOUR CHOICE: ");
     
    scanf("%d",&choice);
    
    switch ( choice )
    {
           case 0:
                return 0;
           case 1:
                printf("\nEnter rows of matrices A and B: ");
                scanf("%d", &m);
                printf("Enter columns of matrices A and B: ");
                scanf("%d", &n);
                printf("Enter elements of matrix A:\n");
                getMatrix(a, m, n);
                printf("Enter elements of matrix B:\n");
                getMatrix(b, m, n);
                printf("\n==== Matrix Addition ====\n");
                myAddition(a, b, c, m, n);
                printMatrix(c, m, n);

                break;
           case 2:
                printf("\nEnter rows of matrices A and B: ");
                scanf("%d", &m);
                printf("Enter columns of matrices A and B: ");
                scanf("%d", &n);
                printf("Enter elements of matrix A:\n");
                getMatrix(a, m, n);
                printf("Enter elements of matrix B:\n");
                getMatrix(b, m, n);
                printf("\n==== Matrix Subtraction ====\n");
                mySubtraction(a, b, c, m, n);
                printMatrix(c, m, n);
                break;
           case 3:
                printf("\nEnter rows of matrix A: ");
                scanf("%d", &m);
                printf("Enter columns of matrix A: ");
                scanf("%d", &n);
                printf("\nEnter rows of matrix B: ");
                scanf("%d", &p);
                printf("Enter columns of matrix B: ");
                scanf("%d", &q);
                if (n != p)
                {
                      printf("Matrices cannot be multiplied!");
                }
                else /* if n==p */
                {
                    printf("Matrices can be multiplied.\n");
                    printf("Resultant matrix is %dx%d\n", m, q);
                    printf("Enter elements of matrix A:\n");
                    getMatrix(a, m, n);
                    printf("Enter elements of matrix B:\n");
                    getMatrix(b, p, q);
                    printf("\n==== Matrix Multiplication ====\n\n");
                    myMultiplication(a, b, c, m, q, n);
                    printMatrix(c, m, q);
                }
                break;
           case 4:
                printf("\nEnter rows of matrix A: ");
                scanf("%d", &m);
                printf("Enter columns of matrix A: ");
                scanf("%d", &n);
                printf("Enter elements of matrix A:\n");
                getMatrix(a, m, n);
                printf("\n==== Matrix Transposed ====\n\n");
                myTransposed(a, c, m, n);
                printMatrix(c, n, m);
                break;
           case 5:
                printf("\nEnter dimension of matrix A: ");
                scanf("%d", &n);
                printf("Enter elements of matrix A:\n");
                getMatrix(a, n, n);
                printf("\n==== Matrix Determinant ====\n\n");
                printf("det(A) = %.3f", myDeterminant(a, n) );
                break;
           case 6:
                printf("\nEnter dimension of matrix A: ");
                scanf("%d", &n);
                printf("Enter elements of matrix A:\n");
                getMatrix(a, n, n);
                if ( myReverse(a, c, n) )
                {
                   printf("\n==== Matrix Reverse ====\n\n");
                   printMatrix(c, n, n);
                }
                else
                {
                    printf("Matrix cannot be reversed!\n");
                }
                break;
    }

    return 0;
}

void myAddition(float A[][10], float B[][10], float C[][10], int row, int col)
{
     int i, j;
     
     for (i = 0; i < row ; i++)
     {
         for (j = 0; j < col ; j++)
         {
             C[i][j] = A[i][j] + B[i][j];
         }
     }
}

void mySubtraction(float A[][10], float B[][10], float C[][10], int row, int col)
{
     int i, j;
     
     for (i = 0; i < row ; i++)
     {
         for (j = 0; j < col ; j++)
         {
             C[i][j] = A[i][j] - B[i][j];
         }
     }
}


void myMultiplication(float A[][10], float B[][10], float C[][10], int M, int Q, int N )
{
     int i, j, k;
     float sum;

     for (i = 0; i < M ; i++)
     {
         for (j = 0; j < Q ; j++)
         {
             sum = 0;
             for (k = 0; k < N ; k++)
             {
                 sum = sum + A[i][k] * B[k][j];
             }
             C[i][j] = sum;
         }
     }
}

void myTransposed(float A[][10], float C[][10], int row, int col) 
{ 
    int i, j; 
    
    for (i = 0 ; i < row ; i++ )
    { 
        for (j = 0 ; j < col  ;j++) 
        {
            C[j][i] = A[i][j];
        }
    }
}

void myMinor(float A[][10], float C[][10], int N, int ti, int tj) 
{ 
    int i, j;
    int r = 0, s = 0;

    for (i = 0 ; i < N ; i++ )
    {
        if (i != ti)
        {
           r++;
           s = 0;
           for (j = 0 ; j < N  ;j++) 
           {
               if (j != tj)
               {
                  s++;
                  C[r - 1][s - 1] = A[i][j];
               }
           }
        }
    }
}

float myDeterminant(float A[][10], int N) 
{ 
    int i, j;
    float det = 0;
    float C[10][10];
    
    if ( N == 1 )
    {
         return A[0][0];
    }
    else
    {
        i = 0;
        for (j = 0 ; j < N  ;j++) 
        {
            myMinor(A, C, N, i, j);
            det = det + pow( -1 , i+j ) * A[i][j] * myDeterminant(C, N - 1);
        }
    }
    return det;
}

int myReverse(float A[][10], float C[][10], int N)
{ 
    int i, j;
    float AStar[10][10];
    float det;
    
    det = myDeterminant(A, N);
    
    if (det == 0)
    {
       return 0;
    }
    else
    {
        if ( N == 1)
        {
            C[0][0] = 1/det;
        }
        else
        {
            for (i = 0 ; i < N ; i++ )
            {
                for (j = 0 ; j < N  ;j++) 
                {
                    myMinor(A, C, N, i, j);
                    AStar[j][i] = pow( -1 , i+j ) * myDeterminant(C, N - 1);
                }
            }
        
            for (i = 0 ; i < N ; i++ )
            {
                for (j = 0 ; j < N  ;j++) 
                {
                    C[i][j] = AStar[i][j]/det;
                }
            }
            return 1;
        }
    }
}

void getMatrix(float A[][10], int row, int col) 
{ 
    int i, j; 
    
    for (i = 0 ; i < row ; i++ )
    { 
        for (j = 0 ; j < col  ;j++) 
        {
            scanf("%f", &A[i][j]);
        }
    }
}

void printMatrix(float A[][10], int row, int col) 
{ 
    int i, j; 
    
    for (i = 0 ; i < row ; i++ )
    { 
        for (j = 0 ; j < col  ;j++) 
        {
            printf("%6.3f ", A[i][j]);
        }
        printf("\n");
    }
}
