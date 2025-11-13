#include <stdio.h>
#include <stdlib.h>

int *input_matrix(int rows, int cols);
void display_matrix(int *matrix, int rows, int cols);
void subtract_matrices_recursive(int *a, int *b, int *c, int index, int total);

int main()
{
    int rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of Matrix A:\n");
    int *A = input_matrix(rows, cols);

    printf("Enter elements of Matrix B:\n");
    int *B = input_matrix(rows, cols);

    int *C = (int *)malloc(rows * cols * sizeof(int));

    subtract_matrices_recursive(A, B, C, 0, rows * cols);

    printf("Resultant Matrix (A - B):\n");
    display_matrix(C, rows, cols);

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

void subtract_matrices_recursive(int *a, int *b, int *c, int index, int total)
{
    if (index == total)
    {
        return;
    }
    c[index] = a[index] - b[index];

    subtract_matrices_recursive(a, b, c, index + 1, total);
}
