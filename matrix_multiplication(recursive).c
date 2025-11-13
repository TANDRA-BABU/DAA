#include <stdio.h>
#include <stdlib.h>

int *input_matrix(int rows, int cols);
void display_matrix(int *matrix, int rows, int cols);
void multiply_recursive(int *a, int *b, int *c, int rowsA, int colsA, int colsB, int i, int j, int k, int sum);

int main()
{
    int rowsA, colsA, rowsB, colsB;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB)
    {
        printf("Matrix multiplication not possible (colsA must equal rowsB).\n");
        return 0;
    }

    printf("Enter elements of Matrix A:\n");
    int *A = input_matrix(rowsA, colsA);

    printf("Enter elements of Matrix B:\n");
    int *B = input_matrix(rowsB, colsB);

    int *C = (int *)calloc(rowsA * colsB, sizeof(int));

    multiply_recursive(A, B, C, rowsA, colsA, colsB, 0, 0, 0, 0);

    printf("Resultant Matrix (A × B):\n");
    display_matrix(C, rowsA, colsB);

    free(A);
    free(B);
    free(C);

    return 0;
}

int *input_matrix(int rows, int cols)
{
    int *matrix = (int *)malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows * cols; i++)
    {
        scanf("%d", &matrix[i]);
    }
    return matrix;
}

void display_matrix(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

// Recursive matrix multiplication
void multiply_recursive(int *a, int *b, int *c, int rowsA, int colsA, int colsB, int i, int j, int k, int sum)
{
    if (i >= rowsA) 
        return; // Done with all rows

    if (j >= colsB) 
    {
        multiply_recursive(a, b, c, rowsA, colsA, colsB, i + 1, 0, 0, 0);
        return;
    }

    if (k < colsA) 
    {
        sum += a[i * colsA + k] * b[k * colsB + j];
        multiply_recursive(a, b, c, rowsA, colsA, colsB, i, j, k + 1, sum);
    }
    else 
    {
        c[i * colsB + j] = sum;
        multiply_recursive(a, b, c, rowsA, colsA, colsB, i, j + 1, 0, 0);
    }
}
