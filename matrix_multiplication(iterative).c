#include <stdio.h>
#include <stdlib.h>

int *input_matrix(int rows, int cols);
void display_matrix(int *matrix, int rows, int cols);
int *multiply_matrices(int *a, int *b, int rowsA, int colsA, int colsB);

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

    int *C = multiply_matrices(A, B, rowsA, colsA, colsB);

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

int *multiply_matrices(int *a, int *b, int rowsA, int colsA, int colsB)
{
    int *result = (int *)calloc(rowsA * colsB, sizeof(int));

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                result[i * colsB + j] += a[i * colsA + k] * b[k * colsB + j];
            }
        }
    }

    return result;
}
